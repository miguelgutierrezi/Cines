#include <iostream>

using namespace std;

struct Silla {
    int fila;
    int col;
    bool ocupada = false;
    string cliente;
};

struct Sala {
    int numero;
    Silla sillas[26][20];
};

struct Funcion {
    string hora;
    Sala sala;
};

struct Pelicula {
    string nombre;
    Funcion funciones[10];
    int cant_funciones = 0;
};

void agregar_pelicula (Pelicula peliculas[], int tam) {
    int cant_horas, cant_sillas;
    string hora, silla;
    cout<<"Ingrese el nombre de la pelicula: ";
    cin>>peliculas[tam].nombre;
    cout<<"Cuantas funciones tendra la pelicula? ";
    cin>>peliculas[tam].cant_funciones;
    for (int i=0; i<peliculas[tam].cant_funciones; i++) {
        cout<<"Ingrese el horario de la funcion No. "<<i+1<<" (Formato: hh:mm): ";
        cin>>peliculas[tam].funciones[i].hora;
    }
    cout<<"La pelicula "<<peliculas[tam].nombre<<" fue añadida al sistema"<<endl;
}

void seleccionar_pelicula (Pelicula peliculas[], int tam) {
    int peli, opcion;
    for (int i=0; i<tam; i++) {
        cout<<"\t"<<i+1<<" "<<peliculas[i].nombre<<endl;
    }
    cout<<"Ingrese el numero de la pelicula que desea consultar: ";
    cin>>peli;

    do {
        cout<<"\t1. Ver funciones disponibles"<<endl;
        cout<<"\t2. Modificar pelicula"<<endl;
        cout<<"\t3. Volver"<<endl;
        cout<<"Ingrese la opcion que desea realizar: ";
        cin>>opcion;
        switch(opcion) {
        case 1:
            cout<<"1. Comprar silla"<<endl;
            cout<<"2. Cancelar silla"<<endl;
            int seat;
            cout<<"Ingrese lo que desea realizar: ";
            cin>>seat;
            if (seat == 1) {
                for (int i=0; i<peliculas[peli-1].cant_funciones; i++) {
                    cout<<"\t\t"<<i+1<<" "<<peliculas[peli-1].funciones[i].hora<<endl;
                }
                int t;
                cout<<"Ingrese el numero de la funcion de la que quiere comprar la boleta: ";
                cin>>t;
                for (int j=0; j<26; j++) {
                    for (int k=0; k<20; k++) {
                        if (peliculas[peli-1].funciones[t-1].sala.sillas[j][k].ocupada == false) {
                            cout<<j+1<<" "<<k+1<<endl;
                        }
                    }
                }
                cout<<"Seleccione la silla que desea comprar (Ej: 1 1): "<<endl;
                int fila, col;
                cin>>fila>>col;
                peliculas[peli-1].funciones[t-1].sala.sillas[fila-1][col-1].ocupada = true;
                cout<<"Se ha comprado la silla "<<fila<<" "<<col<<endl;
            }
            if (seat == 2) {
                for (int i=0; i<peliculas[peli-1].cant_funciones; i++) {
                    cout<<"\t\t"<<i+1<<" "<<peliculas[peli-1].funciones[i].hora<<endl;
                }
                int t;
                cout<<"Ingrese el numero de la funcion de la que quiere cancelar la boleta: ";
                cin>>t;
                for (int j=0; j<26; j++) {
                    for (int k=0; k<20; k++) {
                        if (peliculas[peli-1].funciones[t-1].sala.sillas[j][k].ocupada == true) {
                            cout<<j+1<<" "<<k+1<<endl;
                        }
                    }
                }
                cout<<"Seleccione la silla que desea cancelar (Ej: 1 1): "<<endl;
                int fila, col;
                cin>>fila>>col;
                peliculas[peli-1].funciones[t-1].sala.sillas[fila-1][col-1].ocupada = false;
                cout<<"Se ha cancelado la compra de la silla "<<fila<<" "<<col<<endl;
            }
            break;

        case 2:
            cout<<"Opcion no disponible por el momento"<<endl;
            break;

        case 3:
            break;
        }
    } while(opcion == 1 || opcion == 2);
}

void eliminar_pelicula (Pelicula peliculas[], int tam) {
    int peli, opcion;
    string nombre;
    for (int i=0; i<tam; i++) {
        cout<<"\t"<<i+1<<" "<<peliculas[i].nombre<<endl;
    }
    cout<<"Ingrese el numero de la pelicula que desea eliminar: ";
    cin>>peli;

    nombre = peliculas[peli-1].nombre;

    peliculas[peli-1] = peliculas[tam-1];

    cout<<"Se ha eliminado la pelicula de nombre "<<nombre<<endl;
}

int main()
{
    int n;
    Pelicula peliculas [10];
    peliculas[0].nombre = "It";
    peliculas[1].nombre = "Halloween";
    peliculas[2].nombre = "Venom";
    int tam = 3;
    do  {
        cout<<"Cines"<<endl;
        cout<<"\t1. Agregar pelicula"<<endl;
        cout<<"\t2. Seleccionar pelicula"<<endl;
        cout<<"\t3. Eliminar pelicula"<<endl;
        cout<<"\t4. Salir"<<endl;
        cout<<"Ingrese la opcion que quiere realizar: ";
        cin>>n;
        switch(n) {
        case 1:
            agregar_pelicula(peliculas, tam);
            tam++;
            break;

        case 2:
            seleccionar_pelicula(peliculas, tam);
            break;

        case 3:
            eliminar_pelicula(peliculas, tam);
            tam--;
            break;

        case 4:
            cout<<"Gracias por utilizar nuestros servicios"<<endl;
            break;
        }
    } while (n == 1 || n == 2 || n == 3);
    return 0;
}
