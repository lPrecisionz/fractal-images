#include "Mandelbrot.h"
#include <complex>

namespace fractal{

int Mandelbrot::getIterations(double x, double y){
    std::complex<double> z = 0;
    std::complex<double> c(x, y);

    int iterations = 0;

    while(iterations < MAX_ITERATIONS){
        z = z * z + c; 

        if(norm(z) > 4.0){
            break;
        }

        iterations++;
    }

    return iterations;
}

} //namespace fractal