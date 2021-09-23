#include "pixelimage.h"

PixelImage::PixelImage()
{

}

PixelImage::PixelImage(int HeightPixel_Init_, int WidthPixel_Init_, int HeightPixel_End_, int WidthPixel_End_, QImage &MyImage)
{
    HeightPixel_Init=HeightPixel_Init_;

    WidthPixel_Init=WidthPixel_Init_;

    HeightPixel_End=HeightPixel_End_;

    WidthPixel_End=WidthPixel_End_;

    int BlueValor, RedValor, GreenValor;

    for(int indy=HeightPixel_Init; indy<=HeightPixel_End; indy++){

            for(int indx=WidthPixel_Init; indx < WidthPixel_End; indx++){


                   BlueValor=MyImage.pixelColor(indx, indy).blue();
                   RedValor=MyImage.pixelColor(indx, indy).red();
                   GreenValor=MyImage.pixelColor(indx, indy).green();

                   vector <int>*AuxVector=new vector <int>;

                   AuxVector->push_back(BlueValor);
                   AuxVector->push_back(RedValor);
                   AuxVector->push_back(GreenValor);

                   MyAreaOfPixeles.push_back(*AuxVector);

                   delete AuxVector;

        }

    }

}

vector<int> PixelImage::getMyColor() const
{
    return MyColor;
}

bool PixelImage::comparateVector(vector<int> elemnt1, vector<int> elemnt2)
{
    for(int i=0; i<3; i++){

        if(elemnt1[i]!=elemnt2[i]){

            return false;
        }
    }

    return true;

}

void PixelImage::getMyColor()
{
    vector <int> aux;

    vector<vector <int>> DifVectors;

    for(auto valor : MyAreaOfPixeles){


        for(auto value: DifVectors){

          //Comparar los vectores, y contar cuantos pixeles hay de cada color, para hallar el mas abundante

        }

    }

}
