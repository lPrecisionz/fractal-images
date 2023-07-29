#pragma once

#include <string>
#include <cstdint>
#include <memory>

namespace fractal{

class Bitmap{
private:
    int m_width {0};
    int m_height {0};
    std::unique_ptr<uint8_t []> m_pPixels {nullptr};

public:
    Bitmap(int width, int height);
    void setPixel(int x, int y);
    bool write(std::string fileName);
};

} //namespace fractal