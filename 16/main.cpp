#include "../misc.hpp"

class Record {
  private:
    int number;
    int japanese;
    int math;

  public:
    auto get_number() const -> int {
        return number;
    }
    auto get_average() const -> double {
        return (japanese + math) / 2.0;
    }

    Record(const int number, const int japanese, const int math) : number(number), japanese(japanese), math(math) {}
};

auto print_record(const Record& record) -> void {
    println("average of student ", record.get_number(), " is ", record.get_average());
}

auto main() -> int {
    const auto tanaka  = Record(1, 67, 90);
    const auto koizumi = Record(2, 80, 78);

    print_record(tanaka);
    print_record(koizumi);

    return 0;
}
