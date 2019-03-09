#include <iostream>
#include "Node.h"

using namespace std;
int main() {

    List *list = new List;

    list->add(3);
    list->add(5);
    list->add(6);
    list->add(8);
    list->recorrer();

    list->add(77);
    list->add(14);
    list->eliminarUltimo();

    list->add(65);
    list->eliminarUltimo();
    list->add(55);
    list->add(8);

    list->eliminarUltimo();
    list->add(99);

    list->recorrer();

    return 0;
}