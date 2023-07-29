#include "Bitmap.h"
int main(int, char**){
    fractal::Bitmap bitmap(800, 600);

    bitmap.write("test.bmp");
    return 0;
}
