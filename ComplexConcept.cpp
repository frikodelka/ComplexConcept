#include <iostream>
#include <string>

//x86-64 clang 14.0.0
//-std=c++20 -stdlib=libc++

template<typename T> concept ComplexConcept = requires(const T v)
{
    {v.hash()} -> std::convertible_to<long>;
    {v.toString()} -> std::same_as<std::string>;
}&& std::has_virtual_destructor<T>::value == false;

struct HashStruct
{
    int num { 0 };
    int hash() const { return num << 3; };
    std::string toString() const { return std::to_string(this->hash()); };
};

void PrintType(ComplexConcept auto &t)
{
    std::cout << t.toString() << std::endl;
}

int main()
{
    HashStruct num { 100 };
    PrintType(num);

    return 0;
}
