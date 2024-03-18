#include <iostream>
#include "nodo.h"
#include <stdexcept>
#include "pedido.h"
using namespace std;

pedido p;

int main(int argc, char** argv) {
    int op, x;
    string nombre, comida;
    do{
        cout<<"--------------------------------------------"<<endl;
        cout<<"|                                          |"<<endl;
        cout<<"|         Sistema Pedidos a Cocina         |"<<endl;
        cout<<"|                                          |"<<endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"1- Ingresar pedido a cocina"<<endl;
        cout<<"2- Entregar siguiente pedido en espera"<<endl;
        cout<<"3- Mostrar pedidos en espera"<<endl;
        cout<<"0- salir"<<endl;
        cout<<"--------------------------------------------"<<endl;

        cin>>op;

        switch(op){
            case 1:
                cout << "Ingrese el ID del combo: "<<endl;
                cin>>x;
                cout << "Ingrese el nombre del cliente: "<<endl;
                cin.ignore();
                getline(cin, nombre);
                cout<<"Ingrese el nombre del combo: "<<endl;
                getline(cin, comida);
                p.ingresar_pedido(x, nombre, comida);
                break;
            case 2:
                p.eliminar_pedido();
                break;
            case 3:
                p.mostrar_pedido();
                break;
            case 0:
                break;
            default:
                cout<<"Opcion no valida"<<endl;
        }
    }while(op != 0);
    return 0;
}

