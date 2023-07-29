#pragma once

#include <cstdint>

namespace fractal{

#pragma pack(push, 2)

struct BitmapFile{
    char header[2]{'B' , 'M'};
    uint32_t fileSize;
    uint32_t reserved { 0 };
    uint32_t dataOffset;
};

#pragma pack(pop)

} //namespace fractal