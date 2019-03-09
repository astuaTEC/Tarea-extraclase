//
// Created by saymon on 5/03/19.
//

#include <clocale>
#include <cstdlib>
#include <new>
#include <iostream>
#include "Collector.h"
using namespace std;

/**
 * instancia de collector
 */
Collector* Collector::instance = 0;

/**
 * constructor
 */
Collector::Collector(){

}
/**
 * singleton aplicado
 * @return una instancia de collector
 */
Collector* Collector::getInstance()
{
    if (instance == 0)
    {
        instance = new Collector;
    }

    return instance;
}
/**
 * funcion que recorre todos los elementos del collector
 */
void Collector::revisar(){
        if (!cabeza){
            cout << "No hay espacios disponibles"<< endl;
        }
        else{
            cout << "Estado del collector"<<endl;
            cout << "--------------------"<< endl;
            Node *aux = cabeza;
            while (aux){
                cout<< aux << endl;
                aux = aux->getSgt();
            }
            cout << "________________________"<<endl;
        }
}
/**
 * funcion para asignar espacio de memoria para un nuevo nodo
 * @return la direccion de memoria donde alojar el nodo
 */
void *Collector::nuevo_nodo() {
    cout << "entra a collector"<< endl;
    if(cabeza== nullptr){
        return malloc(sizeof(Node));
    }
    else {
        Node *aux = getCabeza();
        Node* aux2 = getCabeza()->getSgt();
        if(!aux2){
            cabeza = NULL;
            return aux;
        }
        while(aux2->getSgt()) {
            aux = aux2;
            aux2 = aux->getSgt();

        }
        aux->setSgt(NULL);

        return aux2;
    }
}
/**
 * funcion para reciclar espacio de memoria en collector
 * @param node el nodo que ya ha sido liberado en la lista
 */
void Collector::reciclar_nodo(Node* node) {
    if (!cabeza) {
        cabeza = node;
    } else {
        Node *aux = cabeza;
        cabeza = node;
        cabeza->setSgt(aux);
    }
}

Node* Collector:: cabeza = 0;
/**
 * funcion para acceder al primer nodo de collector
 * @return el primer nodo
 */
Node* Collector:: getCabeza(){
    return this->cabeza;
}

