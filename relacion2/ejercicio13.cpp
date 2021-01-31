#include<map>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

template <typename T>
//list<T> lista_posiciones(const list<T> &l, const list< typename list<T>::iterator> &li) ;
list<T> lista_posiciones(const list<T> &l, const list< typename list<T>::iterator> &li){

    typename list< typename list<T>::iterator>::const_iterator i = li.begin();
    list<T> salida;

    while (i != li.end()) {

        salida.push_back(**i);
        i++;
    }

    return salida;
}

int main() {

    list<int> lista2, lista1;
    list<list<int>::iterator> lit;

    lista2.push_back(2);
    lista2.push_back(3);
    lista2.push_back(3);
    lista2.push_back(5);
    lista2.push_back(5);
    lista2.push_back(8);
    lista2.push_back(9);
    lista2.push_back(11);
    lista2.push_back(12);
    lista2.push_back(13);

    list<int>::iterator i = lista2.begin();

    while (i != lista2.end()) {
        lit.push_back(i);
        i++;
        i++;
    }

    lista1 = lista_posiciones(lista2, lit);

    cout << "\nPrueba 1: \n";

    for (list<int>::const_iterator i = lista1.cbegin(); i != lista1.cend(); i++)
        cout << *i << endl;

    //------------------------------------------------------------------------

    lit.clear();
    lista1.clear();

    lista1 = lista_posiciones(lista2, lit);

    cout << "\nPrueba 2, lista vacia: \n";

    for (list<int>::const_iterator i = lista1.cbegin(); i != lista1.cend(); i++)
        cout << *i << endl;

    //------------------------------------------------------------------------

    lit.clear();
    lista1.clear();
    i = lista2.begin();

    while (i != lista2.end()) {
        lit.push_back(i);
        i++;
        if (i != lista2.end()) i++;
    }
    //couts para averiguar por qué el end() está apuntando a un valor 10
    cout << "el numero " << *lista2.end() << endl;
    i++;
    cout << "el numero " << *i << endl;
    i--; i--;
    cout << "el numero " << *i << endl;
    lit.push_back(lista2.end());

    lista1 = lista_posiciones(lista2, lit);

    cout << "\nPrueba 3, end() al final de la lista de iteradores: \n";

    for (list<int>::const_iterator i = lista1.cbegin(); i != lista1.cend(); i++)
        cout << *i << endl;

    //parece que lo que se mete es basura que tiene el end()
}