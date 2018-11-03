#include <iostream>

using namespace std;

struct Cliente {
    string nombre;
    string cedula;
};

struct Silla {
    int ocupada = 0;
    string cliente;
};

struct Boleta {
    Silla silla;
    Cliente cliente;
};

void mostrar_teatro (Boleta boletas[26][20]) {
    char col;
    cout<<"\t";
    for (int i = 0; i < 20; i++) {
        col = (i+49) + '0';
        cout<<"  "<<col<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 26; i++) {
        cout<<i + 1<<"\t";
        for (int j = 0; j < 20; j++) {
            cout<<"| "<<boletas[i][j].silla.ocupada<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Cliente clientes[520];
    Boleta boletas[26][20];
    int cant_clientes = 0;
    int n;
    do  {
        cout<<"Cines"<<endl;
        cout<<"\t1. Mostrar Teatro"<<endl;
        cout<<"\t2. Mostrar Clientes"<<endl;
        cout<<"\t3. Reservar Boleta"<<endl;
        cout<<"\t4. Comprar Boleta"<<endl;
        cout<<"\t5. Cancelar Compra"<<endl;
        cout<<"\t6. Salir"<<endl;
        cout<<"Ingrese la opcion que quiere realizar: ";
        cin>>n;
        switch(n) {
        case 1:
            mostrar_teatro(boletas);
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            cout<<"Gracias por utilizar nuestros servicios"<<endl;
            break;
        }
    } while (n == 1 || n == 2 || n == 3 || n == 4 || n == 5);
    return 0;
}
