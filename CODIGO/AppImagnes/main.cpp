#include <iostream>
#include <QImage>

using namespace std;

int main()
{
    string filename="RM.jpg";


    QImage im(filename.c_str());

    unsigned int pixelX=898;
    unsigned int pixelY=776;

    //QSize sizeImg=im.size();

    //cout << "La imagen tiene un tamano de: "<< sizeImg.<<" * "<<sizeImg.width()<<endl;

    cout << "Valor en RED del pixel selccionado: "<<im.pixelColor(pixelX, pixelY).red()<<endl;
    cout << "Valor en BLUE del pixel selccionado: "<<im.pixelColor(pixelX, pixelY).blue()<<endl;
    cout << "Valor en GREEN del pixel selccionado: "<<im.pixelColor(pixelX, pixelY).green()<<endl;

    cout << "The size of the image is: "<<im.width()<<" | "<<im.height()<<endl;

    /*for(int indx=0; indx<im.width(); ++indx){

        for(int indy=0; indy <im.height(); ++indy){

            cout << "Valor en RED del pixel selccionado: "<<im.pixelColor(indx, indy).red()<<endl;
        }
    }*/

    return 0;
}
