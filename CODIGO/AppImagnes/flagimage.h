#ifndef FLAGIMAGE_H
#define FLAGIMAGE_H
#include <iostream>
#include <QImage>
#include "RW_files.h"
#include <array>
#include <vector>
#include "pixelimage.h"

using namespace std;


class FlagImage
{
public:

    FlagImage();

    FlagImage(QString ruta);

    QImage *Image;

    array <array <PixelImage, 16>, 16> MatrizLeds;

    int getHeight() const;

    int getWidth() const;

    void ShowMyPixeles();

private:

    int Height;

    int Width;

    void CreateTxt(QImage *im, string RedFile_, string BlueFile_, string GreenFile_);

    void CreatePixeles();

    void genTheTxtPixels();


};

#endif // FLAGIMAGE_H
