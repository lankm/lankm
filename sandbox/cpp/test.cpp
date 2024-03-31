#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstring>
#include <iterator>
#include <iomanip>
#include <random>
#include <limits>

#include <math.h>
#define BIT_ALIGN 30
/* represents a unit quaternion */
class Quaternion {
    private:
        /* simple array values of a quaternion */
        int32_t q[4];

        /* raw value constructor */
        Quaternion(int32_t a, int32_t b, int32_t c, int32_t d) {
            this->q[0] = a;
            this->q[1] = b;
            this->q[2] = c;
            this->q[3] = d;
        }
    public:
        /* default of <1,0,0,0> */
        Quaternion() {
            this->q[0] = 1<<BIT_ALIGN;
            this->q[1] = 0;
            this->q[2] = 0;
            this->q[3] = 0;
        }

        /* user-friendly conversion */
        Quaternion(double a, double b, double c, double d) {
            double norm = sqrt(a*a+b*b+c*c+d*d);
            double base = (1<<BIT_ALIGN)/norm;

            this->q[0] = a*base;
            this->q[1] = b*base;
            this->q[2] = c*base;
            this->q[3] = d*base;
        }
        

        /* right multiplication of quaterions. no renormalization */
        Quaternion operator*(const Quaternion& other) const {
            // multiplication based on quaternion rules
            const int32_t ROUND = 1<<(BIT_ALIGN-1);
            int32_t a = (  q[0]*(int64_t)other.q[0] - q[1]*(int64_t)other.q[1] 
                         - q[2]*(int64_t)other.q[2] - q[3]*(int64_t)other.q[3]
                         + ROUND                                              )>>BIT_ALIGN;

            int32_t b = (  q[0]*(int64_t)other.q[1] + q[1]*(int64_t)other.q[0]
                         + q[2]*(int64_t)other.q[3] - q[3]*(int64_t)other.q[2]
                         + ROUND                                              )>>BIT_ALIGN;

            int32_t c = (  q[0]*(int64_t)other.q[2] - q[1]*(int64_t)other.q[3]
                         + q[2]*(int64_t)other.q[0] + q[3]*(int64_t)other.q[1]
                         + ROUND                                              )>>BIT_ALIGN;

            int32_t d = (  q[0]*(int64_t)other.q[3] + q[1]*(int64_t)other.q[2]
                         - q[2]*(int64_t)other.q[1] + q[3]*(int64_t)other.q[0]
                         + ROUND                                              )>>BIT_ALIGN;

            return Quaternion(a,b,c,d);
        }

        /* right multiplication of quaterions. with renormalization */
        Quaternion& operator*=(const Quaternion& other) {
            // multiplication based on quaternion rules
            const int32_t ROUND = 1<<(BIT_ALIGN-1);
            int32_t a = (  q[0]*(int64_t)other.q[0] - q[1]*(int64_t)other.q[1] 
                         - q[2]*(int64_t)other.q[2] - q[3]*(int64_t)other.q[3]
                         + ROUND                                              )>>BIT_ALIGN;

            int32_t b = (  q[0]*(int64_t)other.q[1] + q[1]*(int64_t)other.q[0]
                         + q[2]*(int64_t)other.q[3] - q[3]*(int64_t)other.q[2]
                         + ROUND                                              )>>BIT_ALIGN;

            int32_t c = (  q[0]*(int64_t)other.q[2] - q[1]*(int64_t)other.q[3]
                         + q[2]*(int64_t)other.q[0] + q[3]*(int64_t)other.q[1]
                         + ROUND                                              )>>BIT_ALIGN;

            int32_t d = (  q[0]*(int64_t)other.q[3] + q[1]*(int64_t)other.q[2]
                         - q[2]*(int64_t)other.q[1] + q[3]*(int64_t)other.q[0]
                         + ROUND                                              )>>BIT_ALIGN;

            // calculate quick inverse norm
            const int64_t ONE = 1LL<<(BIT_ALIGN<<1);
            int64_t dot = q[0]*(int64_t)q[0] + q[1]*(int64_t)q[1] + q[2]*(int64_t)q[2] + q[3]*(int64_t)q[3];
            int32_t invnorm = (((ONE - dot) >> 1) + ONE + ROUND)>>BIT_ALIGN; // based on derivitive of x^(1/2) at x=1

            // apply
            q[0] = (a*(int64_t)invnorm + ROUND)>>BIT_ALIGN;
            q[1] = (b*(int64_t)invnorm + ROUND)>>BIT_ALIGN;
            q[2] = (c*(int64_t)invnorm + ROUND)>>BIT_ALIGN;
            q[3] = (d*(int64_t)invnorm + ROUND)>>BIT_ALIGN;

            return *this;   
        }

