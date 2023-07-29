#pragma once

#include <cstdint>

namespace fractal{

#pragma pack(push, 2)

struct BitmapInfo{
    uint32_t headerSize {40};
    uint32_t width;
    uint32_t height;
    uint16_t planes {1};
    uint16_t bitsPerPixel {24};
    uint32_t compression {0};
    uint32_t dataSize {0};
    uint32_t horizontalResolution {2400};
    uint32_t verticalResolution {2400};
    uint32_t colors; 
    uint32_t importantColors {0};
};

#pragma pack(pop)

} //namespace fractal