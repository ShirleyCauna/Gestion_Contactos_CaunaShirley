#include <iostream>
#include <cstring>

using namespace std;

struct ContactoEmail {
    char nombres[100];
    char sexo;
    int edad;
    char telefono[40];
    char email[60];
    char nacionalidad[50];
};

void agregarContacto(ContactoEmail contactos[],int &numContactos) {
    ContactoEmail nuevoContacto;

    cout<<"Ingrese nombres completos: ";
    cin.ignore();
    cin.getline(nuevoContacto.nombres,100);

    cout << "Ingrese sexo (M/F): ";
    cin >> nuevoContacto.sexo;
    
    cout<<"Ingrese edad: ";
    cin>>nuevoContacto.edad;
    cin.ignore(); 
    
    cout << "Ingrese telefono: ";
    cin.getline(nuevoContacto.telefono,20);
    
    cout<<"Ingrese email: ";
    cin.getline(nuevoContacto.email,50);
    
    cout<<"Ingrese nacionalidad: ";
    cin.getline(nuevoContacto.nacionalidad,50);

    contactos[numContactos]=nuevoContacto;
    numContactos++;
    cout<<"Contacto agregado exitosamente"<<endl;
}


int main() 
{
    ContactoEmail contactos[100]; 
    int numContactos = 0;
    int opcion;

    do {
        cout<<"\nGestion de Contactos"<<endl;
        cout<<"1. Agregar un contacto"<<endl;
        
        cin>>opcion;

        switch(opcion) {
            case 1:
                agregarContacto(contactos, numContactos);
                break;
                }
				}while(opcion != 5);

    return 0;
}