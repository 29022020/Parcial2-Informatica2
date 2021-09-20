#ifndef PIXELIMAGE_H
#define PIXELIMAGE_H
#include <iostream>
#include <QImage>
#include "RW_files.h"
#include <array>
#include <vector>

using namespace std;

class PixelImage

{
public:

    PixelImage();

    PixelImage(int HeightPixel_, int WidthPixel_, int AreaHPixel_, int AreaWPixel_);

private:

    int HeightPixel;

    int WidthPixel;

    int AreaHPixel;

    int AreaWPixel;

};

#endif // PIXELIMAGE_H
