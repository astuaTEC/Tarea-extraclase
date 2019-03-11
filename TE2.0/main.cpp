#include <iostream>
#include "Node.h"

void menu(List* lista);

using namespace std;
int main() {

    List *list = new List;
    menu(list);
    return 0;
}

/**
 * funcion del menu de interaccion
 * @param lista donde se agregan los elementos
 */
void menu(List* lista){

    int op;
    int n;
    cout << "Digite 1 para agregar un número:"<< endl;
    cout<< "Digite 2 para eliminar el último elemento de la lista:"<< endl;
    cin>> op ;

    if(op == 1){
        cout<< "Digite el número que desea agregar:"<< endl;
        cin>>n;
        lista->add(n);
        lista->recorrer();
        menu(lista);
    }
    else if(op == 2){
        if(lista->getHead()){
            lista->eliminarUltimo();
            lista->recorrer();
            menu(lista);
        }
        cout<< "La lista está vacía"<< endl;
        menu(lista);
    }
    cout << "Entrada inválida, inténtelo de nuevo"<< endl;
    menu(lista);
}