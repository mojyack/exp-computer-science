#include <cmath>
#include <iomanip>

#include "../misc.hpp"

auto main(const int argc, const char* const argv[]) -> int {
    if(argc != 2) {
        println("Usage: ", argc >= 1 ? argv[0] : "8", " size");
        return 1;
    }

    auto size = int(); // size of times table
    try {
        size = std::stoi(argv[1]);
    } catch(const std::invalid_argument&) {
        println("invalid size");
        return 1;
    }

    const auto w = std::log10(size * size) + 1; // longest number of digits

    for(auto n = 1; n <= size; n += 1) {     // rows
        for(auto m = 1; m <= size; m += 1) { // columns
            print(std::setw(w), n * m, " ");
        }
        println();
    }

    return 0;
}
