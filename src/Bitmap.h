#pragma once

#include <string>
#include <cstdint>

namespace fractal{

class Bitmap{
private:
    int m_width {0};
    int m_height {0};

public:
    Bitmap(int width, int height);
    void setPixel(int x, int y);
    bool write(std::string fileName, uint8_t red, uint8_t green, uint8_t blue);
};

} //namespace fractal