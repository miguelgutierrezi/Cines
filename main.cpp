#include <iostream>

using namespace std;

int main()
{
    int n;
    do  {
        cout<<"Cines"<<endl;
        cout<<"\t1. Agregar pel�cula"<<endl;
        cout<<"\t2. Seleccionar pel�cula"<<endl;
        cout<<"\t3. Eliminar pel�cula"<<endl;
        cout<<"\t4. Salir"<<endl;
        cout<<"Ingrese la opci�n que quiere realizar: ";
        cin>>n;
        switch(n) {
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            cout<<"Gracias por utilizar nuestros servicios"<<endl;
            break;
        }
    } while (n == 1 || n == 2 || n == 3);
    return 0;
}
