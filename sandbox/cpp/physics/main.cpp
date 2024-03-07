#include <iostream>

#include "number.cpp"

int main(int argc, char **argv) {
    Unit u = Unit(-0.5);

    Angle a = Angle(3.1415926535897932384626);
    std::cout << a << std::endl;

    return 0;
}
