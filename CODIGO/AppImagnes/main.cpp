#include <iostream>
#include <QImage>
#include "RW_files.h"

using namespace std;

string CharToString(char array[]);


void CreateTxt(QImage *im, string RedFile_, string BlueFile_, string GreenFile_);
int main()
{
    string filename="colombia.png";

    QImage im(filename.c_str());

    unsigned int pixelX=50;
    unsigned int pixelY=70;

    //QSize sizeImg=im.size();

    //cout << "La imagen tiene un tamano de: "<< sizeImg.<<" * "<<sizeImg.width()<<endl;

    cout << "Valor en RED del pixel selccionado: "<<im.pixelColor(pixelX, pixelY).red()<<endl;
    cout << "Valor en BLUE del pixel selccionado: "<<im.pixelColor(pixelX, pixelY).blue()<<endl;
    cout << "Valor en GREEN del pixel selccionado: "<<im.pixelColor(pixelX, pixelY).green()<<endl;

    cout << "The size of the image is: "<<im.width()<<" | "<<im.height()<<endl;

    string RedFile="";
    string BlueFile="";
    string GreemFile="";

    CreateTxt(&im, RedFile, BlueFile, GreemFile);

    return 0;

}

void CreateTxt(QImage *im, string RedFile_, string BlueFile_, string GreenFile_){

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
