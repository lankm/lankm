#include <iostream>
#include "unit.hpp"

int main(int argc, char **argv) {
    Unitless u = 1.0;
    Time t = 5;
    Frequency f = 2;

    Time temp = u*t;

    std::cout << temp << std::endl;
    return 0;
}