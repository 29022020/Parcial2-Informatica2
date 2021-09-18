#include <iostream>

using namespace std;
void imprimirleds(int asientos[8][8]);
void ingresardatos(int matriz[8][8]);
void ingresardatos2(int matriz[][8][8], int n);
void imprimirleds2(int asientos[][8][8], int n);
void publik(void);

int main()
{
    int inicializar[8][8]={{1, 1 ,1 ,1, 1, 1, 1, 1}, {1, 1 ,1 ,1, 1, 1, 1, 1}, {1, 1 ,1 ,1, 1, 1, 1, 1}, {1, 1 ,1 ,1, 1, 1, 1, 1}, {1, 1 ,1 ,1, 1, 1, 1, 1}, {1, 1 ,1 ,1, 1, 1, 1, 1}, {1, 1 ,1 ,1, 1, 1, 1, 1}, {1, 1 ,1 ,1, 1, 1, 1, 1}};
    int borrar[8][8]={{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
    int matriz[8][8]={};
    int N;


     bool band=true;

    cout << "-------------------------------------------------"<<endl;
    cout << "|      BIENVENIDO AL GRAFICADOR DE LEDS 8X8     |"<<endl;

         while(band){

         cout << "--------------------------------------------------"<<endl;
         cout << "|                    MENU.                       |"<<endl;
         cout << "--------------------------------------------------"<<endl;
         cout << "1. Verificar funcionamiento de leds. "<<endl;
         cout << "2. Ingresar un patron para mostrarlo en la matriz. "<<endl;
         cout << "3. Ingresar varios patrones para ser mostrado en distintos intervalos de tiempo que debe ingresar. "<<endl;
         cout << "4. Salir del programa. "<<endl;


         cout << "Ingresa una opcion: ";
         cin >> N;

         switch (N) {

         case 1:
             cout << "-----------------------------------------------------"<<endl;
             cout << "       VERIFICACION DE LA MATRIZ DE LEDS."<<endl;
             cout << "-----------------------------------------------------"<<endl;

             imprimirleds(inicializar);
             break;
         case 2:
             cout << "-----------------------------------------------------"<<endl;
             cout << "INGRESA TU PATRON PARA MOSTRARLO EN LA MATRIZ DE LEDS."<<endl;
             cout << "-----------------------------------------------------"<<endl;
              ingresardatos(matriz);
              imprimirleds(matriz);


             break;
         case 3:
             cout << "--------------------------------------------------------------"<<endl;
             cout << "INGRESA LOS PATRONES QUE DESEES Y EL INTERVALO PARA MOSTRARLOS"<<endl;
             cout << "--------------------------------------------------------------"<<endl;

             publik();


             break;

         case 4:
             cout << "-------------------------------------------------"<<endl;
             cout << "       GRACIAS POR USAR NUESTRO SERVICIO."<<endl;
             cout << "-------------------------------------------------"<<endl;


            band =false;
             break;
         default:
             cout << "-------------------------------------------------"<<endl;
             cout << "                 DATOS INVALIDOS"<<endl;
             cout << "-------------------------------------------------"<<endl;



     }
     }
    return 0;
}


void publik(void){

    int N=0, n=0;

    cout << "Ingrese el numero de patrones: ";
    cin >> N;

    cout << "Ingrese el tiempo en (segundos) entre un patron y otro: ";
    cin >> n;

    int publik[N][8][8]={};

    for(int i=0; i<N; i++){

          ingresardatos2(publik, i);


    }
    for (int j=0; j<N; j++){
        for (int k=1; k<=n; k++){

        cout << k << " segundo."<<endl;

        }
        imprimirleds2(publik, j);
    }




}
void ingresardatos2(int matriz[][8][8], int n){


  bool band=true;
  cout << "Ingrese cada fila de su patron, donde un 0 es un led apagado, y un 1 es un led prendido, ingrese un Byte representando una fila."<<endl;

  unsigned long int byte;
  int bit, A=1, k=0;

  while(band){


    cout <<A<< ". Ingrese un Byte: "<<endl;
    cin >> byte;
    cout <<endl;

    for (int i=7; i>=0 ;i--){
           bit=byte%10;


             matriz[n][k][i]=bit;
             byte/=10;


           }

    if(A==8){
    band=false;
    }
    A++;
    k++;

  }


}

void ingresardatos(int matriz[8][8]){


  bool band=true;
  cout << "Ingrese cada fila de su patron, donde un 0 es un led apagado, y un 1 es un led prendido, ingrese un Byte representando una fila."<<endl;

  unsigned long int byte;
  int bit, A=1, k=0;

  while(band){


    cout <<A<< ". Ingrese un Byte: "<<endl;
    cin >> byte;
    cout <<endl;

    for (int i=7; i>=0 ;i--){
           bit=byte%10;



             matriz[k][i]=bit;
             byte/=10;


           }

    if(A==8){
    band=false;
    }
    A++;
    k++;

  }


}

void imprimirleds(int asientos[8][8]){


             for (int k=1; k<=17; k++){

                     if (k!=17){

                     cout << "- ";

                     }
                     else{

                       cout << "-"<<endl;

                     }
                 }

             for (int j=0; j<8; j++){


                 for (int i=0; i<8; i++){

                         if (i==0 ){

                         cout << "| "<<asientos[j][i]<<" | ";

                         }
                         else{
                            if(i==7){

                             cout <<  asientos[j][i]<<" | "<<endl;


                            }
                            else{

                                cout <<  asientos[j][i]<<" | ";

                            }

                         }
                     }

                 for (int k=1; k<=17; k++){

                         if (k!=17){

                         cout << "- ";

                         }
                         else{

                           cout << "-"<<endl;

                         }
                     }

                }

}

void imprimirleds2(int asientos[][8][8], int n){


             for (int k=1; k<=17; k++){

                     if (k!=17){

                     cout << "- ";

                     }
                     else{

                       cout << "-"<<endl;

                     }
                 }

             for (int j=0; j<8; j++){


                 for (int i=0; i<8; i++){

                         if (i==0 ){

                         cout << "| "<<asientos[n][j][i]<<" | ";

                         }
                         else{
                            if(i==7){

                             cout <<  asientos[n][j][i]<<" | "<<endl;


                            }
                            else{

                                cout <<  asientos[n][j][i]<<" | ";

                            }

                         }
                     }

                 for (int k=1; k<=17; k++){

                         if (k!=17){

                         cout << "- ";

                         }
                         else{

                           cout << "-"<<endl;

                         }
                     }

                }

}
