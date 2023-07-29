#include "Bitmap.h"
#include <iostream>
int main(int, char**){
    const int WIDTH = 800;
    const int HEIGHT = 600;

    fractal::Bitmap bitmap(WIDTH, HEIGHT);
    
    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            bitmap.setPixel(x, y, 255, 0, 0);
        }
    }

    bitmap.write("test.bmp");
    std::cout << "finished" << std::endl;

    return 0;
}