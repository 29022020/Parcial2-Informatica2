#include <iostream>
#include <QImage>
#include "RW_files.h"

using namespace std;

void CreateTxt(QImage *im, string *RedFile_, string *BlueFile_, string *GreenFile_);

string CharToString(char array[]);

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

    CreateTxt(&im, &RedFile, &BlueFile, &GreemFile);

    return 0;

}

void CreateTxt(QImage *im, string *RedFile_, string *BlueFile_, string *GreenFile_){

    for(int indx=0; indx<(*im).width(); ++indx){

        for(int indy=0; indy <(*im).height(); ++indy){

            if(indy==0){

                (*RedFile_)+='-';
                (*BlueFile_)+='-';
                (*GreenFile_)+='-';

                (*RedFile_)+=(*im).pixelColor(indx, indy).red();
                (*BlueFile_)+=(*im).pixelColor(indx, indy).blue();
                (*GreenFile_)+=(*im).pixelColor(indx, indy).green();

            }
            else{

                if(indy!=(*im).height()){

                (*RedFile_)+=(*im).pixelColor(indx, indy).red();
                (*BlueFile_)+=(*im).pixelColor(indx, indy).blue();
                (*GreenFile_)+=(*im).pixelColor(indx, indy).green();

                (*RedFile_)+='-';
                (*BlueFile_)+='-';
                (*GreenFile_)+='-';

                }
                else{

                    (*RedFile_)+=(*im).pixelColor(indx, indy).red();
                    (*BlueFile_)+=(*im).pixelColor(indx, indy).blue();
                    (*GreenFile_)+=(*im).pixelColor(indx, indy).green();

                }

            }

        }

        (*RedFile_)+='\n';
        (*BlueFile_)+='\n';
        (*GreenFile_)+='\n';

    }

    escribir("Red_file.txt", *RedFile_);
    escribir("Blue_file.txt", *BlueFile_);
    escribir("Red_Green.txt", *GreenFile_);

    cout << endl<<"Job Done"<<endl;

}
string CharToString(char array[])
{
    /*stringToInt: Función que una vez le ingreses un string que es una cadena de numeros, los convierte en enteros.
     *
     * Parametro: string text.
     *
     * Retorno: El valor entero del string ingresado.
     *
     */

    string Elemento="";

    for(int i=0; i<3; i++){

        if(array[i]=='0'){

            Elemento+="0";
        }

        if(array[i]=='1'){

            Elemento+="1";

        }
        if(array[i]=='2'){

            Elemento+="2";

        }
        if(array[i]=='3'){

            Elemento+="3";

        }
        if(array[i]=='4'){

            Elemento+="4";

        }
        if(array[i]=='5'){

            Elemento+="5";
        }
        if(array[i]=='6'){

            Elemento+="6";

        }

        if(array[i]=='7'){

            Elemento+="7";

        }
        if(array[i]=='8'){

            Elemento+="8";

        }
        if(array[i]=='9'){

            Elemento+="9";

        }

    }

    return Elemento;
}
