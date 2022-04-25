#include "../misc.hpp"

auto main() -> int {
    const auto a = read_stdin<double>("a =");
    const auto b = read_stdin<double>("b =");
    println("a + b = ", a + b);
    println("a - b = ", a - b);
    println("a * b = ", a * b);
    println("a / b = ", a / b);
    return 0;
}
