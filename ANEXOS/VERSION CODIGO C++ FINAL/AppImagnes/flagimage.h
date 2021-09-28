///////////////////////////////////////////////////////////
///              CLASE FLAGIMAGE
///
/// CLASE QUE RECIBE LA IMAGEN DEL USUARIO.
///
/// FUNCION:
/// -ANALIZAR LA IMAGEN (DIMESIONES)
/// PARA TRANSFORMARLA EN LA MATRIZ DE LEDS RGB
/// 16*16.
/// A TRAVÉS DEL PROCESO SUBMUESTREO Y EL SOBREMUESTREO
/// E INTERMEDIOS (CUANDO EL ANCHO ES MAYOR A 16 PIXELES
/// Y EL ALTO MENOR A 16 PIXELES, ADEMAS CUANDO EL ANCHO
/// ES MENOR A 16 PIXELES Y EL ALTO MENOR A 16 PIXELES).
///
/// -EXPORTAR EN UN ARCHIVO .TXT LA INFORMACION NECESARIA
/// PARA QUE LA IMAGEN SEA REPRESENTADA EN LA MATRIZ DE
/// LEDS RGB DE LA PLATAFORMA TINKERCAD.
///
///

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

    vector<vector <int>> *MatrizPixels;

    int getHeight() const;

    int getWidth() const;

private:

    int Height;

    int Width;

    void SelectMySize();

    void CreatePixeles();

    void CreatePixeles2();

    void CreatePixeles3();

    void CreatePixeles4();

    void genTheTxtPixels();

};

#endif // FLAGIMAGE_H
