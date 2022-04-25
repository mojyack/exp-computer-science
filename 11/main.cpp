#include <cmath>

#include "../misc.hpp"

auto main() -> int {
begin:
    println(std::abs(read_stdin<double>("value = ")));
    goto begin;
    return 0;
}
