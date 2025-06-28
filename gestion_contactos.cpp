#include <iostream>
#include <cstring>

using namespace std;

struct ContactoEmail {
    char nombres[100];
    char sexo;
    int edad;
    char telefono[30];
    char email[50];
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
    cout<<"Contacto agregado exitosamente.\n";
}

void eliminarContacto(ContactoEmail contactos[], int &numContactos) {
    if (numContactos == 0) {
        cout << "No hay contactos para eliminar.\n";
        return;
    }

    int indice;
    cout << "Ingrese el indice del contacto a eliminar (0 a " << numContactos - 1 << "): ";
    cin >> indice;

    if (indice < 0 || indice >= numContactos) {
        cout << "Índice inválido.\n";
        return;
    }

    for (int i = indice; i < numContactos - 1; i++) {
        contactos[i] = contactos[i + 1];
    }
    numContactos--;
    cout << "Contacto eliminado exitosamente.\n";
}

int main() {
    ContactoEmail contactos[100]; 
    int numContactos = 0;
    int opcion;

    do {
        cout << "Gestion de Contactos"<<endl;
        cout << "1. Agregar un contacto"<<endl;
        cout << "2. Eliminar un contacto"<<endl;
        cout << "Ingrese una opcion: "<<endl;
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarContacto(contactos, numContactos);
                break;
            case 2:
                eliminarContacto(contactos, numContactos);
				break;   
				 }
    } while(opcion != 5);

    return 0;
}
