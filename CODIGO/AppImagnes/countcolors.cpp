#include "countcolors.h"



int countColors::getMyNumOfColors() const
{
    return myNumOfColors;
}

void countColors::setMyNumOfColors(int value)
{
    myNumOfColors = value;
}

vector<int> countColors::getMyColor() const
{
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
