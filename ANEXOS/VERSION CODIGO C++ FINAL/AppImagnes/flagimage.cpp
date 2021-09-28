#include "flagimage.h"

FlagImage::FlagImage()
{

}

FlagImage::FlagImage(QString ruta)
{
    /*FlagImage: Constructor de clae, que una vez se le da ruta de la imagen
     * crea una isntacia de la clase QImage, analiza las dimensiones de la imagen
     * y decide que metodo emplear(sobremuestreo, submuestreo, combinados) usar
     * para hacer la transformacion de la imagen a 16*16 pixeles, y exportar
     * esta informacion en un .txt, para seguir con el proceso de muestreo.
     *
     */

    Image=new QImage(ruta);

    MatrizPixels = new vector<vector <int>>;

    Width=Image->width();
    Height=Image->height();

    cout<<"============================================================================"<<endl;

    cout<<endl<<"                  Iniciando transformacion de la Imagen."<<endl<<endl;

    cout<<"============================================================================"<<endl;

    SelectMySize();

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

void FlagImage::SelectMySize()
{
    /*SelectMySize: funcion que analiza las dimensiones de la imagen:
     *
     * -Si la imagen tiene mayor ancho y alto a 16, entonces emplea
     * el metodo de submuestreo.
     *
     * -Si la imagen  tiene ancho y alto mayor
     * o igual 16 realiza metodo de sobremuestreo.
     *
     * -Si el ancho es mayor a 16 pero no su alto, emplea un metodo
     * combinado.
     *
     * -Si el alto es mayor a 16 pero no su ancho, emplea un metodo
     * combinado.
     *
     */

    if(getWidth() <= 16 && getHeight() <= 16){

         CreatePixeles2();

    }else if(getWidth() > 16 && getHeight() > 16){

         CreatePixeles();

    }else if(getWidth() > 16 && getHeight() <= 16){

            CreatePixeles3();

    } else if(getWidth() < 16 && getHeight() > 16){

           CreatePixeles4();

    }

}

void FlagImage::CreatePixeles()
{
    /*CreatePixeles:  (submuestreo puro) Se divide el total del area de la imagen
     * en una matriz de 16*16, donde cada porsion de area se le asigna
     * a una instancia de la clase PixelImage, para que determine cual
     * es el pixel de representacion del area y sea almacenado en un vector
     * de la clase FlagImage
     *
     */
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

   int co=0;
   int co1=0;

   for(int i=Height_; i<=getHeight() && co!=16; i+= Height_){

       for(int j=Width_; j<=getWidth() && co1!=16; j+=Width_){

          if(j!=getWidth()-FaulPixelesWidth-1 && i!=getHeight()-FaulPixelesHeight-1){

          PixelImage element(LastValueH, LastValueW, i, j,*Image, MatrizPixels, 1);
          MatrizLeds[contX][contY]=element;

          contX++;

          }else if(j==getWidth()-FaulPixelesWidth-1 && i!=getHeight()-FaulPixelesHeight-1){

              PixelImage element(LastValueH, LastValueW, i, j+FaulPixelesWidth,*Image, MatrizPixels, 1);
              MatrizLeds[contX][contY]=element;

              contX++;


          }
          else if(j!=getWidth()-FaulPixelesWidth-1 && i==getHeight()-FaulPixelesHeight-1){

                        PixelImage element(LastValueH, LastValueW,i+FaulPixelesHeight, j,*Image, MatrizPixels, 1);
                        MatrizLeds[contX][contY]=element;

                        contX++;


           }else if(j==getWidth()-FaulPixelesWidth-1 && i==getHeight()-FaulPixelesHeight-1){

             PixelImage element(LastValueH, LastValueW, i+FaulPixelesHeight, j+FaulPixelesWidth, *Image, MatrizPixels, 1);
             MatrizLeds[contX][contY]=element;

              contX++;


          }

          LastValueW=j;
          co1++;

       }

       co++;
       co1=0;
       contX=0;
       contY++;
       LastValueH=i;

       LastValueW=0;

   }




}

void FlagImage::CreatePixeles2()
{
    /*CreatePixeles2: (sobremuestreo puro) Se divide el total del area de la imagen
     * en una matriz de 16*16, como las areas son diminutas se asigna el mismos valor del pixel
     * hasta que el iterador sea mayor a uno, para hacer que la imagen pequeña tenga las dimensiones
     * de 16*16.
     *
     */

    float Width_=float(getWidth())/16.0;

    float Height_=float(getHeight())/16.0;

    int contX=0;

    int contY=0;

    float aux1=Height_;

    float aux2=Width_;

    int BlueValor, RedValor, GreenValor;

    for(int i=1; i<=16; i++){


        for(int j=1; j<=16; j++){


            BlueValor=(*Image).pixelColor(contX, contY).blue();
            RedValor=(*Image).pixelColor(contX, contY).red();
            GreenValor=(*Image).pixelColor(contX, contY).green();


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

            MatrizPixels->push_back(*AuxVector);

            if(aux2>=1.0){

                contX++;
                aux2=0.0;

            }

            aux2+=Width_;

           }

      if(aux1>=1.0){

          contY++;
          aux1=0.0;


      }

      contX=0;
      aux1+=Height_;

    }

}

void FlagImage::CreatePixeles3()
{
    /*CreatePixeles3: (caso combinado mayor ancho, menor alto ) Se divide el total del area de la imagen
     * en una matriz de 16*16, como las areas horizonatles son mayores, para el area vertical se asigna el mismo
     * pixel hasta que el iterador no note un cambio de pixel, se le lleva esta area de 1*n a una instacia de la clase
     * PixelImage para que determine el pixel representacion del area hasta determinar los valores de la matriz de 16*16.
     *
     */

   int Width_=getWidth()/16;

   float Height_=float(getHeight())/16.0;;

   int FaulPixelesWidth=getWidth()%16;

   int LastValueW=0;

   int contX=0;

   int contY=0;

   float aux1=0;

   if(FaulPixelesWidth!=0){

       FaulPixelesWidth+=-1;
   }

   int co=0;

   for(int i=0; i<16; i++){

       for(int j=Width_; j<=getWidth() &&co!=16; j+=Width_){

          if(j!=getWidth()-FaulPixelesWidth-1){

          PixelImage element(contY, LastValueW, contY, j, *Image, MatrizPixels,2);
          MatrizLeds[contX][contY]=element;

          contX++;

          }else if(j==getWidth()-FaulPixelesWidth-1){

              PixelImage element(contY, LastValueW, contY, getWidth()-1, *Image, MatrizPixels,2);
              MatrizLeds[contX][contY]=element;

          contX++;

          }
          LastValueW=j;
          co++;

       }

      if(aux1>=1.0){

           contY++;
           aux1=0.0;

           }
        contX=0;
        aux1+=Height_;     
        LastValueW=0;

        co=0;

   }

}

void FlagImage::CreatePixeles4()
{
    /*CreatePixeles3: (caso combinado mayor alto, menor ancho ) Se divide el total del area de la imagen
     * en una matriz de 16*16, como las areas verticales son mayores, para el area horizontal se asigna el mismo
     * pixel hasta que el iterador no note un cambio de pixel, se le lleva esta area de 1*n a una instacia de la clase
     * PixelImage para que determine el pixel representacion del area hasta determinar los valores de la matriz de 16*16.
     *
     */
   float Width_=float(getWidth())/16.0;

   int Height_=getHeight()/16;

   int FaulPixelesHeight=getHeight()%16;

   if(FaulPixelesHeight!=0){

     FaulPixelesHeight+=-1;

  }

   int LastValueH=0;

   int contX=0;

   int contY=0;

   int contX1=0;

   int contY1=0;

   float aux2=0;

   int co=0;

   for(int i=Height_; i<=getHeight() && co!=16; i+= Height_){

       for(int j=0; j<16 ; j++){

          if(i!=getHeight()-FaulPixelesHeight-1){

          PixelImage element(LastValueH, contX, i, contX, *Image, MatrizPixels,3);
          MatrizLeds[contX][contY]=element;

          }else if(i==getHeight()-FaulPixelesHeight-1){

              PixelImage element(LastValueH, contX, getHeight()-1, contX, *Image, MatrizPixels,3);
              MatrizLeds[contX][contY]=element;


          }
          if(aux2>=1.0){

              contX++;
              aux2=0.0;


          }

          aux2+=Width_;
          contX1++;

       }

        contX=0;
        contX1=0;
        LastValueH=i;
        contY1++;
        co++;

   }


}

void FlagImage::genTheTxtPixels()
{
    /*genTheTxtPixels: Utiliza el vector MatrizPixels para crear un formato
     * de un matriz de enteros de [256][3], a cadenas de strings correspondintes
     * a la representacion de la imagen transformada a 16*16 pixeles, para posteriormente
     * escribir esta informacion en el archivo que se guardara en la carpeta build del
     * proyecto con el nombre de MyFile.txt, informacion que sera llevada a Tinkercad.
     *
     */
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

    delete MatrizPixels;

    cout<<endl<<"          Exportacion de transformacion de la imagen completada."<<endl<<endl;

    cout<<"============================================================================"<<endl;

    //////////ACA PUEDE CAMBIAR EL NOMBRE Y LA RUTA AÑADIENDO DESPUES DE LA RUTA EL NOMBRE DEL ARCHIVO + .txt//////////
              escribir("MyFile.txt", MatrizLeds);



}
