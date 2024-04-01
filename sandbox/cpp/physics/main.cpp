#include <iostream>
#include <limits>
#include <time.h>
#include <random>
#include <chrono>

#include "number.cpp"
#include "physics.cpp"

int main(int argc, char **argv) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-0.5f, 0.5f);

    std::cout << std::setprecision(20);
    Quaternion q = Quaternion(dist(gen),dist(gen),dist(gen),dist(gen));

    // Start the clock
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; i++)
    {   
        q *= q;
    }
    // Stop the clock
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << q.norm() << std::endl;

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Print the duration in seconds
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
    
    
    return 0;
}
