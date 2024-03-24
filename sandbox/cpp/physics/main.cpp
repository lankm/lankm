#include <iostream>
#include <limits>
#include <time.h>

#include "number.cpp"
#include "physics.cpp"

int main(int argc, char **argv) {
    Translation t1 = Translation(); // worldframe
    Translation t2 = Translation();

    t2.accelerate({2147483647,0,0}, 10); // set to max velocity
    t2.accelerate({-2147483647,0,0}, 10); // set to max velocity

    std::cout << t2.dist_to(t1, 10);

    return 0;
}
