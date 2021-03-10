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

int main() {
    {
        Point p[]{
            {10, 20},
            {30, -50}
        };
        // std::ofstream f("01.bin", std::ios::binary);
        FILE *f = std::fopen("01.bin", "wb");
        assert(f);

        std::size_t written = std::fwrite(p, sizeof p[0], std::size(p), f);
        assert(written == std::size(p));

        std::fclose(f);
    }
    {
        Point p[2];
        // std::ifstream f("01.bin", std::ios::binary);
        FILE *f = std::fopen("01.bin", "rb");
        assert(f);

        std::size_t read = std::fread(p, sizeof p[0], std::size(p), f);
        assert(read == std::size(p));

        std::fclose(f);

        std::cout << "p[0] = " << p[0].x << " " << p[0].y << "\n";
        std::cout << "p[1] = " << p[1].x << " " << p[1].y << "\n";
    }
}
