#include <array>
#include <cmath>
#include <functional>
#include <numbers>

#include "../misc.hpp"

auto main(const int argc, const char* const argv[]) -> int {
    struct Function {
        const char*                   text;  // help message
        std::array<double, 2>         range; // range of x
        std::function<double(double)> func;
    };

    const static auto functions = std::array<Function, 6>{
        {{"e^(-x^2) [-3, +3]", {-3, 3}, [](const double x) -> double {
              return std::pow(std::numbers::e, -std::pow(x, 2));
          }},
         {"sin(x)/x [-3*pi, +3*pi]", {-3 * std::numbers::pi, 3 * std::numbers::pi}, [](const double x) -> double {
              return std::sin(x) / x;
          }},
         {"x*x(x-1) [0, 1]", {0, 1}, [](const double x) -> double {
              return x * (x - 1);
          }},
         {"1/(1+x^2) [-2 2]", {-2, 2}, [](const double x) -> double {
              return 1.0 / (1 + x * x);
          }},
         {"x^5 [-1, 1]", {-1, 1}, [](const double x) -> double {
              return x * x * x * x * x;
          }},
         {"sqrt(1-x^2) [-1 1]", {-1, 1}, [](const double x) -> double {
              return std::sqrt(1.0 - x * x);
          }}}};

    if(argc != 2) {
        println("Usage: ", argc >= 1 ? argv[0] : "18", " function_number{1~6}");
        for(auto i = 0; i < functions.size(); i += 1) {
            println(i, ": ", functions[i].text);
        }
        return 1;
    }

    auto n = int(); // function number
    try {
        n = std::stoi(argv[1]);
    } catch(const std::invalid_argument&) {
        println("invalid function number");
        return 1;
    }

    if(n >= functions.size()) {
        println("invalid function number");
        return 1;
    }

    constexpr auto step  = 100; // you can increase this for accuracy
    const auto&    f     = functions[n];
    const auto&    range = f.range;
    for(auto i = 0; i <= step; i += 1) {
        const auto x = range[0] + (range[1] - range[0]) / step * i;
        const auto y = f.func(x);
        println(x, " ", y);
    }
    return 0;
}
