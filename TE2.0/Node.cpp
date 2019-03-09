//
// Created by saymon on 5/03/19.
//

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include "Node.h"
#include "Collector.h"

using namespace std;
/**
 * Constructor
 * @param nodeSgt  al apuntador hacia el nodo siguiente
 * @param d  el sato a guardar dentro del nodo
 */

Node::Node(Node* nodeSgt, int d) {
    data = d;
    sgt = nodeSgt;
    recolector = Collector::getInstance();
};

/**
 * Sobrecarga del operador new
 * @param sz el tamaño del espacio de memoria que se necesita
 * @return retorna la dirección de memoria donde se va a alojar el nodo
 */

void* Node:: operator new(size_t sz){
    cout << "entra a new..." << endl;

    return recolector->nuevo_nodo();
}

Collector* Node:: recolector = 0;

/**
 * sobrecarga del operador delete
 * @param node es el nodo que se quiere eliminar, o en este caso, reciclar
 */

void Node:: operator delete (void* node){
    recolector->reciclar_nodo((Node*)node);
    recolector->revisar();

}
/**
 * funcion para obtener el valor alojado en un nodo
 * @return el dato que almacena el nodo
 */
int Node::getData() const {
    return this->data;

}

/**
 * funcion para setear el dato en un nodo
 * @param n el dato a asignar
 */
void Node::setData(int n)  {
    this->data = n;
}
/**
 * funcion para obtener el puntero del nodo siguiente
 * @return el puntero hacia el nodo siguiente
 */
Node* Node::getSgt() const {
    return this->sgt;
}
/**
 * funcion para asignar el nodo siguiente
 * @param nodo que ahora va a ser el siguiente
 */
void Node::setSgt(Node *nodo) {
    this->sgt= nodo;
}



