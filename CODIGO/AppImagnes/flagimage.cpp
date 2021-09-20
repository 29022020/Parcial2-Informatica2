#include "flagimage.h"

FlagImage::FlagImage()
{

}

FlagImage::FlagImage(QString ruta)
{

    Image=new QImage(ruta);

    Width=Image->width();
    Height=Image->height();

}

int FlagImage::getHeight() const
{
    return Height;
}

int FlagImage::getWidth() const
{
    return Width;
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

   int ContX=0;

   int ContY=0;

   for(int i=0; i<getWidth(); i+=Width_){


       for(int j=0; j<getHeight(); j+=Height_){

          PixelImage element(Height_, Width_, i, j);
          MatrizLeds[ContX][ContY]=element;

       }

   }


}
