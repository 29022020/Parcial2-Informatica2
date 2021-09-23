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
