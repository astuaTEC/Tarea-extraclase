//
// Created by saymon on 5/03/19.
//

#include <clocale>
#include <iostream>
#include "List.h"
#include "Collector.h"
using namespace std;

/**
 * constructor
 */
List::List(){
    head = nullptr;
}
/**
 * funcion para acceder al primer nodo de la lista
 * @return el primer nodo
 */
Node* List::getHead() {
    return this->head;
}
/**
 * funcion para asignar el primer nodo de la lista
 * @param node que va a ser el primero
 */
void List::setHead(Node *node) {
    this->head= node;
}
/**
 * funcion para agregar elementos a una lista
 * @param n el dato a asignar
 */
void List::add(int n) {
    Node* node = new Node(nullptr,n);
    if (!head) {
        this->head = node;
        head->setData(n);
    } else {
        Node *aux = head;
        setHead(node);
        head->setSgt(aux);
        head->setData(n);
    }
}
/**
 * funcion para recorrer todos los elementos de la lista
 */
void List::recorrer() {
    if (!head){
        cout << "Lista vacía" << endl;
    }
    else{
        cout << "Estado de la Lista"<<endl;
        cout << "__________________________________________________________"<< endl;
        Node *aux = getHead();
        while (aux){
            cout<< "Posicion: "<< aux <<" Dato: "<< aux->getData() <<endl;
            aux = aux->getSgt();
        }
        cout << "__________________________________________________________"<< endl;
    }
}

/**
 * funcion para eliminar el ultimo elemento de la lista
 */
void List::eliminarUltimo() {
    Node* aux = getHead();
    if(!aux->getSgt()){
        setHead(nullptr);
    }
    while(aux->getSgt()->getSgt()){
        aux = aux->getSgt();
    }
    delete(aux->getSgt());
    aux->setSgt(nullptr);

}