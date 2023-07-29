#pragma once

namespace fractal{

class Mandelbrot{
private:
    static const int MAX_ITERATIONS = 1000;

public:
    int getIterations(double x, double y);
}

} //namespace fractal