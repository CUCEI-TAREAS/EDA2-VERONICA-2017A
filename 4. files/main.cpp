#include <iostream>
#include <fstream>

#define NAMEFILE "archivo.txt"
using namespace std;

int main() {

    cout << "Creando archivo!" << endl;
    ofstream myfile (NAMEFILE);


    if (myfile.is_open()) {
        cout << "Escribiendo en el archivo" << endl;
        myfile << "Hola Mundo .\n";

        cout << "Cerrando el archivo" << endl;
        myfile.close();
    } else cout << "No se pudo abrir el archivo";

    string line;
    cout << "Abriendo el archivo" << endl;
    ifstream myfile2(NAMEFILE);

    cout << "Leyendo el archivo :" << endl;
    while ( getline (myfile2,line) )
        cout << line << '\n';

    cout << "\nFin de lectura del archivo" << endl;
    cout << "Cerrando el archivo" << endl;
    myfile.close();

    return 0;
}
