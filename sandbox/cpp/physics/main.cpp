#include <iostream>
#include <limits>
#include <time.h>

#include "number.cpp"
#include "physics.cpp"

int main(int argc, char **argv) {
    Translation t1 = Translation();
    Translation t2 = Translation();
    t2.accelerate({2,0,0});
    POSITION p = t1.get_rel_pos(t2, 20);
    for(int i=0; i<3; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    return 0;
}
