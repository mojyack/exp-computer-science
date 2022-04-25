#include "../misc.hpp"

auto main() -> int {
    const auto n = read_stdin<int>("n = ");

    auto sum = 0;
    for(auto i = 1; i <= n; i += 1) {
        sum += i;
    }
    println("1 + 2 + ... + n = ", sum);
    println("1/2n(n + 1) = ", n * (n + 1) / 2);

    return 0;
}
