#include "../misc.hpp"

auto main() -> int {
    const auto a = read_stdin<int>("a =");
    const auto b = read_stdin<int>("b =");
    println("a + b = ", a + b);
    println("a - b = ", a - b);
    println("a * b = ", a * b);
    return 0;
}
