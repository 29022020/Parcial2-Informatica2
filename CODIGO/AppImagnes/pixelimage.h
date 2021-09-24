#ifndef PIXELIMAGE_H
#define PIXELIMAGE_H
#include <iostream>
#include <QImage>
#include "RW_files.h"
#include <array>
#include <vector>
#include <QImage>
#include "countcolors.h"

///////////////////////////////
///
///CLASE QUE VA A TENER EL AREA QUE SE LE ASIGNE DE LA IMAGEN
/// PARA SABER CUAL ES EL COLOR EN TÉRMINOS DE VALORES RGB
/// QUE MÁS PREDOMINA EN LA AREA ASIGNADA DE LA IMAGEN
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

    vector <vector<int>> MyAreaOfPixeles; //Pixeles de mi area

    vector<int> MyColor;  //Pixel de representación

    bool comparateVector(vector<int> elemnt1, vector<int> elemnt2);//Comparar los valores de dos pixeles, para saber si son iguales

    void getMyColor();  //Para obtener mi pixel de representación

};

#endif // PIXELIMAGE_H
