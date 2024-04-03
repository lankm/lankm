#include <iostream>
#include "unit.hpp"

int main(int argc, char **argv) {
    Unitless u = 1.0;

    std::cout << u+0.1 << std::endl;
    return 0;
}