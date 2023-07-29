#include "Bitmap.h"
#include <iostream>
int main(int, char**){
    const int WIDTH = 800;
    const int HEIGHT = 600;

    fractal::Bitmap bitmap(WIDTH, HEIGHT);

    double min = 99999;
    double max = -99999;

    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            double xFractal = (x - WIDTH/2) * (2.0/WIDTH);
            double yFractal = (y - HEIGHT/2) * (2.0/HEIGHT);

            if(xFractal < min) min = xFractal;
            if(xFractal > max) max = xFractal;

            if(yFractal < min) min = yFractal;
            if(yFractal > max) max = yFractal;
        }
    }

    std::cout << "min: " << min << "; max: " << max << std::endl;

    bitmap.write("test.bmp");
    std::cout << "finished" << std::endl;

    return 0;
}