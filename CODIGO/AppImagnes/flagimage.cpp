#include "flagimage.h"

FlagImage::FlagImage()
{

}

FlagImage::FlagImage(QString ruta)
{

    Image=new QImage(ruta);

    Width=Image->width();
    Height=Image->height();

    CreatePixeles();

}

int FlagImage::getHeight() const
{
    return Height;
}

int FlagImage::getWidth() const
{
    return Width;
}

void FlagImage::ShowMyPixeles()
{

    for(int i=0; i<16; i++){

        for(int j=0; j<16; j++){

            //cout<<"Pixel["<<i<<"]["<<j<<"]= "<<MatrizLeds.at(i).at(j).getMyColor().at(0)<<endl;

        }
    }
}

void FlagImage::CreateTxt(QImage *im, string RedFile_, string BlueFile_, string GreenFile_)
{
    for(int indx=0; indx<(*im).width(); indx++){

        for(int indy=0; indy <(*im).height(); indy++){

            if(indy!=((*im).height()-1)){

                RedFile_+=to_string((*im).pixelColor(indx, indy).red())+'-';
                BlueFile_+=to_string((*im).pixelColor(indx, indy).blue())+'-';
                GreenFile_+=to_string((*im).pixelColor(indx, indy).green())+'-';

            }
            else{

                RedFile_+=to_string((*im).pixelColor(indx, indy).red());
                BlueFile_+=to_string((*im).pixelColor(indx, indy).blue());
                GreenFile_+=to_string((*im).pixelColor(indx, indy).green());

            }

        }
        if(indx!=(*im).width()-1){

        RedFile_+='\n';
        BlueFile_+='\n';
        GreenFile_+='\n';

        }

    }

    escribir("Red_file.txt", RedFile_);
    escribir("Blue_file.txt", BlueFile_);
    escribir("Green_file.txt", GreenFile_);

    cout << endl<<"Job Done"<<endl;

}

void FlagImage::CreatePixeles()
{
   int Width_=getWidth()/16;

   int Height_=getHeight()/16;

   int FaulPixelesWidth=getWidth()%16;

   int FaulPixelesHeight=getHeight()%16;

   if(FaulPixelesHeight!=0){

      FaulPixelesHeight+=-1;
   }
   if(FaulPixelesWidth!=0){

       FaulPixelesWidth+=-1;
   }

   int LastValueW=0;

   int LastValueH=0;

   int contX=0;

   int contY=0;

   cout<<Width_<<" | "<<Height_<<endl<<endl;

   cout<<getHeight()<<" | "<<getWidth()<<endl;

   for(int i=Height_; i<=getHeight()-1; i+= Height_){

       cout<<endl<<"Colum: "<<i<<endl<<endl;

       for(int j=Width_; j<=getWidth()-1; j+=Width_){

          cout<<"Pixels["<<contX<<"]["<<contY<<"]= ";

          if(j!=getWidth()-FaulPixelesWidth && i!=getHeight()-FaulPixelesHeight){

          cout<<"0: ("<<LastValueH<<", " <<LastValueW<<", " <<i<<", " << j<<") "<<endl;

          PixelImage element(LastValueH, LastValueW, i, j, *Image);
          MatrizLeds[contX][contY]=element;

          contX++;

          }else if(j==getWidth()-FaulPixelesWidth && i!=getHeight()-FaulPixelesHeight){

              cout<<"1: ("<<LastValueH<<", " <<LastValueW<<", " <<i<<", " << j+FaulPixelesWidth<<") "<<endl;

              PixelImage element(LastValueH, LastValueW, i, j+FaulPixelesWidth, *Image);
              MatrizLeds[contX][contY]=element;

              contX++;


          }
          else if(j!=getWidth()-FaulPixelesWidth && i==getHeight()-FaulPixelesHeight){

                        cout<<"2: ("<<LastValueH<<", " <<LastValueW<<", " <<i+FaulPixelesHeight<<", " << j<<") "<<endl;


                        PixelImage element(LastValueH, LastValueW, i+FaulPixelesHeight, j, *Image);
                        MatrizLeds[contX][contY]=element;

                        contX++;


           }else if(j==getWidth()-FaulPixelesWidth && i==getHeight()-FaulPixelesHeight){


             cout<<"3: ("<<LastValueH<<", " <<LastValueW<<", " <<i+FaulPixelesHeight<<", " << j+FaulPixelesWidth<<") ,";

             PixelImage element(LastValueH, LastValueW, i+FaulPixelesHeight, j+FaulPixelesWidth, *Image);
              MatrizLeds[contX][contY]=element;

              contX++;


          }

          LastValueW=j;

          //contX++;



       }

       cout<<endl;


       contX=0;
       contY++;
       LastValueH=i;

       LastValueW=0;

   }




}

void FlagImage::genTheTxtPixels()
{

}
