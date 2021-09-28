#include <iostream>
#include <fstream>

using namespace std;

void escribir(string nombre, string contenido){
    /*escribir: Funcion que recibe el nombre de un archivo, una cadena de caracteres
     *          y escribe ese archivo con ese contenido.
     *
     * Parametro: Nombre de un archivo, y una cadena de caracteres
     *
     * Retorno: Ninguno.
     *
     */

    ofstream archivo;
    archivo.open(nombre);

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }

    archivo<<contenido;
    archivo.close();
}


