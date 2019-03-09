//
// Created by saymon on 5/03/19.
//

#ifndef TE2_0_NODE_H
#define TE2_0_NODE_H


#include "Collector.h"

class Node{

private:

    int data;
    Node *sgt;
    static struct Collector *recolector;


    friend class List;

public:
    Node(Node*,int);
    int getData() const;
    void setData(int);
    Node* getSgt() const;
    void setSgt(Node*);
    void operator delete(void*);
    void *operator new(size_t);

};

#endif //TE2_0_NODE_H
