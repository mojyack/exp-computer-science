#include <algorithm>
#include <array>

#include "../misc.hpp"

auto main() -> int {
    auto arr = std::array<int, 10>();
    for(auto& a : arr) {
        a = read_stdin<int>(build_string("arr[", &a - arr.data(), "] = "));
    }

    std::sort(arr.begin(), arr.end());

    for(const auto a : arr) {
        print(a, " ");
    }
    println();
    return 0;
}
