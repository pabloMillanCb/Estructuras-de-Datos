#include<map>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

template <typename T>
list<T> mezclar(const list<T> &l1, const list<T> &l2) {

    list<T> salida;

    typename list<T>::const_iterator i = l1.begin(), j = l2.begin();

    while (i != l1.end() && j != l2.end()) {

        if (*i < *j){

            salida.push_back(*i);
            i++;
        }
        else{
            salida.push_back(*j);
            j++;
        }

    }

    while (i != l1.end()) {

        salida.push_back(*i);
        i++;
    }

    while (j != l2.end()) {
        
        salida.push_back(*j);
        j++;
    }

    return salida;
}

int main() {

    list<int> lista1, lista2, lista;

    lista1.push_back(1);
    lista1.push_back(3);
    lista1.push_back(3);
    lista1.push_back(6);
    lista1.push_back(7);
    lista1.push_back(8);
    lista1.push_back(9);

    lista2.push_back(2);
    lista2.push_back(3);
    lista2.push_back(3);
    lista2.push_back(5);
    lista2.push_back(5);
    lista2.push_back(8);
    lista2.push_back(10);
    lista2.push_back(11);
    lista2.push_back(12);
    lista2.push_back(13);

    cout << "Caso 1: " << endl;

    lista = mezclar(lista1,lista2);

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

    lista.clear();

    cout << "\n\nCaso 2, segunda lista vacia: " << endl;

    lista = mezclar(lista1,lista);

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

    lista.clear();

    cout << "\n\nCaso 3, primera lista vacia: " << endl;

    lista = mezclar(lista,lista2);

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

}