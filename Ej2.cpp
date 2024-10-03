/*En una comisión de un colegio o universidad, los profesores o estudiantes son nodos, y las
colaboraciones o relaciones entre ellos, como trabajar en un proyecto, son aristas. Este grafo
puede ser dirigido si una colaboración tiene una jerarquía (por ejemplo, un profesor dirige a
varios estudiantes).
Descripción del problema:
● Cada persona en la comisión es un nodo en el grafo.
● Las colaboraciones o trabajos en conjunto son las aristas.
● Puedes buscar si dos personas están colaborando en algún proyecto.
● Agregar o eliminar miembros y colaboraciones.
● Mostrar todas las relaciones de colaboración dentro de la comisión.
OPERACIONES:
● Agregar Miembro: Añadir un nodo al grafo representando a un nuevo miembro de la
comisión.
● Agregar Colaboración: Crear una arista dirigida entre dos nodos (miembros) para
representar una relación de trabajo o supervisión.
● Eliminar Colaboración: Eliminar la relación de trabajo entre dos miembros.
● Buscar Miembro: Buscar un miembro en el grafo de la comisión.
● Imprimir Comisión: Mostrar todos los miembros y sus relaciones de trabajo.
*/
#include <iostream>
#include "Grafos/Grafo.h"

using namespace std;

int main() {
    Grafo<string> comision;

    int opcion;
    string miembro, colaborador;

    do {
        cout << "\n--- Comision de Colegio/Universidad ---\n";
        cout << "1. Agregar miembro\n";
        cout << "2. Establecer colaboracion\n";
        cout << "3. Buscar miembro\n";
        cout << "4. Eliminar miembro\n";
        cout << "5. Mostrar estructura de la comision\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del miembro: ";
                cin >> miembro;
                try{
                    comision.agregarNodo(miembro);
                }catch(int e){
                    cout << "ya existe";
                }
            break;

            case 2:
                cout << "Ingrese el nombre del miembro: ";
                cin >> miembro;
                
                cout << "Ingrese el nombre del colaborador: ";
                cin >> colaborador;

                comision.agregarArista(miembro, colaborador);
            break;

            case 3:
                cout << "Ingrese el nombre del miembro a buscar: ";
                cin >> miembro;

                if (comision.buscarNodo(miembro)) {
                    cout << "El miembro " << miembro << " esta en la comision.\n";
                } else {
                    cout << "Miembro no encontrado.\n";
                }
            break;

            case 4:
                cout << "Ingrese el nombre del miembro a eliminar: ";
                cin >> miembro;
                try{
                    comision.eliminarNodo(miembro);
                }catch(int e){
                    cout << "No encontrado";
                }

            break;

            case 5:
                cout << "Estructura de la comision:\n";
                comision.imprimir();
            break;

            case 6:
                cout << "Saliendo...\n";
            break;

            default:
                cout << "Opción no valida.\n";
        }
    } while (opcion != 6);

    return 0;
}