#include "pedido.h"


pedido::pedido()
{
    Inicio = NULL;
    Final = NULL;
}

void pedido::ingresar_pedido(int x, std::string nombre, std::string comida) {
    Temporal = new nodo();              // crea un nuevo nodo
    Temporal->id = x;                   // asigna el valor de x al id del nodo
    Temporal->nombre_cliente = nombre;  // asigna el valor de nombre al nombre_cliente del nodo
    Temporal->tipo_comida = comida;     // asigna el valor de comida al tipo_comida del nodo
    Temporal->siguiente = NULL;         // el siguiente nodo es NULL

    if (Inicio == NULL) {               // si el inicio es NULL
        Inicio = Temporal;              // el inicio es igual al nodo temporal
        Final = Temporal;               // el final es igual al nodo temporal
    } else {
        Final->siguiente = Temporal;    // el siguiente del nodo final es igual al nodo temporal
        Final = Temporal;               // el final es igual al nodo temporal
    }
    Temporal->tiempo_inicio = std::chrono::high_resolution_clock::now(); // Iniciar el cronómetro
}


void pedido::eliminar_pedido(){
    int x; // variable para almacenar la respuesta del usuario
    if(Inicio != NULL){                                     // si el inicio no es NULL mostrar el siguiente pedido, el primero de la cola
        cout << "-------------------------------" << endl;
        cout << "Siguiente pedido: "<< endl;
        cout << "ID del pedido: " <<"\t"<<"\t"<< Inicio->id << endl;
        cout << "Nombre del cliente: " <<Inicio->nombre_cliente << endl;
        cout << "Tipo de comida: " <<"\t"<<Inicio->tipo_comida << endl;
        cout << "-------------------------------" << endl;
        cout << "Entregar pedido? 1- SI , 2- NO: " << endl;
        cin >> x;

        if (x == 1){                                              // si la respuesta es 1, entregar el pedido
            entregar_pedido();                                    // llamar a la función entregar_pedido
        } else if( x == 2){
            cout << "Pedido sigue en espera: " << endl;
        }
    } else {
        cout << "No hay pedidos en cola" << endl;
    }
}


void pedido::entregar_pedido(){
    // Detener el cronómetro
    std::chrono::high_resolution_clock::time_point tiempo_final = std::chrono::high_resolution_clock::now();

    // Calcular el tiempo transcurrido en milisegundos
    auto duracion = std::chrono::duration_cast<std::chrono::seconds>(tiempo_final - Inicio->tiempo_inicio);
    long long tiempo_transcurrido_segundos = duracion.count();

    // Convertir milisegundos a minutos y segundos
    long long minutos = tiempo_transcurrido_segundos / 60;
    long long segundos = tiempo_transcurrido_segundos % 60;

    // Mostrar el tiempo de espera total del pedido al usuario
    std::cout << "Tiempo de espera total del pedido: " <<"\t"<< minutos << " minutos y " << segundos << " segundos." << std::endl;

    Inicio = Inicio->siguiente;     // el inicio es igual al siguiente nodo
    Temporal = NULL;                // el nodo temporal es NULL
    cout << "Pedido Entregado Satisfactoriamente" << endl;
}

void pedido::mostrar_pedido(){

    if (Inicio == NULL) {
        cout << "No hay pedidos en cola" << endl;
    } else {
        Temporal = Inicio;
        while(Temporal != NULL){
            cout << "-------------------------------" << endl;
            cout << "ID del pedido: " <<"\t"<<"\t"<< Temporal->id << endl;
            cout << "Nombre del cliente: " <<Temporal->nombre_cliente << endl;
            cout << "Tipo de comida: " <<"\t"<<Temporal->tipo_comida << endl;
            // Calcular el tiempo de espera
            std::chrono::high_resolution_clock::time_point tiempo_actual = std::chrono::high_resolution_clock::now();
            auto duracion = std::chrono::duration_cast<std::chrono::seconds>(tiempo_actual - Temporal->tiempo_inicio);
            long long tiempo_espera_segundos = duracion.count();

            // Convertir segundos a minutos y segundos
            long long minutos = tiempo_espera_segundos / 60;
            long long segundos = tiempo_espera_segundos % 60;
            // Mostrar el tiempo de espera al usuario
            cout << "Tiempo de espera: " <<"\t"<< minutos << " minutos y " << segundos << " segundos." << endl;

            cout << "-------------------------------" << endl;
            Temporal = Temporal->siguiente;
        }
    }
}





pedido::~pedido()
{
}
