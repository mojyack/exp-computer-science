#include "../misc.hpp"

auto main() -> int {
    const auto n = read_stdin<int>("n = ");
    
    auto sum = 1;
    for(auto i = 1; i <= n; i += 1) {
        sum = sum * i;
    }

    println(n, "! = ", sum);

    return 0;
}
