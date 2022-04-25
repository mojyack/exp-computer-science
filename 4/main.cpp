#include <array>

#include "../misc.hpp"

auto main() -> int {
    auto arr = std::array<int, 5>();
    for(auto& a : arr) {
        a = read_stdin<int>(build_string("arr[", &a - arr.data(), "] = "));
    }
    println("the pof2 of each value is:");
    for(const auto a : arr) {
        println(a * a);
    }
}
