#include "flagimage.h"

FlagImage::FlagImage()
{

}

FlagImage::FlagImage(QString ruta)
{

    Image=new QImage(ruta);

    MatrizPixels = new vector<vector <int>>;

    MatrizPixels2= new vector<vector <int>>;

    Width=Image->width();
    Height=Image->height();

    CreatePixeles3();

   //SelectMySize();

    genTheTxtPixels();

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




}

void FlagImage::SelectMySize()
{

    if(getWidth() <= 16 && getHeight() <= 16){


         CreatePixeles2();


    }else if(getWidth() > 16 && getHeight() > 16){

         CreatePixeles();


    }else if(getWidth() > 16 && getHeight() <= 16){




    } else if(getWidth() < 16 && getHeight() > 16){



    }
=======


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

   cout<<FaulPixelesHeight<<" | "<<FaulPixelesWidth<<endl;

   for(int i=Height_; i<=getHeight(); i+= Height_){

       cout<<endl<<"Colum: "<<i<<endl<<endl;

       for(int j=Width_; j<=getWidth(); j+=Width_){

          cout<<"Pixels["<<contX<<"]["<<contY<<"]= ";

          if(j!=getWidth()-FaulPixelesWidth-1 && i!=getHeight()-FaulPixelesHeight-1){

          cout<<"0: ("<<LastValueH<<", " <<LastValueW<<", " <<i<<", " << j<<") "<<endl;

          PixelImage element(LastValueH, LastValueW, i, j,*Image, MatrizPixels);
          MatrizLeds[contX][contY]=element;

          contX++;

          }else if(j==getWidth()-FaulPixelesWidth-1 && i!=getHeight()-FaulPixelesHeight-1){

              cout<<"1: ("<<LastValueH<<", " <<LastValueW<<", " <<i<<", " << j+FaulPixelesWidth<<") "<<endl;

              PixelImage element(LastValueH, LastValueW, i, j+FaulPixelesWidth,*Image, MatrizPixels);
              MatrizLeds[contX][contY]=element;

              contX++;


          }
          else if(j!=getWidth()-FaulPixelesWidth-1 && i==getHeight()-FaulPixelesHeight-1){

                        cout<<"2: ("<<LastValueH<<", " <<LastValueW<<", " <<i+FaulPixelesHeight<<", " << j<<") "<<endl;


                        PixelImage element(LastValueH, LastValueW,i+FaulPixelesHeight, j,*Image, MatrizPixels);
                        MatrizLeds[contX][contY]=element;

                        contX++;


           }else if(j==getWidth()-FaulPixelesWidth-1 && i==getHeight()-FaulPixelesHeight-1){


             cout<<"3: ("<<LastValueH<<", " <<LastValueW<<", " <<i+FaulPixelesHeight<<", " << j+FaulPixelesWidth<<") ,";

             PixelImage element(LastValueH, LastValueW, i+FaulPixelesHeight, j+FaulPixelesWidth, *Image, MatrizPixels);
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

void FlagImage::CreatePixeles2()
{

    float Width_=float(getWidth())/16.0;  //0.75

    float Height_=float(getHeight())/16.0;  //0.5

    float FaulPixelesWidth=getWidth()%16;

    float FaulPixelesHeight=getHeight()%16;

    int LastValueW=0;

    int LastValueH=0;

    int contX=0;

    int contY=0;

    int contX1=0;

    int contY1=0;

    float aux1=0;

    float aux2=0;

    int BlueValor, RedValor, GreenValor;

    cout<<Width_<<"||"<<Height_<<endl;

    for(int i=1; i<=16; i++){


        for(int j=1; j<=16; j++){


            BlueValor=(*Image).pixelColor(contX, contY).blue();
            RedValor=(*Image).pixelColor(contX, contY).red();
            GreenValor=(*Image).pixelColor(contX, contY).green();

            cout<<"Pixel["<<contX1<<"]["<<contY1<<"]=("<<RedValor<<", " <<GreenValor<<", " <<BlueValor<<") "<<endl;

           vector <int>*AuxVector=new vector <int>;

            AuxVector->push_back(RedValor);
            AuxVector->push_back(GreenValor);
            AuxVector->push_back(BlueValor);

            MatrizPixels->push_back(*AuxVector);

           // delete AuxVector;

            if(aux2>=1.0){

                contX++;
                cout<<aux2<<endl;
                aux2=0.0;


            }


            aux2+=Width_;
            contX1++;





           }


      cout<<endl;

      if(aux1>=1.0){

          contY++;
          aux1=0.0;


      }
      contY1++;
      contX1=0;
      contX=0;
      aux1+=Height_;


    }





}

void FlagImage::CreatePixeles3()
{
   int Width_=getWidth()/16;

   float Height_=float(getHeight())/16.0;;

   int FaulPixelesWidth=getWidth()%16;

  // int FaulPixelesHeight=getHeight()%16;

   //if(FaulPixelesHeight!=0){

    // FaulPixelesHeight+=-1;

  // }

   int LastValueW=0;

   int LastValueH=0;

   int contX=0;

   int contY=0;

   int contX1=0;

   int contY1=0;

   float aux1=0;

   float aux2=0;

   if(FaulPixelesWidth!=0){

       FaulPixelesWidth+=-1;
   }

   cout<<Width_<<" | "<<Height_<<endl<<endl;

   cout<<getHeight()<<" | "<<getWidth()<<endl;

   //cout<<FaulPixelesHeight<<" | "<<FaulPixelesWidth<<endl;

   int co=0;

   for(int i=0; i<16; i++){

      cout<<endl<<"Colum: "<<i<<endl<<endl;

       for(int j=Width_; j<=getWidth() &&co!=16; j+=Width_){

         cout<<"Pixels["<<contX<<"]["<<contY1<<"]= ";

          if(j!=getWidth()-FaulPixelesWidth-1){

       cout<<"1: ("<<contY<<", " <<LastValueW<<", " <<contY<<", " << j<<") "<<endl;

          PixelImage element(contY, LastValueW, contY, j, *Image, MatrizPixels);
          MatrizLeds[contX][contY]=element;

          contX++;

          }else if(j==getWidth()-FaulPixelesWidth-1){

            cout<<"2: ("<<LastValueH<<", " <<LastValueW<<", " <<contY<<", " << j+FaulPixelesWidth<<") "<<endl;

              PixelImage element(contY, LastValueW, contY, j+FaulPixelesWidth, *Image, MatrizPixels);
              MatrizLeds[contX][contY]=element;

              contX++;


          }
          LastValueW=j;
          co++;

       }

       cout<<endl;



      if(aux1>=1.0){

           contY++;
           aux1=0.0;
           cout<<contY<<endl;


           }
        contX=0;
        aux1+=Height_;     
        LastValueW=0;
        contY1++;

        co=0;

   }




}

void FlagImage::genTheTxtPixels()
{
    string MatrizLeds="";

    int contX=0;

    int contY=0;



    for(auto value: *MatrizPixels){

        if(contX==0){

           MatrizLeds+="{{ "+to_string(value[0])+", "+to_string(value[1])+", "+to_string(value[2])+"}, ";

             contY++;

        }else if(contX==255){

            MatrizLeds+="{ "+to_string(value[0])+", "+to_string(value[1])+", "+to_string(value[2])+"}};";

           contY++;




        }else{


            MatrizLeds+="{ "+to_string(value[0])+", "+to_string(value[1])+", "+to_string(value[2])+"}, ";

            contY++;


        }


        contX++;

        if(contY==16){

        MatrizLeds+="\n";

        contY=0;

        }

    }
    cout << endl<<"Job Done"<<endl;

    escribir("MyFile.txt", MatrizLeds);



}
