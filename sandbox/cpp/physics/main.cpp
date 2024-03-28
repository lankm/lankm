#include <iostream>
#include <limits>
#include <time.h>
#include <random>

#include "number.cpp"
#include "physics.cpp"

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> dist(0.0f, 0.5f);
    
    for (int i = 0; i < 100; i++)
    {
        Quaternion q = Quaternion(dist(gen),dist(gen),dist(gen),dist(gen));

        std::cout << ' ' << q*q.inv() << std::endl;
    }

    return 0;
}
