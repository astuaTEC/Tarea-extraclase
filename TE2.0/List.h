//
// Created by saymon on 5/03/19.
//

#ifndef TE2_0_LIST_H
#define TE2_0_LIST_H

#include "Node.h"
#include "Collector.h"

/**
 * clase List
 */
class List {

    /**
     * atributos privados
     */
private:
    struct Node *head;


  /**
   * metodos publicos
   */
public:
    List();
    Node* getHead();
    void setHead(Node*);
    void add(int);
    void eliminar(int);
    void eliminarUltimo();
    void recorrer();

};


#endif //TE2_0_LIST_H
