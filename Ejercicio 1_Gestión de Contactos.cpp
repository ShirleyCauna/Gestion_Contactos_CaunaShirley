/* 1. Gesti�n de Contactos
Crear una estructura llamada contactoEmail que tenga las siguientes caracter�sticas: nombres completos,
sexo, edad, tel�fono, email, nacionalidad
El programa debe constar de un men� que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com,
outlook.com, yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecuci�n continuamente hasta que usuario indique que desea salir del
mismo.*/

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
        cout << "�ndice inv�lido.\n";
        return;
    }

    for (int i = indice; i < numContactos - 1; i++) {
        contactos[i] = contactos[i + 1];
    }
    numContactos--;
    cout << "Contacto eliminado exitosamente.\n";
}
void mostrarContactos(const ContactoEmail contactos[], int numContactos) {
    if (numContactos == 0) {
        cout << "No hay contactos para mostrar.\n";
        return;
    }

    for (int i = 0; i < numContactos; i++) {
        cout << "Contacto " << i << ":\n";
        cout << "Nombres : " << contactos[i].nombres<< endl;
        cout << "Sexo: "<<contactos[i].sexo<<endl;
        cout << "Edad: "<<contactos[i].edad<<endl;
        cout << "Tel�fono: "<<contactos[i].telefono<<endl;
        cout << "Email: "<<contactos[i].email<<endl;
        cout << "Nacionalidad: "<<contactos[i].nacionalidad<<endl;
        
    }
}
void mostrarContactosOrdenadosPorDominio(ContactoEmail contactos[], int numContactos) {
    if (numContactos == 0) {
        cout << "No hay contactos para mostrar.\n";
        return;
    }

    for (int i = 0; i < numContactos - 1; i++) {
        for (int j = i + 1; j < numContactos; j++) {
            char *dominioA = strchr(contactos[i].email, '@');
            char *dominioB = strchr(contactos[j].email, '@');

            if (dominioA && dominioB) {
                if (strcmp(dominioA, dominioB) > 0) {
                    ContactoEmail temp = contactos[i];
                    contactos[i] = contactos[j];
                    contactos[j] = temp;
                }
            }
        }
    }

    mostrarContactos(contactos, numContactos);
}


int main() {
    ContactoEmail contactos[100]; 
    int numContactos = 0;
    int opcion;

    do {
        cout << "Gestion de Contactos"<<endl;
        cout << "1. Agregar un contacto"<<endl;
        cout << "2. Eliminar un contacto"<<endl;
        cout << "3. Mostrar listado general de contactos"<<endl;
         cout << "4. Mostrar listado de contactos ordenado por servidor de correo"<<endl;
         cout << "5. Salir"<<endl;
        cout << "Ingrese una opcion: "<<endl;
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarContacto(contactos, numContactos);
                break;
            case 2:
                eliminarContacto(contactos, numContactos);
				break;  
			case 3:
                mostrarContactos(contactos, numContactos);
                break;	
			case 4:
                mostrarContactosOrdenadosPorDominio(contactos, numContactos);
                break;
				 default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;   
				 }
    } while(opcion != 5);

    return 0;
}
