//
// Created by saymon on 5/03/19.
//

#include <clocale>
#include <iostream>
#include "List.h"
#include "Collector.h"
using namespace std;


List::List(){
    head = nullptr;
}

Node* List::getHead() {
    return this->head;
}

void List::setHead(Node *node) {
    this->head= node;
}

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

void List::recorrer() {
    if (!head){
        cout << "Lista vacía" << endl;
    }
    else{
        cout << "Estado de la Lista"<<endl;
        cout << "--------------------"<< endl;
        Node *aux = getHead();
        while (aux){
            cout<< aux << endl;
            aux = aux->getSgt();
        }
        cout << "_____________________"<< endl;
    }
}

/*
void List::eliminar(int n) {
    if(head->getData() == n) {
        cout << "elimina cabeza" << endl;
        delete(head);
        setHead(head->getSgt());
    }
    Node* aux = head;
    while(aux->getSgt()){
        if(aux->getSgt()->getData() == n){
            delete(aux->getSgt());
            aux->setSgt(NULL);
            cout << "eliminado en while" << endl;
            break;
        }

        aux = aux->getSgt();
    }

}
*/

void List::eliminarUltimo() {
    Node* aux = getHead();
    while(aux->getSgt()->getSgt()){
        aux = aux->getSgt();
    }
    delete(aux->getSgt());
    aux->setSgt(nullptr);
    cout << "eliminado en while" << endl;

}