#include <iostream>
#include <QImage>
#include "RW_files.h"
#include "flagimage.h"

//////////////////////
/*PONGA EN FRENTE DE LA DEFINICIÓN DE LA MACRO MY_FILE LA RUTA DE LA IMAGEN
 *
 * EJEMPLO:
 *
 * #define MY_FILE ":/new/prefix1/Imagenes/Flag_of_Brazil.svg.png"
 *
 */

#define MY_FILE ":/new/prefix1/Imagenes/Flag_of_Brazil.svg.png"

using namespace std;

int main()
{

    QString filename=MY_FILE;

    FlagImage myImage(filename);

    return 0;

}

