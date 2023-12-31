#include "Mandelbrot.h"
#include "Bitmap.h"
#include <iostream>

int main(int, char**){
    using namespace fractal;
    const int WIDTH = 800;
    const int HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    double min = 99999;
    double max = -99999;

    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            double xFractal = (x - WIDTH/2 - 150) * (2.0/HEIGHT);
            double yFractal = (y - HEIGHT/2) * (2.0/HEIGHT); //set both to height proportions to avoid disproportion

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            uint8_t color = (uint8_t)(256 * (static_cast<double>(iterations)/fractal::Mandelbrot::MAX_ITERATIONS));


            bitmap.setPixel(x, y, color, 0, color);
            if(xFractal < min) min = xFractal;
            if(xFractal > max) max = xFractal;
        }
    }

    std::cout << "min: " << min << "; max: " << max << std::endl;

    bitmap.write("fractal_image.bmp");
    std::cout << "finished" << std::endl;

    return 0;
}