#ifndef PROYECTO_PROGRAMACION3_PEDIDO_H
#define PROYECTO_PROGRAMACION3_PEDIDO_H
#include "nodo.h"
#include <iostream>
using namespace std;

class pedido {
    public:
        int id_Orden;
        nodo *Inicio, *Final, *Temporal;
        void ingresar_pedido(int x, string nombre, string comida);
        void eliminar_pedido();
        void mostrar_pedido();
        void entregar_pedido();
        pedido();
        ~pedido();
    protected:
};


#endif //PROYECTO_PROGRAMACION3_PEDIDO_H
