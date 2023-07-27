#pragma once

#include <cstdint>

namespace fractal{

struct BitmapFile{
    char header[2]{'B' , 'M'};
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t dataOffset;
};

} //namespace fractal