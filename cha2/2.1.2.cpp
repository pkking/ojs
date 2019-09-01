#include "iostream"

int main()
{
    unsigned u=10, u2=42;
    std::cout << u2 - u <<std::endl; // 32
    std::cout << u - u2 << std::endl; // 4294967295 - 32

    int i = 10, i2 = 42;
    std::cout << i2 - i <<std::endl; // 32
    std::cout << i - i2 << std::endl; // -32
    std::cout << i - u << std::endl; // 0
    std::cout << u - i << std::endl; // 0

    std::cout << u8"李超然" << std::endl;
    std::cout << "李超然" << std::endl;
    std::cout << L'李' << std::endl;
    std::cout << '李' << std::endl;
    std::cout << "hello" <<std::endl;
    std::cout << '\U+0065' << '\U+006C' << '\U+006C' << '\U+006F' <<std::endl;
    return 0;
}