#ifndef FLAGIMAGE_H
#define FLAGIMAGE_H
#include <iostream>
#include <QImage>
#include "RW_files.h"
#include <array>
#include <vector>
#include "pixelimage.h"

////////////////////////////////
///
/// CLASE QUE RECIBE LA IMAGEN DEL USUARIO
///
/// ANALIZAR LA IMAGEN
/// PARA TRANSFORMARLA EN LA MATRIZ DE LEDS RGB
///
/// A TRAVÉS DEL SUBMUESTREO Y EL SOBREMUESTREO
///
/// PARA EXPORTAR EL CODIGO A USAR EN TINKERCAD

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

    void ShowMyPixeles();


private:

    int Height;

    int Width;

    void CreateTxt(QImage *im, string RedFile_, string BlueFile_, string GreenFile_);

    void SelectMySize();

    void CreatePixeles();//Crear la division areas dentro de la imagen

    void CreatePixeles2();

    void CreatePixeles3();

    void CreatePixeles4();

    void genTheTxtPixels();


};

#endif // FLAGIMAGE_H
