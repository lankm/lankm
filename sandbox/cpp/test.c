#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdint.h>
#include <math.h>

// Function to print a number in binary format
void printBinary(unsigned long long num, int bits) {
    if (num == 0) {
        printf("0\n");
        return;
    }

    // Calculate the number of bits needed to represent the number
    int numBits = bits;

    // Loop through each bit and print it
    for (int i = numBits - 1; i >= 0; i--) {
        // Use bitwise AND to check if the bit is set
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    clock_t start;
    clock_t end;
    const unsigned int LOOPS = (unsigned int)((uint64_t)1<<1)-1;

    int32_t u = 1<<30;
    printBinary(u,32);
    start = clock();
    for(unsigned int i=0; i<LOOPS; i++) {
        u = (int32_t)(( ((int64_t)u)*((int64_t)u))>>30);
    }
    end = clock();
    printf("final fixed: %d\n",u);
    printf("clocks: %d\n",end-start);

    float f = 1.0;
    printf("%d\n",u);
    start = clock();
    for(unsigned int i=0; i<LOOPS; i++) {
        f=f*f;
    }
    end = clock();
    printf("final float: %f\n",f);
    printf("clocks: %d\n",end-start);

    return 0;
}
