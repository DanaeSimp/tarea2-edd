#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "DeBlock.cpp"  // Incluye la implementación del TDA DeBlock

int main() {
    //archivo de entrada
    std::ifstream inputFile("pruebas.txt");
    if (!inputFile) {    //si no puede abrirlo retorna 1
        std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    int tam_ori, tam_blo;
    inputFile >> tam_ori >> tam_blo;

    tElem* elems = new tElem[tam_ori];
    for (int i = 0; i < tam_ori; i++) {
        inputFile >> elems[i];
    }

    DeBlock db(elems, tam_ori, tam_blo);

    int cant_op;
    inputFile >> cant_op;

    std::string line;
    std::getline(inputFile, line); // Leer línea en blanco después de q
    for (int i = 0; i < cant_op; i++) {
        std::getline(inputFile, line);
        std::istringstream iss(line);
        std::string operation;
        iss >> operation;
        
        if (operation == "G") {
            int pos;
            iss >> pos;
            tElem value = db.get_value(pos);
            std::cout << value << std::endl;
        } else if (operation == "I") {
            int pos, value;
            iss >> pos >> value;
            int a = db.insert(pos, value);

            if (a == 0){
                std::cout << "Error al insertar el elemento" << std::endl;    
            }
            
            std::cout << a << std::endl;
        } else if (operation == "L") {
            int len = db.length();
            std::cout << len << std::endl;
        }
    }

    delete[] elems;
    inputFile.close();

    return 0;
}