        /* returns the inverse of a Quaternion */
        Quaternion inv() {
            return Quaternion(q[0], -q[1], -q[2], -q[3]);
        }
        double norm() {
            return sqrt(q[0]*(int64_t)q[0] + q[1]*(int64_t)q[1] + q[2]*(int64_t)q[2] + q[3]*(int64_t)q[3])/(1<<BIT_ALIGN);
        }

        /* displays the raw values of the instance variables */
        friend std::ostream& operator<<(std::ostream& os, const Quaternion& obj) {
            os << '<';
            for(int i = 0; i < 4; i++) {
                os << (double)obj.q[i]/(1<<BIT_ALIGN) << ' ';
            }
            os << "\b>";

            return os;
        }
};
class fQuaternion {
    private:
        /* simple array values of a quaternion */
        double q[4];
    public:
        /* default of <1,0,0,0> */
        fQuaternion() {
            this->q[0] = 1.0;
            this->q[1] = 0.0;
            this->q[2] = 0.0;
            this->q[3] = 0.0;
        }

        /* user-friendly conversion */
        fQuaternion(double a, double b, double c, double d) {
            double dot = a*a + b*b + c*c + d*d;
            double norm = sqrt(dot);

            this->q[0] = a/norm;
            this->q[1] = b/norm;
            this->q[2] = c/norm;
            this->q[3] = d/norm;
        }
        
        /* right multiplication of quaterions. no renormalization */
        fQuaternion operator*(const fQuaternion& other) const {
            // multiplication based on quaternion rules
            double a = q[0]*other.q[0] - q[1]*other.q[1] - q[2]*other.q[2] - q[3]*other.q[3];
            double b = q[0]*other.q[1] + q[1]*other.q[0] + q[2]*other.q[3] - q[3]*other.q[2];
            double c = q[0]*other.q[2] - q[1]*other.q[3] + q[2]*other.q[0] + q[3]*other.q[1];
            double d = q[0]*other.q[3] + q[1]*other.q[2] - q[2]*other.q[1] + q[3]*other.q[0];

            return fQuaternion(a,b,c,d);
        }

        /* right multiplication of quaterions. with renormalization */
        fQuaternion& operator*=(const fQuaternion& other) {
            // multiplication based on quaternion rules
            double a = q[0]*other.q[0] - q[1]*other.q[1] - q[2]*other.q[2] - q[3]*other.q[3];
            double b = q[0]*other.q[1] + q[1]*other.q[0] + q[2]*other.q[3] - q[3]*other.q[2];
            double c = q[0]*other.q[2] - q[1]*other.q[3] + q[2]*other.q[0] + q[3]*other.q[1];
            double d = q[0]*other.q[3] + q[1]*other.q[2] - q[2]*other.q[1] + q[3]*other.q[0];

            // calculate inverse norm
            double dot = q[0]*q[0] + q[1]*q[1] + q[2]*q[2] + q[3]*q[3];
            double invnorm = ((1.0-dot)/2)+1;
            // double invnorm = 1/sqrt(dot);

            // apply
            q[0] = a*invnorm;
            q[1] = b*invnorm;
            q[2] = c*invnorm;
            q[3] = d*invnorm;

            return *this;   
        }

        /* returns the inverse of a Quaternion */
        fQuaternion inv() {
            return fQuaternion(q[0], -q[1], -q[2], -q[3]);
        }
        double norm() {
            return sqrt(q[0]*q[0] + q[1]*q[1] + q[2]*q[2] + q[3]*q[3]);
        }

        /* displays the raw values of the instance variables */
        friend std::ostream& operator<<(std::ostream& os, const fQuaternion& obj) {
            os << '<';
            for(int i = 0; i < 4; i++) {
                os << obj.q[i] << ' ';
            }
            os << "\b>";

            return os;
        }
};

int main(int argc, char **argv) {
    Quaternion q1 = Quaternion(0.5,0.5,0.5,0.5);
    Quaternion q2 = Quaternion(0.0,1.0,0.0,0.0);

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
}

// 100,000,000 iterations
// classic: 3.7s
// qinvnorm: 2.6s (better precision)
// fixed32: 2.3s  (better memory/speed)
