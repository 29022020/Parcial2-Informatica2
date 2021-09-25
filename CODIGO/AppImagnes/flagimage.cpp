#include "flagimage.h"

FlagImage::FlagImage()
{

}

FlagImage::FlagImage(QString ruta)
{

    Image=new QImage(ruta);

    MatrizPixels = new vector<vector <int>>;

    Width=Image->width();
    Height=Image->height();

    CreatePixeles();

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

   cout<<FaulPixelesHeight<<" | "<<FaulPixelesWidth<<endl;

   for(int i=Height_; i<=getHeight()-1; i+= Height_){

       cout<<endl<<"Colum: "<<i<<endl<<endl;

       for(int j=Width_; j<=getWidth(); j+=Width_){

          cout<<"Pixels["<<contX<<"]["<<contY<<"]= ";

          if(j!=getWidth()-FaulPixelesWidth-1 && i!=getHeight()-FaulPixelesHeight-1){

          cout<<"0: ("<<LastValueH<<", " <<LastValueW<<", " <<i<<", " << j<<") "<<endl;

          PixelImage element(LastValueH, LastValueW, i, j, *Image, MatrizPixels);
          MatrizLeds[contX][contY]=element;

          contX++;

          }else if(j==getWidth()-FaulPixelesWidth-1 && i!=getHeight()-FaulPixelesHeight-1){

              cout<<"1: ("<<LastValueH<<", " <<LastValueW<<", " <<i<<", " << j+FaulPixelesWidth<<") "<<endl;

              PixelImage element(LastValueH, LastValueW, i, j+FaulPixelesWidth, *Image, MatrizPixels);
              MatrizLeds[contX][contY]=element;

              contX++;


          }
          else if(j!=getWidth()-FaulPixelesWidth-1 && i==getHeight()-FaulPixelesHeight-1){

                        cout<<"2: ("<<LastValueH<<", " <<LastValueW<<", " <<i+FaulPixelesHeight<<", " << j<<") "<<endl;


                        PixelImage element(LastValueH, LastValueW, i+FaulPixelesHeight, j, *Image, MatrizPixels);
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

    float Width_=getWidth()/16;  //0.625

    float Height_=getHeight()/16;  //0.375

    float FaulPixelesWidth=getWidth()%16;

    float FaulPixelesHeight=getHeight()%16;

    int LastValueW=0;

    int LastValueH=0;

    int contX=0;

    int contY=0;

    int aux1=0;

    int aux2=0;

    int BlueValor, RedValor, GreenValor;

    for(int i=Height_; i<=getHeight()-1; i+= Height_){

         aux1+=i;

         if(aux1>=1){

             contY++;
         }

        for(int j=Width_; j<=getWidth(); j+=Width_){

            aux2+=j;

            if(aux2>=1){

                contX++;
            }

            BlueValor=(*Image).pixelColor(contX, contY).blue();
            RedValor=(*Image).pixelColor(contX, contY).red();
            GreenValor=(*Image).pixelColor(contX, contY).green();

           vector <int>*AuxVector=new vector <int>;

            AuxVector->push_back(RedValor);
            AuxVector->push_back(GreenValor);
            AuxVector->push_back(BlueValor);

            //MyAreaOfPixeles.push_back(*AuxVector);

            delete AuxVector;



           }

      contX=0;


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

            MatrizLeds+="{ "+to_string(value[0])+", "+to_string(value[1])+", "+to_string(value[2])+"}}";

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


    escribir("MyFile.txt", MatrizLeds);



}
