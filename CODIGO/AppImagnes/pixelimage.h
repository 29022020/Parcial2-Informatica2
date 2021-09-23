#ifndef PIXELIMAGE_H
#define PIXELIMAGE_H
#include <iostream>
#include <QImage>
#include "RW_files.h"
#include <array>
#include <vector>
#include <QImage>


using namespace std;

class PixelImage
{
public:

    PixelImage();

    PixelImage(int HeightPixel_Init_, int WidthPixel_Init_, int HeightPixel_End_, int WidthPixel_End_, QImage &MyImage);



    vector<int> getMyColor() const;

private:

    int HeightPixel_Init;

    int WidthPixel_Init;

    int HeightPixel_End;

    int WidthPixel_End;

    bool operator ==(const vector<int> &elemet1)const;

    vector <vector<int>> MyAreaOfPixeles;

    vector<int> MyColor;

    bool comparateVector(vector<int> elemnt1, vector<int> elemnt2);

    void getMyColor();

};

#endif // PIXELIMAGE_H
