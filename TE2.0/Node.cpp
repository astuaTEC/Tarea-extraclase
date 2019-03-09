//
// Created by saymon on 5/03/19.
//

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include "Node.h"
#include "Collector.h"

using namespace std;


Node::Node(Node* nodeSgt, int d) {
    data = d;
    sgt = nodeSgt;
    recolector = Collector::getInstance();
};


void* Node:: operator new(size_t sz){
    cout << "entra a new..." << endl;

    return recolector->nuevo_nodo();
}

Collector* Node:: recolector = 0;

void Node:: operator delete (void* node){
    recolector->reciclar_nodo((Node*)node);
    recolector->revisar();

}
int Node::getData() const {
    return this->data;

}

void Node::setData(int n)  {
    this->data = n;
}
Node* Node::getSgt() const {
    return this->sgt;
}
void Node::setSgt(Node *nodo) {
    this->sgt= nodo;
}



