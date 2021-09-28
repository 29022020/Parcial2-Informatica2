///////////////////////////////////////////////////////////
///                CLASE PIXELIMAGE
///
/// CLASE QUE RECIBE UNA AREA DE LA IMAGEN.
///
/// FUNCION:
/// -SE LE ASIGNARÁ CIERTA AREA DE LA IMAGEN, Y LA INFORMACION
/// DE LA IMAGEN POR MEDIO DE UNA INSTANCIA DE LA CLASE QIMAGE,
/// PARA QUE ESTA POR MEDIO DE SUS METODOS Y ATRIBUTOS DETERIMINE
/// CUAL ES COLOR EN TERMINO DE SUS VALORES CORRESPONDINTES RGB
/// QUE REPRESENTA A ESA AREA (EL QUE MAS PREDOMINA).
///

#ifndef PIXELIMAGE_H
#define PIXELIMAGE_H
#include <iostream>
#include <QImage>
#include "RW_files.h"
#include <array>
#include <vector>
#include <QImage>
#include "countcolors.h"

using namespace std;

class PixelImage
{
public:

    PixelImage();

    PixelImage(int HeightPixel_Init_, int WidthPixel_Init_, int HeightPixel_End_, int WidthPixel_End_, QImage &MyImage, vector<vector <int>> *MatrizPixelsCopy, int Type_);

    vector<int> getMyColor() const;

    vector<vector <int>> *MatrizPixelsCopy;

    int MyType;

private:

    int HeightPixel_Init;

    int WidthPixel_Init;

    int HeightPixel_End;

    int WidthPixel_End;


    vector <vector<int>> *MyAreaOfPixeles; //Pixeles de mi area

    vector<int> MyColor;  //Pixel de representación

    bool comparateVector(vector<int> elemnt1, vector<int> elemnt2);//Comparar los valores de dos pixeles, para saber si son iguales

    void getMyColor();  //Para obtener mi pixel de representación

};

#endif // PIXELIMAGE_H
