#include<map>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

template <typename T>
list<T> inversa(const list<T> &l) {

    list<T> salida;

    for (typename list<T>::const_reverse_iterator i = l.rbegin(); i != l.rend(); i++ )
        salida.push_back(*i);

    return salida;

}

int main() {

    list<int> lista;

    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(5);
    lista.push_back(5);
    lista.push_back(5);
    lista.push_back(3);
    lista.push_back(6);
    lista.push_back(5);

    lista = inversa(lista);

    cout << "Lista 1: " << endl;

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

    lista.clear();

    lista.push_back(2);
    lista.push_back(5);
    lista.push_back(3);
    lista.push_back(6);

    lista = inversa(lista);

    cout << "Lista 2: " << endl;

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;
    
    lista.clear();

    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(2);

    lista = inversa(lista);

    cout << "Lista 3: " << endl;

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

    lista.clear();

    lista = inversa(lista);

    cout << "Lista vacía: " << endl;

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;


}