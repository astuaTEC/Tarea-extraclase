//
// Created by saymon on 5/03/19.
//

#include <clocale>
#include <cstdlib>
#include <new>
#include <iostream>
#include "Collector.h"
using namespace std;


Collector* Collector::instance = 0;

Collector::Collector(){

}

Collector* Collector::getInstance()
{
    if (instance == 0)
    {
        instance = new Collector;
    }

    return instance;
}

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


void Collector::limpiar() {

}

void *Collector::nuevo_nodo() {
    cout << "entra a collector"<< endl;
    if(cabeza== nullptr){
        cout << "devuelve null"<< endl;
        return malloc(sizeof(Node));
    }
    else {
        cout<< "entra else nuevo_nodo"<< endl;
        Node *aux = getCabeza();
        Node* aux2 = getCabeza()->getSgt();
        if(!aux2){
            cabeza = NULL;
            return aux;
        }
        while(aux2->getSgt()) {
            cout<< "entra while nuevo_nodo"<< endl;
            aux = aux2;
            aux2 = aux->getSgt();

        }
        aux->setSgt(NULL);
        cout << "devuelve pos" << endl;

        return aux2;
    }
}

void Collector::reciclar_nodo(Node* node) {
    cout << "entra en reciclar"<< endl;
    if (!cabeza) {
        cout << "entra en if reciclar"<< endl;
        cabeza = node;
    } else {
        cout << "entra en else reciclar" << endl;
        Node *aux = cabeza;
        cabeza = node;
        cabeza->setSgt(aux);
    }
}

Node* Collector:: cabeza = 0;

Node* Collector:: getCabeza(){
    return this->cabeza;
}

