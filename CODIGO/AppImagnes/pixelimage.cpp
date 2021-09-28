#include "pixelimage.h"

PixelImage::PixelImage()
{

}

PixelImage::PixelImage(int HeightPixel_Init_, int WidthPixel_Init_, int HeightPixel_End_, int WidthPixel_End_, QImage &MyImage,  vector<vector <int>> *MatrizPixelsCopy_, int MyType_)
{
    /*PixelImage: Constructor que recibe los extremos del area asinada para PixelImage, la informacion
     * de la imagen a traves de la intacia de QImage, y el tipo de proceso de area a realzar.
     * Para posteriomente analizar el area asignada, y definir el pixel de representacion del area dada.
     *
     *Tipo uno: proceso de submuestreo.
     *
     *Tipo dos: proceso de mayor ancho menor alto.
     *
     *Tipo tres: proceso de menor ancho mayor alto.
     *
     */

    HeightPixel_Init=HeightPixel_Init_;

    WidthPixel_Init=WidthPixel_Init_;

    HeightPixel_End=HeightPixel_End_;

    WidthPixel_End=WidthPixel_End_;

    MatrizPixelsCopy=MatrizPixelsCopy_;

    MyAreaOfPixeles=new vector <vector<int>>;

    MyType=MyType_;

    if(MyImage.height()==HeightPixel_End){

         HeightPixel_End--;

    }

    if(MyImage.width()==WidthPixel_End){

        WidthPixel_End--;

    }


    int BlueValor, RedValor, GreenValor;

    if(MyType==1){

    for(int indy=HeightPixel_Init; indy<=HeightPixel_End; indy++){

            for(int indx=WidthPixel_Init; indx <=WidthPixel_End; indx++){


                   BlueValor=MyImage.pixelColor(indx, indy).blue();
                   RedValor=MyImage.pixelColor(indx, indy).red();
                   GreenValor=MyImage.pixelColor(indx, indy).green();

                   if(BlueValor==0 && RedValor==0 && GreenValor==0){

                       BlueValor+=1;
                       RedValor+=1;
                       GreenValor+=1;
                   }

                   if(BlueValor==255 && RedValor==255 && GreenValor==255){

                       BlueValor-=1;
                       RedValor-=1;
                       GreenValor-=1;
                   }


                   vector <int>*AuxVector=new vector <int>;

                   AuxVector->push_back(RedValor);
                   AuxVector->push_back(GreenValor);
                   AuxVector->push_back(BlueValor);

                   MyAreaOfPixeles->push_back(*AuxVector);

                   delete AuxVector;

        }

    }

    }

    if(MyType==2){

    int indy=HeightPixel_Init;

         for(int indx=WidthPixel_Init; indx <=WidthPixel_End-1; indx++){


                BlueValor=MyImage.pixelColor(indx, indy).blue();
                RedValor=MyImage.pixelColor(indx, indy).red();
                GreenValor=MyImage.pixelColor(indx, indy).green();

                if(BlueValor==0 && RedValor==0 && GreenValor==0){

                    BlueValor+=10;
                    RedValor+=10;
                    GreenValor+=10;
                }
                if(BlueValor==255 && RedValor==255 && GreenValor==255){

                    BlueValor-=1;
                    RedValor-=1;
                    GreenValor-=1;
                }


                vector <int>*AuxVector=new vector <int>;

                AuxVector->push_back(RedValor);
                AuxVector->push_back(GreenValor);
                AuxVector->push_back(BlueValor);

                MyAreaOfPixeles->push_back(*AuxVector);

                delete AuxVector;

     }

     }
    if(MyType==3){

        int indx=WidthPixel_Init;

             for(int indy=HeightPixel_Init; indy <=HeightPixel_End-1; indy++){


                    BlueValor=MyImage.pixelColor(indx, indy).blue();
                    RedValor=MyImage.pixelColor(indx, indy).red();
                    GreenValor=MyImage.pixelColor(indx, indy).green();

                    if(BlueValor==0 && RedValor==0 && GreenValor==0){

                        BlueValor+=10;
                        RedValor+=10;
                        GreenValor+=10;
                    }
                    if(BlueValor==255 && RedValor==255 && GreenValor==255){

                        BlueValor-=1;
                        RedValor-=1;
                        GreenValor-=1;
                    }


                    vector <int>*AuxVector=new vector <int>;

                    AuxVector->push_back(RedValor);
                    AuxVector->push_back(GreenValor);
                    AuxVector->push_back(BlueValor);

                    MyAreaOfPixeles->push_back(*AuxVector);

                    delete AuxVector;

         }


    }


    getMyColor();

    delete MyAreaOfPixeles;

}

vector<int> PixelImage::getMyColor() const
{
    return MyColor;
}

bool PixelImage::comparateVector(vector<int> elemnt1, vector<int> elemnt2)
{

    /*comparateVector: compara si dos colores (representacion en un vector de tres valores enteros) son iguales.
     *
     *
     */
    for(int i=0; i<3; i++){

        if(elemnt1.at(i)!=elemnt2.at(i)){

            return false;
        }
    }

    return true;

}

void PixelImage::getMyColor()
{
    /*getMyColor: Funcion que determina cual es color de represenatcion del area de pixeles
     * utilizando instancias de la clase countColors, par saber cuantas veces se repite un color
     * en el area.
     *
     */

    vector <int> aux;

    bool flag=true;

    vector <countColors> *ColorsArea=new vector <countColors>;

    for(auto valor : *MyAreaOfPixeles){

        if(!ColorsArea->empty()){

        for(auto value: *ColorsArea){

        if(comparateVector(value.getMyColor(), valor)){

                value.setMyNumOfColors(value.getMyNumOfColors()+1);

                flag=false;
        }


        }

        if(flag){

            countColors element(valor);
            ColorsArea->push_back(element);


        }

        }
        else{

          countColors element(valor);
          ColorsArea->push_back(element);

        }


    }


    countColors MyUniqueColor;

    bool flag2=true;

    for(auto value : *ColorsArea){

        if(flag2){

            MyUniqueColor=value;

            flag=false;

        }
        else{

            if(value.getMyNumOfColors()>MyUniqueColor.getMyNumOfColors()){

                MyUniqueColor=value;

            }
        }

    }

    delete ColorsArea;

    MyColor=MyUniqueColor.getMyColor();

    MatrizPixelsCopy->push_back(MyColor);

}
