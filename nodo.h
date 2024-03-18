#ifndef PROYECTO_PROGRAMACION3_NODO_H
#define PROYECTO_PROGRAMACION3_NODO_H
#include <iostream>
#include <chrono>
using namespace std;

class nodo {
    public:
        int id;
        string nombre_cliente;
        string tipo_comida;
        std::chrono::high_resolution_clock::time_point tiempo_inicio; // Use std::chrono here
        std::chrono::high_resolution_clock::time_point tiempo_final;
        nodo *siguiente;
        nodo();
        ~nodo();
};


#endif //PROYECTO_PROGRAMACION3_NODO_H
