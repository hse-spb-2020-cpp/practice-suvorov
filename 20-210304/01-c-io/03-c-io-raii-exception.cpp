#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <iostream>
#include <stdexcept>

#pragma pack(push, 1)
struct Point {
    std::int32_t x = 0;
    std::int32_t y = 0;
};
#pragma pack(pop)

struct FileEofException : std::logic_error {
    FileEofException() : std::logic_error("FileEofException") {}
};

struct FileReadException : std::logic_error {
    // Вот так не получится: "FileReadException: " + strerror()
    // Потому что тогда надо хитро выделять память.
    FileReadException() : std::logic_error(std::strerror(errno)) {}
};

enum class FileMode { READ_BINARY, WRITE_BINARY };
struct File {
private:
    FILE *f;

public:
    File(const std::string &file_name, FileMode mode)
        : f(std::fopen(file_name.c_str(), mode == FileMode::READ_BINARY ? "rb" : "wb")) {
        assert(f);
    }
    
    File(File &&other) : f(std::exchange(other.f, nullptr)) {
    }
    
    File &operator=(File &&other) {
        f = std::exchange(other.f, nullptr);
        return *this;
    }

    File(const File &) = delete;
    File &operator=(const File &) = delete;

    void write(const char *data, std::size_t length) /*const*/ {
        assert(f);
        std::size_t written = std::fwrite(data, 1, length, f);
        assert(written == length);
    }

    void read(char *data, std::size_t length) {
        assert(f);
        std::size_t read = std::fread(data, 1, length, f);
        if (read != length) {
            if (std::feof(f)) {
                throw FileEofException();
            } else if (std::ferror(f)) {
                throw FileReadException();
            } else {
                assert(false);
            }
        }
    }

    ~File() {
        std::fclose(f);
    }
};

int main() {
    {
        Point p[]{
            {10, 20}
        };
        File f("03.bin", FileMode::WRITE_BINARY);
        f.write(reinterpret_cast<const char*>(p), sizeof(p));
    }
    {
        Point p[2];
        try {
            File f("03.bin", FileMode::READ_BINARY);
            f.read(reinterpret_cast<char*>(p), sizeof(p));
            std::cout << "p[0] = " << p[0].x << " " << p[0].y << "\n";
            std::cout << "p[1] = " << p[1].x << " " << p[1].y << "\n";
        } catch (const std::exception &e) {
            std::cout << "error: " << e.what() << "\n";
        }
    }
}
