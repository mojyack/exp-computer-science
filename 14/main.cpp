#include <cmath>
#include <fstream>
#include <numbers>

#include "../misc.hpp"

auto main(const int argc, const char* argv[]) -> int {
    if(argc != 2) {
        println("invalid argumnts");
        return 1;
    }

    auto f = std::ofstream(argv[1]);

    for(auto i = 0; i < 100; i += 1) {
        const auto a = 2.0 * i * std::numbers::pi / 100.0;
        const auto b = std::sin(a);
        const auto s = build_string(a, ' ', b, '\n');
        f.write(s.data(), s.size());
    }

    return 0;
}
