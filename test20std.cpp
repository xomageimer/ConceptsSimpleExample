#include <algorithm>
#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include <type_traits>


template <typename T>
concept WithCopyConstructor = std::is_copy_constructible_v<T>;

template<WithCopyConstructor T>
void printik(T a){
    std::cerr << a << std::endl;
}

struct NonCopyConstruct{
    int a;
    NonCopyConstruct(int tmp) : a(tmp) {};
    NonCopyConstruct(const NonCopyConstruct&) = delete;
};

struct CopyConstruct{
    int a;
    CopyConstruct(int tmp) : a(tmp) {};
    CopyConstruct(const CopyConstruct&) = default;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, T a){
    os << a.a << std::endl;
    return os;
}

template<int r>
concept Even = r % 2 == 0;

template <int num>
requires (Even<num>)
void printer()
{
    std::cerr << num << std::endl;
}

int main()
{
  //  printer<4>(); // work
  //  printer<3>(); // doesnt work
    NonCopyConstruct ncc(5);
    CopyConstruct cc(33);

    printik(cc); // work
  //  printik(ncc); // doesnt work
}