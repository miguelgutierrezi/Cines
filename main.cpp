#include <iostream>

using namespace std;

void agregar_pelicula (string peliculas[], int tam) {
    int cant_horas, cant_sillas;
    string hora, silla;
    cout<<"Ingrese el nombre de la pelicula: ";
    cin>>peliculas[tam];
    cout<<"Cuantos horarios tendra la pelicula? ";
    cin>>cant_horas;
    for (int i=0; i<cant_horas; i++) {
        cout<<"Ingrese el horario No. "<<i+1<<" (Formato: hh:mm): ";
        cin>>hora;
    }
    cout<<"Cuantas sillas tendra la pelicula? ";
    cin>>cant_sillas;
    for (int i=0; i<cant_sillas; i++) {
        cout<<"Ingrese la silla No. "<<i+1<<" (Ej: A1): ";
        cin>>silla;
    }
    cout<<"La pelicula "<<peliculas[tam]<<" fue añadida al sistema"<<endl;
}

void seleccionar_pelicula (string peliculas[], int tam) {
    int peli, opcion;
    for (int i=0; i<tam; i++) {
        cout<<"\t"<<i+1<<" "<<peliculas[i]<<endl;
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
            cout<<"Opcion no disponible por el momento"<<endl;
            break;

        case 2:
            cout<<"Opcion no disponible por el momento"<<endl;
            break;

        case 3:
            break;
        }
    } while(opcion == 1 || opcion == 2);
}

void eliminar_pelicula (string peliculas[], int tam) {
    int peli, opcion;
    string nombre;
    for (int i=0; i<tam; i++) {
        cout<<"\t"<<i+1<<" "<<peliculas[i]<<endl;
    }
    cout<<"Ingrese el numero de la pelicula que desea eliminar: ";
    cin>>peli;

    nombre = peliculas[peli-1];

    peliculas[peli-1] = peliculas[tam-1];

    cout<<"Se ha eliminado la pelicula de nombre "<<nombre<<endl;
}

int main()
{
    int n;
    string peliculas [10];
    peliculas[0] = "It";
    peliculas[1] = "Halloween";
    peliculas[2] = "Venom";
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
