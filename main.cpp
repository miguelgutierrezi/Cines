#include <iostream>

using namespace std;

struct Cliente {
    string nombre = "";
    string cedula = "";
};

struct Boleta {
    char ocupada = 'L';
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
            cout<<"| "<<boletas[i][j].ocupada<<" ";
        }
        cout<<endl;
    }
}

void agregar_cliente (Cliente clientes[], int &cant_clientes, string nombre, string cedula){
    bool existe = false;
    for (int i=0; i<=cant_clientes; i++) {
        if (clientes[i].nombre == nombre && clientes[i].cedula == cedula) {
            existe = true;
        }
    }

    if (existe == false) {
        clientes[cant_clientes].nombre = nombre;
        clientes[cant_clientes].cedula = cedula;
        cant_clientes++;
    }
}

void eliminar_cliente (Cliente clientes[], int &cant_clientes, string nombre, string cedula){

    int pos, cant = 0;
    for (int i = 0; i <= cant_clientes; i++) {
        if (clientes[i].nombre == nombre && clientes[i].cedula == cedula) {
            pos = i;
            cant++;
        }
    }
    if (cant >= 2) {
        for (int j = pos; j <= cant_clientes; j++) {
            clientes[j] = clientes[j + 1];
        }
        cant_clientes--;
    }
}

void mostrar_clientes (Cliente clientes[], int cant_clientes) {
    for (int i = 0; i < cant_clientes; i++) {
        cout<<"Nombre: "<<clientes[i].nombre<<endl;
        cout<<"Cedula: "<<clientes[i].cedula<<endl;
        cout<<endl;
    }
}

bool reservar_boleta (Boleta boletas[26][20]){
    bool libre = false;
    string nombre, cedula;
    int fila, col;
    char columna;
    cout<<"Ingrese el nombre del cliente: ";
    cin>>nombre;
    cout<<"Ingrese la cedula del cliente: ";
    cin>>cedula;
    cout<<"Ingrese el numero de fila de la silla que quiere reservar: ";
    cin>>fila;
    cout<<"Ingrese la letra de la columna de la silla que quiere reservar: ";
    cin>>columna;
    col = (columna - '0') - 49;
    cout<<"Boleta: "<<boletas[fila-1][col].ocupada<<endl;
    if (boletas[fila-1][col].ocupada=='L') {
        boletas[fila-1][col].cliente.nombre = nombre;
        boletas[fila-1][col].cliente.cedula = cedula;
        boletas[fila-1][col].ocupada = 'R';
        cout<<"Boleta reservada exitosamente"<<endl;
        return true;
    }
    if (boletas[fila-1][col].ocupada=='R') {
        cout<<"La boleta se encuentra reservada, intente mas tarde"<<endl;
        return false;
    }
    if (boletas[fila-1][col].ocupada=='C') {
        cout<<"La boleta se encuentra vendida"<<endl;
        return false;
    }
}

bool comprar_boleta (Boleta boletas[26][20], Cliente clientes[], int &cant_clientes){
    bool libre = false;
    string nombre, cedula;
    int fila, col;
    char columna;
    cout<<"Ingrese el nombre del cliente: ";
    cin>>nombre;
    cout<<"Ingrese la cedula del cliente: ";
    cin>>cedula;
    cout<<"Ingrese el numero de fila de la silla que quiere reservar: ";
    cin>>fila;
    cout<<"Ingrese la letra de la columna de la silla que quiere reservar: ";
    cin>>columna;
    col = (columna - '0') - 49;
    cout<<"Boleta: "<<boletas[fila-1][col].ocupada<<endl;
    if (boletas[fila-1][col].ocupada=='L') {
        boletas[fila-1][col].cliente.nombre = nombre;
        boletas[fila-1][col].cliente.cedula = cedula;
        boletas[fila-1][col].ocupada = 'C';
        agregar_cliente(clientes, cant_clientes, nombre, cedula);
        cout<<"Boleta comprada exitosamente"<<endl;
        return true;
    }
    if (boletas[fila-1][col].ocupada=='R') {
        if (boletas[fila-1][col].cliente.nombre == nombre && boletas[fila-1][col].cliente.cedula == cedula) {
            boletas[fila-1][col].ocupada = 'C';
            agregar_cliente(clientes, cant_clientes, nombre, cedula);
            cout<<"Boleta comprada exitosamente"<<endl;
        }
        else {
            cout<<"La boleta se encuentra reservada, intente mas tarde"<<endl;
        }
        return false;
    }
    if (boletas[fila-1][col].ocupada=='C') {
        cout<<"La boleta se encuentra vendida"<<endl;
        return false;
    }
}

void cancelar_compra (Boleta boletas[26][20], Cliente clientes[], int &cant_clientes){
    int fila, col;
    char columna;
    cout<<"Ingrese el numero de fila de la silla de la compra que quiere cancelar: ";
    cin>>fila;
    cout<<"Ingrese la letra de la columna de la silla de la compra que quiere cancelar: ";
    cin>>columna;
    col = (columna - '0') - 49;
    cout<<"Boleta: "<<boletas[fila-1][col].ocupada<<endl;
    if (boletas[fila-1][col].ocupada=='L') {
        cout<<"La boleta no ha sido vendida ni reservada"<<endl;

    }
    if (boletas[fila-1][col].ocupada=='R') {
        boletas[fila-1][col].ocupada = 'L';
        eliminar_cliente(clientes, cant_clientes, boletas[fila-1][col].cliente.nombre, boletas[fila-1][col].cliente.cedula);
        boletas[fila-1][col].cliente.nombre = "";
        boletas[fila-1][col].cliente.cedula = "";
        cout<<"Se ha cancelado la reserva, y el cliente ha sido eliminado del sistema"<<endl;
    }
    if (boletas[fila-1][col].ocupada=='C') {
        boletas[fila-1][col].ocupada = 'L';
        eliminar_cliente(clientes, cant_clientes, boletas[fila-1][col].cliente.nombre, boletas[fila-1][col].cliente.cedula);
        boletas[fila-1][col].cliente.nombre = "";
        boletas[fila-1][col].cliente.cedula = "";
        cout<<"Se ha cancelado la compra, y el cliente ha sido eliminado del sistema"<<endl;
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
            mostrar_clientes(clientes, cant_clientes);
            break;

        case 3:
            reservar_boleta(boletas);
            break;

        case 4:
            comprar_boleta(boletas, clientes, cant_clientes);
            break;

        case 5:
            cancelar_compra(boletas, clientes, cant_clientes);
            break;

        case 6:
            cout<<"Gracias por utilizar nuestros servicios"<<endl;
            break;
        }
    } while (n == 1 || n == 2 || n == 3 || n == 4 || n == 5);
    return 0;
}
