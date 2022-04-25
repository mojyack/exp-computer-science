#include "../misc.hpp"

auto main() -> int {
    println("swap a and b");

    auto a = read_stdin<int>("a = ");
    auto b = read_stdin<int>("a = ");
    std::swap(a, b);

    println("a = ", a, ", b = ", b);
    
    return 0;
}
