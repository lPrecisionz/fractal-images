#include <fstream>
#include "Bitmap.h"
#include "BitmapFile.h"
#include "BitmapInfo.h"

namespace fractal{

Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{}){
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){
    uint8_t *pPixel = m_pPixels.get();

    pPixel += (y * 3) * m_width + (x * 3);

    //reverse order since bitmap is little-endian
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}

bool Bitmap::write(std::string fileName){
    BitmapFile bitmapFile;
    BitmapInfo bitmapInfo;

    bitmapFile.fileSize = sizeof(BitmapFile) + sizeof(BitmapInfo) + m_width * m_height * 3;
    bitmapFile.dataOffset = sizeof(BitmapFile) + sizeof(BitmapInfo);

    bitmapInfo.width = m_width;
    bitmapInfo.height = m_height;

    std::fstream outputFile;
    outputFile.open(fileName, std::ios::out|std::ios::binary);

    if(!outputFile.is_open()){
        return false;
    }

    outputFile.write(reinterpret_cast<char *>(&bitmapFile), sizeof(bitmapFile));
    outputFile.write(reinterpret_cast<char *>(&bitmapInfo), sizeof(bitmapInfo));
    outputFile.write(reinterpret_cast<char *>(m_pPixels.get()), m_width * m_height * 3);

    outputFile.close();

    return true;
}

} //namespace fractal