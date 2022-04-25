#include <fstream>

#include "../misc.hpp"

auto main(const int argc, const char* argv[]) -> int {
    if(argc != 3) {
        println("invalid argumnts");
        return 1;
    }

    auto src = std::fstream(argv[1]);
    auto dst = std::ofstream(argv[2]);

    auto line = std::string();
    auto sum  = double(0.0);
    while(std::getline(src, line)) {
        const auto sp = line.find(' ');
        dynamic_assert(sp != std::string::npos, "invalid line found");

        auto a = double();
        auto b = double();

        try {
            a = std::stod(line.substr(0, sp));
            b = std::stod(line.substr(sp + 1));
        } catch(const std::invalid_argument&) {
            panic("invalid line found");
        }
        sum += b;

        const auto str = build_string(a, ' ', sum, '\n');
        dst.write(str.data(), str.size());
    }
    return 0;
}
