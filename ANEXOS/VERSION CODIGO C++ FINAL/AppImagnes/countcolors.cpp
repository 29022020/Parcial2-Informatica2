#include "countcolors.h"


int countColors::getMyNumOfColors() const
{
    /*getMyNumOfColors: Funcion que retorna el numero de veces que se repite
     * mi color asignado.
     *
     */

    return myNumOfColors;
}

void countColors::setMyNumOfColors(int value)
{
    /*setMyNumOfColors: Funcion que recibe el numero de veces que se repite
     * el color asignado.
     *
     */

    myNumOfColors = value;
}

vector<int> countColors::getMyColor() const
{
    /*getMyColor: Funcion que retorna en un vector de tres elementos
     * los valors correspondientes a el color asignado.
     *
     */

    return myColor;
}

countColors::countColors()
{

}

countColors::countColors(vector<int> myColor_)
{

    myColor=myColor_;

    myNumOfColors=1;

}
