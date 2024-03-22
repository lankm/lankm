#include <iostream>
#include <limits>
#include <time.h>

#include "number.cpp"
#include "physics.cpp"

int main(int argc, char **argv) {
    Translation t1 = Translation(); // worldframe
    Translation t2 = Translation();
    t2.accelerate({2147483647,0,0}, 10); // set to max velocity

    POSITION p = t2.get_rel_pos(t1, 9); // wait until largest time
    for(int i=0; i<3; i++) {
        printf("%lld ", p[i]);
    }
    printf("\n");

    return 0;
}
