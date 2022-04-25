#include <cmath>

#include "../misc.hpp"

auto main() -> int {
    println("solve the expression ax^2 + bx + c = 0");

    const auto a = read_stdin<double>("a = ");
    const auto b = read_stdin<double>("b = ");
    const auto c = read_stdin<double>("c = ");

    if(const auto d = b * b - 4 * a * c; d > 0) {
        const auto x1 = (-b + std::sqrt(d)) / (2 * a);
        const auto x2 = (-b - std::sqrt(d)) / (2 * a);
        println("the answer is ", x1, " and ", x2);
    } else if(d == 0.0) {
        println("the double root is ", -b / (2 * a));
    } else {
        const auto r = -b / (2 * a);
        const auto i = std::sqrt(-d) / (2 * a);
        println("the complex root is ", r, " +- ", i, "i");
    }
    return 0;
}
