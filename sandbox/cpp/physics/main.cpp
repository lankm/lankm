#include <iostream>
#include <limits>
#include <time.h>

#include "number.cpp"

int main(int argc, char **argv) {
    double d = 0.279;
    double b = d;
    float f = (float)d;
    float l = (float)d;
    Unit u = Unit(d);
    Unit n = Unit(d);

    const unsigned int LOOPS = 1;//std::numeric_limits<unsigned int>::max()>>4;
    std::cout << std::setprecision(20);

    clock_t start = clock();
    for(unsigned int i=0; i<LOOPS; i++) {
        u = u*n;
    }
    clock_t end = clock();
    std::cout << "Unit:   " << u << std::endl;
    std::cout << "Unit calc time:  " << end-start << std::endl;

    start = clock();
    for(unsigned int i=0; i<LOOPS; i++) {
        f = f*l;
    }
    end = clock();
    std::cout << "Float:  " << f << std::endl;
    std::cout << "Float calc time:  " << end-start << std::endl;

    for(unsigned int i=0; i<LOOPS; i++) {
        d = d*b;
    }
    std::cout << "Double: " << d << std::endl;

    return 0;
}
