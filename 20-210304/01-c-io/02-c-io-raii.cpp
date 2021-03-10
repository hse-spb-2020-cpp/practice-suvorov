#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include <iostream>

#pragma pack(push, 1)
struct Point {
    std::int32_t x = 0;
    std::int32_t y = 0;
};
#pragma pack(pop)

enum class FileMode { READ_BINARY, WRITE_BINARY };
struct File {
private:
    FILE *f;  // "Ресурс", которым мы управляем.

public:
    // Почему-то поддерживает только побайтовый ввод-вывод, а текстовый не умеет.
    File(const std::string &file_name, FileMode mode)
        : f(std::fopen(file_name.c_str(), mode == FileMode::READ_BINARY ? "rb" : "wb")) {
        assert(f);  // Но вообще хорошо бы кинуть исключение. Какое?
                    // Самостоятельно написать. А что возвращает what()?
                    // Что-то вроде stderror, но для этого надо сохранить код ошибки.
                    // Брать его из errno нельзя: это глобальная переменная, могла поменяться.
    }
    
    // Осторожно: появилось moved-from состояние! Это новый кусок инварианта!
    // Как минимум надо подумать в деструкторе.
    File(File &&other) : f(std::exchange(other.f, nullptr)) {
    }
    
    File &operator=(File &&other) {
        f = std::exchange(other.f, nullptr);
        return *this;
    }

    // Никакого fopencopy нет.
    File(const File &) = delete;
    File &operator=(const File &) = delete;

    // Или лучше std::span? Или std::vector? Или vector<Point>?
    // const-qualifier дописать можно, но идеологически он тут не по делу: состояние File-то меняется.
    void write(const char *data, std::size_t length) /*const*/ {
        assert(f);
        std::size_t written = std::fwrite(data, 1, length, f);
        assert(written == length);
    }

    // const-qualifier тоже лучше не стоит: меняется позиция в файле => состояние File меняется.
    void read(char *data, std::size_t length) {
        assert(f);
        std::size_t read = std::fread(data, 1, length, f);
        assert(read == length);
    }

    ~File() {
        // fclose либо можно вызывать от nullptr, либо UB.
        // Надо читать документацию и либо ставить if, либо нет.
        // Если документация молчит - надо ставить.
        std::fclose(f);
    }
};

int main() {
    {
        Point p[]{
            {10, 20},
            {30, -50}
        };
        // FILE *f = std::fopen("01.bin", "wb");
        // assert(f);
        File f("01.bin", FileMode::WRITE_BINARY);

        // std::size_t written = std::fwrite(p, sizeof p[0], std::size(p), f);
        // assert(written == std::size(p));
        f.write(reinterpret_cast<const char*>(p), sizeof(p));

        //std::fclose(f);
    }
    {
        Point p[2];
        {
            // FILE *f = std::fopen("01.bin", "rb");
            // assert(f);
            File f("01.bin", FileMode::READ_BINARY);

            //std::size_t read = std::fread(p, sizeof p[0], std::size(p), f);
            //assert(read == std::size(p));
            f.read(reinterpret_cast<char*>(p), sizeof(p));

            //std::fclose(f);
        }

        std::cout << "p[0] = " << p[0].x << " " << p[0].y << "\n";
        std::cout << "p[1] = " << p[1].x << " " << p[1].y << "\n";
    }
}
