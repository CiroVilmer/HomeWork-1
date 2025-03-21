#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <memory>

/*Cree el struct nodo para cada elemento de la lista. Tiene un dato y un puntero al siguiente nodo. También hice un struct para la lista enlazada
  con un unique pointer head, y un puntero a un tail, con un size que dice el largo de la lista.

  En general solamente estoy implentando las funciones que se piden utilizando smart pointers.

  En las funciones de push_front y push_back hacemos el cambio del ownership para poder insertar elementos al inicio y al final.
  En la función insert, si la posición es mayor al tamaño de la lista, insertamos al final. Si la posición es 0, insertamos al principio. En otro caso
  recorremos la lista hasta la posición anterior a la que queremos insertar y hacemos el cambio del ownership para insertar el nodo en la posición deseada.

  En erase, si la posición es 0, eliminamos el primer nodo con la función delete_front, que unicamente cambia el ownership del head, del primer nodo al segundo.
  Si la posición es mayor o igual al tamaño de la lista, eliminamos el último nodo. Cómo estamos trabajando con una lista simplemente enlazada, 
  para poder hacer esto recorremos la lista hasta el penúltimo nodo y hacemos que su puntero al siguiente nodo sea nullptr.
  En otro caso, recorremos la lista hasta la posición anterior a la que queremos eliminar y hacemos el cambio del ownership para eliminar el nodo en la posición deseada.
  
  Por último, tenemos print_list para imprimir la lista y test_lista_enlazada para probar las funciones de la lista enlazada.
*/


struct nodo {
    int dato;
    unique_ptr<nodo> sig;
};

struct lista_enlazada {
    unique_ptr<nodo> head;
    nodo* tail;
    int size;
};

/* Crea un nodo con el valor pasado por parámetro */
unique_ptr<nodo> create_node(int value) {
    unique_ptr<nodo> new_node = make_unique<nodo>();
    new_node->dato = value;
    new_node->sig = nullptr;
    return new_node;
}

/* Inicializa la lista enlazada */
void init_lista(lista_enlazada* lista) {
    lista->head = nullptr;
    lista->tail = nullptr;
    lista->size = 0;
}

/* Agrega un nodo al principio de la lista */
void push_front(lista_enlazada* lista, unique_ptr<nodo> node) {
    if (!lista->head) {
        lista->head = move(node);
        lista->tail = lista->head.get();
    } else {
        node->sig = move(lista->head);
        lista->head = move(node);
    }
    lista->size++;
}

/* Agrega un nodo al final de la lista */
void push_back(lista_enlazada* lista, unique_ptr<nodo> node) {
    if (!lista->head) {
        lista->head = move(node);
        lista->tail = lista->head.get();
    } else {
        lista->tail->sig = move(node);
        lista->tail = lista->tail->sig.get();
    }
    lista->size++;
}

/* Inserta un nodo en la posición pasada por parámetro */
void insert(lista_enlazada* lista, unique_ptr<nodo> node, int pos) {
    if (pos > lista->size) {
        cout << "Posición excede el largo de la lista" << endl;
        push_back(lista, move(node));
        return;
    }
    if (pos == 0) {
        push_front(lista, move(node));
    } else {
        nodo* current = lista->head.get();
        for (int i = 0; i < pos - 1; i++) {
            current = current->sig.get();
        }
        node->sig = move(current->sig);
        current->sig = move(node);
        lista->size++;
    }
}

/* Elimina el primer nodo de la lista */
void delete_front(lista_enlazada* lista) {
    if (!lista->head) {
        cout << "No hay valores que eliminar" << endl;
        return;
    }
    unique_ptr<nodo> node = move(lista->head);
    lista->head = move(node->sig);
    lista->size--;
}

/* Elimina el último nodo de la lista */
void erase(lista_enlazada* lista, int pos) {
    if (pos == 0) {
        delete_front(lista);
        return;
    }
    if (pos >= lista->size) {
        nodo* curr_node = lista->head.get();
        while (curr_node->sig.get() && curr_node->sig->sig) {
            curr_node = curr_node->sig.get();
        }
        curr_node->sig = nullptr;
        lista->size--;
    } else {
        nodo* current = lista->head.get();
        for (int i = 0; i < pos - 1; i++) {
            current = current->sig.get();
        }
        unique_ptr<nodo> node = move(current->sig);
        current->sig = move(node->sig);
        lista->size--;
    }
}

/* Elimina el último nodo de la lista */
void print_list(const lista_enlazada* lista) {
    const nodo* curr_node = lista->head.get();
    int i = 0;
    while (curr_node) {
        cout << "list[" << i << "] = " << curr_node->dato << endl;
        curr_node = curr_node->sig.get();
        i++;
    }
}

/* Prueba la lista enlazada */
void test_lista_enlazada(int list_length) {
    lista_enlazada lista;
    init_lista(&lista);
    
    for (int i = 0; i < list_length; i++) {
        push_back(&lista, create_node(i));
    }
    cout << "\nLista sin cambios" << endl;
    print_list(&lista);

    cout << "\nLista con erase en 0" << endl;
    erase(&lista, 0);
    print_list(&lista);
    cout << "\nLista con erase en 0 y 5" << endl;
    erase(&lista, 5);
    print_list(&lista);
    cout << "\nLista con erase en 0, 5 y 10" << endl;
    erase(&lista, 10);
    print_list(&lista);
}

int main() {
    test_lista_enlazada(10);
    return 0;
}
