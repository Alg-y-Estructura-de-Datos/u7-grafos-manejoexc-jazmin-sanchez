/*En una ciudad, se está implementando un sistema de gestión de rutas de transporte entre
distintas estaciones. Cada estación se representa como un nodo, y las rutas directas entre
estaciones se representan como aristas. Tu tarea es diseñar este sistema de rutas utilizando
grafos, donde los ciudadanos puedan interactuar con el sistema para realizar varias
operaciones.
1. Agregar estaciones: El sistema debe permitir agregar nuevas estaciones al mapa. Cada
estación tiene un nombre único.
2. Conexión de rutas entre estaciones: Las estaciones pueden estar conectadas
mediante rutas directas. El sistema debe permitir agregar una conexión entre dos
estaciones, indicando que existe una ruta entre ellas.
3. Eliminar estaciones: Si una estación deja de funcionar, debe ser posible eliminarla del
sistema. Al eliminar una estación, también deben eliminarse todas las rutas que
conectan a dicha estación.
4. Eliminar rutas: En caso de que una ruta deje de ser operativa entre dos estaciones, el
sistema debe poder eliminar esa conexión sin afectar al resto de las estaciones.
5. Consulta de conectividad: Los ciudadanos podrán consultar si existe una ruta directa
entre dos estaciones específicas. El sistema debe devolver si esas estaciones están
conectadas por una ruta.
6. Verificar si una estación existe: El sistema debe proporcionar una función para
verificar si una estación específica existe en el mapa.
7. Imprimir el mapa completo: Finalmente, el sistema debe poder imprimir un listado de
todas las estaciones y sus conexiones directas, mostrando el estado actual de todas
las rutas en la ciudad.*/
#include <iostream>
#include <string>
#include "Grafos/Grafo.h"

using namespace std;

int main() {
    Grafo<string> sistemaRutas;
    int opcion;
    string estacion1, estacion2;

    do {
        cout << "1. Agregar estacion\n";
        cout << "2. Agregar ruta\n";
        cout << "3. Eliminar estacion\n";
        cout << "4. Eliminar ruta\n";
        cout << "5. Consultar conectividad\n";
        cout << "6. Verificar existencia de estacion\n";
        cout << "7. Imprimir mapa de rutas\n";
        cout << "0. Salir\n";
        cout << "Elija una opcion: ";

        cin >> opcion;
        cin.clear(); // Limpia el estado de error
        cin.ignore(); // Ignora el resto de la línea

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre de la estacion: ";

                getline(cin, estacion1);

                sistemaRutas.agregarNodo(estacion1);
                break;

            case 2:
                cout << "Ingrese la estacion de origen: ";
                getline(cin, estacion1);
                cout << "Ingrese la estacion de destino: ";
                getline(cin, estacion2);
                sistemaRutas.agregarArista(estacion1, estacion2);
                break;

            case 3:
                cout << "Ingrese el nombre de la estacion a eliminar: ";
                getline(cin, estacion1);
                sistemaRutas.eliminarNodo(estacion1);
                break;

            case 4:
                cout << "Ingrese la estacion de origen: ";
                getline(cin, estacion1);
                cout << "Ingrese la estacion de destino: ";
                getline(cin, estacion2);
                sistemaRutas.eliminarArista(estacion1, estacion2);
                break;

            case 5:
                cout << "Ingrese la estacion de origen: ";
                getline(cin, estacion1);
                cout << "Ingrese la estacion de destino: ";
                getline(cin, estacion2);
                if (sistemaRutas.estanConectados(estacion1, estacion2)) {
                    cout << "Las estaciones estan conectadas.\n";
                } else {
                    cout << "Las estaciones NO estan conectadas.\n";
                }
                break;

            case 6:
                cout << "Ingrese el nombre de la estacion a verificar: ";
                getline(cin, estacion1);
                if (sistemaRutas.buscarNodo(estacion1)) {
                    cout << "La estacion existe.\n";
                } else {
                    cout << "La estacion NO existe.\n";
                }
                break;

            case 7:
                cout << "Mapa de rutas:\n";
                sistemaRutas.imprimir();
                break;

            case 0:
                cout << "Saliendo del sistema.\n";
                break;

            default:
                cout << "Opcion no valida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}