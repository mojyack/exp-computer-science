#include <array>
#include <cmath>

#include "../misc.hpp"

using Planet = std::array<std::array<double, 2>, 3>; // [0] position, [1] velocity, [2] acceleration

constexpr auto timestep   = double(0.01);
constexpr auto total_time = 500;

auto kepler(Planet& planet, const double t) -> int {
    const auto r = std::sqrt(std::pow(planet[0][0], 2) + std::pow(planet[0][1], 2));
    planet[2][0] = -planet[0][0] / std::pow(r, 3);
    planet[2][1] = -planet[0][1] / std::pow(r, 3);
    return 2;
}

using DiffFunc = decltype(kepler);

auto euler(Planet& planet, const double t, DiffFunc diff) -> void {
    const auto n = diff(planet, t);
    for(auto i = 0; i < n; i += 1) {
        planet[i][0] += timestep * planet[i + 1][0];
        planet[i][1] += timestep * planet[i + 1][1];
    }
}

auto meuler(Planet& planet, const double t, DiffFunc diff) -> void {
    auto k1 = planet;
    auto k2 = planet;
    auto n  = diff(planet, t);
    for(auto i = 0; i < n; i += 1) {
        k1[i][0] = timestep * k1[i + 1][0];
        k1[i][1] = timestep * k1[i + 1][1];
        k2[i][0] += k1[i][0];
        k2[i][1] += k1[i][1];
    }
    n = diff(k2, t + timestep);
    for(auto i = 0; i < n; i += 1) {
        k2[i][0] = timestep * k2[i + 1][0];
        k2[i][1] = timestep * k2[i + 1][1];

        planet[i][0] += (k1[i][0] + k2[i][0]) / 2.0;
        planet[i][1] += (k1[i][1] + k2[i][1]) / 2.0;
    }
}

auto runge(Planet& planet, const double t, DiffFunc diff) -> void {
    auto k1 = planet;
    auto k2 = planet;
    auto k3 = planet;
    auto k4 = planet;
    auto n  = diff(planet, t);
    for(auto i = 0; i < n; i += 1) {
        k1[i][0] = timestep * k1[i + 1][0];
        k1[i][1] = timestep * k1[i + 1][1];
        k2[i][0] += k1[i][0] / 2.0;
        k2[i][1] += k1[i][1] / 2.0;
    }
    n = diff(k2, t + timestep / 2.0);
    for(auto i = 0; i < n; i += 1) {
        k2[i][0] = timestep * k2[i + 1][0];
        k2[i][1] = timestep * k2[i + 1][1];
        k3[i][0] += k2[i][0] / 2.0;
        k3[i][1] += k2[i][1] / 2.0;
    }
    n = diff(k3, t + timestep / 2.0);
    for(auto i = 0; i < n; i += 1) {
        k3[i][0] = timestep * k3[i + 1][0];
        k3[i][1] = timestep * k3[i + 1][1];
        k4[i][0] += k3[i][0];
        k4[i][1] += k3[i][1];
    }
    n = diff(k4, t + timestep);
    for(auto i = 0; i < n; i += 1) {
        k4[i][0] = timestep * k4[i + 1][0];
        k4[i][1] = timestep * k4[i + 1][1];

        planet[i][0] += (k1[i][0] + 2.0 * k2[i][0] + 2.0 * k3[i][0] + k4[i][0]) / 6.0;
        planet[i][1] += (k1[i][1] + 2.0 * k2[i][1] + 2.0 * k3[i][1] + k4[i][1]) / 6.0;
    }
}

auto main(const int argc, const char* const argv[]) -> int {
    if(argc != 4) {
        println("Usage: ", argc >= 1 ? argv[0] : "24", " method{euler|meuler|runge} initial_x_velocity initial_y_velocity");
        return 1;
    }

    auto init = Planet{1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    try {
        init[1][0] = std::stod(argv[2]);
        init[1][1] = std::stod(argv[3]);
    } catch(const std::invalid_argument&) {
        println("invalid arguments");
        return 1;
    }

    if(std::strcmp(argv[1], "euler") == 0) {
        auto planet = init;
        for(auto i = 0; i < total_time / timestep; i += 1) {
            euler(planet, i * timestep, kepler);
            println(planet[0][0], " ", planet[0][1]);
        }
    } else if(std::strcmp(argv[1], "meuler") == 0) {
        auto planet = init;
        for(auto i = 0; i < total_time / timestep; i += 1) {
            meuler(planet, i * timestep, kepler);
            println(planet[0][0], " ", planet[0][1]);
        }
    } else if(std::strcmp(argv[1], "runge") == 0) {
        auto planet = init;
        for(auto i = 0; i < total_time / timestep; i += 1) {
            runge(planet, i * timestep, kepler);
            println(planet[0][0], " ", planet[0][1]);
        }
    } else {
        println("unknown method");
        return 1;
    }

    return 0;
}
