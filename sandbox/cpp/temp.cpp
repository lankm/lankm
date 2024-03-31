#include <math.h>
#include <iostream>

int main(int argc, char **argv) {
    double d = 1.0005;
    double invnorm = 1/sqrt(d);

    std::cout << invnorm << std::endl;
    return 0;
}