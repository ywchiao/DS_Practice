#include <iostream>

int main(int argc, char** argv) {
    int odds[] = { 1, 3, 5, 7, 9 };
    int *p = odds;

    std::cout << "array odds[]'s address:"
        << std::endl;

    for (int i = 0; i < sizeof(odds) / sizeof(int); i++) {
        std::cout
            << "  &odds[" << i << "] = " << std::hex << &odds[i] << std::dec
            << "  (odds + " << i << ") = " << std::hex << p + i
            << std::endl;
    }
}

// odds_ptr.cpp
