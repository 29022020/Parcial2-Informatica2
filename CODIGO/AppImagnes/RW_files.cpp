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


string leer(string nombre){
    /*leer: Funcion que recibe el nombre de un archivo, lo lee, y retorna como un string.
     *
     * Parametro: Nombre de un archivo.
     *
     * Retorno: Una cadena de caracteres que correspoonde a el contenido del archivo.
     *
     * Ej:  archivo.txt->string: Cadena de caracter.
     *                           1. First.
     *                           2. Second.
     *                           3. Third
     */

    string contenido;
    string linea;
    ifstream archivo;

    archivo.open(nombre);
    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }

    while (!archivo.eof()) {

        getline(archivo,linea);
        contenido.append(linea+"\n");
    }
    archivo.close();
    return contenido;
}
