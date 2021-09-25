#include "pixelimage.h"

PixelImage::PixelImage()
{

}

PixelImage::PixelImage(int HeightPixel_Init_, int WidthPixel_Init_, int HeightPixel_End_, int WidthPixel_End_, QImage &MyImage)
{

    cout<<"New Pixel"<<endl;

    HeightPixel_Init=HeightPixel_Init_;

    WidthPixel_Init=WidthPixel_Init_;

    HeightPixel_End=HeightPixel_End_;

    WidthPixel_End=WidthPixel_End_;

    int BlueValor, RedValor, GreenValor;

    for(int indy=HeightPixel_Init; indy<=HeightPixel_End; indy++){

            for(int indx=WidthPixel_Init; indx <=WidthPixel_End; indx++){


                   BlueValor=MyImage.pixelColor(indx, indy).blue();
                   RedValor=MyImage.pixelColor(indx, indy).red();
                   GreenValor=MyImage.pixelColor(indx, indy).green();

                   vector <int>*AuxVector=new vector <int>;

                   AuxVector->push_back(RedValor);
                   AuxVector->push_back(GreenValor);
                   AuxVector->push_back(BlueValor);     

                   MyAreaOfPixeles.push_back(*AuxVector);

                   delete AuxVector;

        }

    }

    getMyColor();

}

vector<int> PixelImage::getMyColor() const
{
    return MyColor;
}

bool PixelImage::comparateVector(vector<int> elemnt1, vector<int> elemnt2)
{

    for(int i=0; i<3; i++){

        if(elemnt1.at(i)!=elemnt2.at(i)){

            return false;
        }
    }

    return true;

}

void PixelImage::getMyColor()
{

    vector <int> aux;

    bool flag=true;

    vector <countColors> ColorsArea;

    for(auto valor : MyAreaOfPixeles){

        if(!ColorsArea.empty()){

        for(auto value: ColorsArea){

        if(comparateVector(value.getMyColor(), valor)){

                value.setMyNumOfColors(value.getMyNumOfColors()+1);

                flag=false;

        }


        }

        if(flag){

            countColors element(valor);
            ColorsArea.push_back(element);

        }

        }
        else{

          countColors element(valor);
          ColorsArea.push_back(element);

        }

        flag=true;

    }

    countColors MyUniqueColor;

    bool flag2=true;

    for(auto value : ColorsArea){

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

    MyColor=MyUniqueColor.getMyColor();
    int cont=1;
    cout<<endl;
    for(auto valou: MyColor){
        if(cont==1){

            cout<<endl<<endl<<"My color is: Red="<<valou<<endl;

        }
        if(cont==2){

            cout<<endl<<endl<<"My color is: Green="<<valou<<endl;
        }
        if(cont==3){

            cout<<endl<<endl<<"My color is: Blue="<<valou<<endl;

        }
        cont++;

    }

    cout<<endl;
    cout<<endl;




}
