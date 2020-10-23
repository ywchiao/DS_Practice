#include <iostream>

int main(int argc, char** argv) {
    int odds[] = { 1, 3, 5, 7, 9 };
    int *p = odds;

    std::cout << "access odds[] through index:"
        << std::endl;

    for (int i = 0; i < sizeof(odds) / sizeof(int); i++) {
        std::cout
            << "  odds[" << i << "] = " << odds[i]
            << std::endl;
    }
}

// array.cpp
