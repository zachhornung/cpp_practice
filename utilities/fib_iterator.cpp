#include <iostream>

class FibIterator{
  private:
    size_t i {0};
    size_t a {0};
    size_t b {1};

  public:
    constexpr FibIterator() = default;

    constexpr FibIterator(size_t b_, size_t a_, size_t i_)
        : i{i_}, a{a_}, b{b_}
    {}

    size_t operator*() const { return b; }

    constexpr FibIterator& operator++() {
        const size_t old_b {b};
        b += a;
        a  = old_b;
        ++i;
        return *this;
    }

    bool operator!=(const FibIterator& o) const { return i != o.i; }
};

constexpr FibIterator fibit_at(size_t n){
    FibIterator it;
    for (size_t i {0}; i < n; ++i) {
        ++it;
    }
    return it;
};

class FibRange {
  private:
    FibIterator begin_it;
    size_t end_n;

  public:
    constexpr FibRange(size_t end_n_, size_t begin_n = 0)
        : begin_it(fibit_at(begin_n)), end_n(end_n_)
    {}

    FibIterator begin() const { return begin_it; }
    FibIterator end()   const { return {0, 0, end_n}; }
};

int main(){
  for (const size_t num : FibRange(10)) std::cout << num << std::endl;
};

// credits:
// https://blog.galowicz.de/2016/09/04/algorithms_in_iterators/