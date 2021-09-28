///////////////////////////////////////////////////////////
///              CLASE COUNTCOLORS
///
/// CLASE AUXILIAR QUE AYUDA A PIXELIMAGE; EN BUSQUEDA DEL
/// COLOR REPRESENATCIÓN.
///
/// FUNCION:
/// -SE LE ASIGNA UN VECTOR QUE CORRESPONDE A UN COLOR RGB
/// Y UNA VARIABLE QUE DERTEMINARA EL NUMERO DE VECES QUE
/// SE ENCUENTRA ESE COLOR EN EL AREA.
///

#ifndef COUNTCOLORS_H
#define COUNTCOLORS_H

#include <iostream>
#include <vector>

using namespace std;

class countColors
{
public:

    vector <int> myColor;

    int myNumOfColors;

    countColors();

    countColors(vector <int> myColor_);

    int getMyNumOfColors() const;

    void setMyNumOfColors(int value);

    vector<int> getMyColor() const;

};

#endif // COUNTCOLORS_H
