#include <iomanip>
#include <numeric>
#include <vector>

#include "../misc.hpp"

namespace num {
constexpr auto unknown = std::numeric_limits<int>::min() + 0;
constexpr auto current = std::numeric_limits<int>::min() + 1;
} // namespace num

struct Matrix {
    size_t rows;
    size_t columns;

    std::vector<std::vector<int>> data;

    static auto from_stdin() -> Matrix {
        const auto r  = read_stdin<size_t>("rows? ");
        const auto c  = read_stdin<size_t>("columns? ");
        auto v = Matrix(r, c);
        v.init();
        for(auto& r : v.data) {
            for(auto& c : r) {
                c = num::current;
                v.print();
                c = read_stdin<int>();
            }
        }
        return v;
    }

    auto init() -> void {
        for(auto& r : data) {
            std::fill(r.begin(), r.end(), num::unknown);
        }
    }

    auto print() -> void {
        for(const auto& r : data) {
            for(const auto& c : r) {
                switch(c) {
                case num::unknown:
                    ::print("??");
                    break;
                case num::current:
                    ::print("<>");
                    break;
                default:
                    ::print(std::setw(2), c);
                    break;
                }
                ::print(' ');
            }
            println();
        }
    }

    auto operator[](const size_t index) -> std::vector<int>& {
        return data[index];
    }

    auto operator*(Matrix& o) -> Matrix {
        dynamic_assert(columns == o.rows, "matrix size mismatched");

        auto v = Matrix(rows, o.columns);
        for(auto r = size_t(0); r < rows; r += 1) {
            for(auto c = size_t(0); c < o.columns; c += 1) {
                v[r][c] = 0;
                for(auto i = size_t(0); i < columns; i += 1) {
                    v[r][c] += data[r][i] * o[i][c];
                }
            }
        }
        return v;
    }

    Matrix(const size_t rows, const size_t columns) : rows(rows), columns(columns), data(std::vector<std::vector<int>>(rows)) {
        for(auto& r : data) {
            r.resize(columns);
        }
    }
};

auto main() -> int {
    println("a:");
    auto a = Matrix::from_stdin();
    println("matrix a is:");
    a.print();

    println("b:");
    auto b = Matrix::from_stdin();
    println("matrix b is:");
    a.print();

    println("a * b = ");
    (a * b).print();
    return 0;
}
