#include <iostream>
using namespace std;

// Definimos la estructura Nodo
struct Nodo {
    int valor;          // Dato del nodo
    Nodo* siguiente;    // Apuntador al siguiente nodo

    Nodo(int v) : valor(v), siguiente(nullptr) {}  // Constructor para inicializar el nodo
};

// Definimos la clase ListaCircularSimple
class ListaCircularSimple {
private:
    Nodo* cabeza;  // Apuntador al primer nodo

public:
    // Constructor
    ListaCircularSimple() : cabeza(nullptr) {}

    // Método para agregar al inicio
    void agregarInicio(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevoNodo;
            cabeza->siguiente = cabeza;  // Apunta a sí mismo, formando el ciclo
        } else {
            Nodo* actual = cabeza;
            // Recorre hasta el último nodo
            while (actual->siguiente != cabeza) {
                actual = actual->siguiente;
            }
            // Inserta el nuevo nodo al inicio
            nuevoNodo->siguiente = cabeza;
            actual->siguiente = nuevoNodo;
            cabeza = nuevoNodo;
        }
    }

    // Método para agregar al final
    void agregarFinal(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevoNodo;
            cabeza->siguiente = cabeza;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != cabeza) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
            nuevoNodo->siguiente = cabeza;
        }
    }

    // Método para agregar en el medio (después de una posición específica)
    void agregarEnMedio(int valor, int posicion) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza || posicion == 0) {
            agregarInicio(valor);
        } else {
            Nodo* actual = cabeza;
            int indice = 0;
            while (indice < posicion - 1 && actual->siguiente != cabeza) {
                actual = actual->siguiente;
                indice++;
            }
            nuevoNodo->siguiente = actual->siguiente;
            actual->siguiente = nuevoNodo;
        }
    }

    // Método para imprimir la lista
    void imprimir() {
        if (!cabeza) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo* actual = cabeza;
        do {
            cout << actual->valor << " ";
            actual = actual->siguiente;
        } while (actual != cabeza);
        cout << endl;
    }

    // Destructor para liberar memoria
    ~ListaCircularSimple() {
        if (cabeza) {
            Nodo* actual = cabeza;
            do {
                Nodo* siguiente = actual->siguiente;
                delete actual;
                actual = siguiente;
            } while (actual != cabeza);
        }
    }
};

// Ejemplo de uso
int main() {
    ListaCircularSimple lista;

    lista.agregarInicio(10);
    lista.agregarInicio(20);
    lista.agregarFinal(30);
    lista.agregarEnMedio(25, 2);

    lista.imprimir();  // Salida: 20 10 25 30

    return 0;
}
