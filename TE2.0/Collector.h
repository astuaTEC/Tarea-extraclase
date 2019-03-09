//
// Created by saymon on 5/03/19.
//

#ifndef TE2_0_COLLECTOR_H
#define TE2_0_COLLECTOR_H


#include "Node.h"
#include "List.h"

/**
 * Clase Collector
 */
class Collector {

/**
 * metodos y atributos privados
 */
private:
    Collector();
    static struct Node* cabeza;
    static Collector* instance;

    friend class Node;

    /**
     * metodos publicos
     */
public:
    void* nuevo_nodo();
    void reciclar_nodo(Node*);
    void revisar();
    Node* getCabeza();
    static Collector* getInstance();

};


#endif //TE2_0_COLLECTOR_H
