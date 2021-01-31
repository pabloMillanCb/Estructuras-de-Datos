#include<set>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

template <typename T>
void elimina_duplicados(list<T> &l) {

    set<T>count;

    typename list<T>::iterator i = l.begin();

    while ( i != l.end()) { //O(n)

        bool b = (count.insert(*i)).second;

        if (!b)
            i = l.erase(i);
        else
            i++;
    }

}

int main() {

    list<int> lista;

    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(3);
    lista.push_back(2);
    lista.push_back(5);
    lista.push_back(5);
    lista.push_back(3);
    lista.push_back(6);
    lista.push_back(5);

    elimina_duplicados(lista);

    cout << "Lista 1: " << endl;

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

    lista.clear();

    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(3);
    lista.push_back(2);

    elimina_duplicados(lista);

    cout << "Lista 2: " << endl;

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;
    
    lista.clear();

    lista.push_back(2);
    lista.push_back(2);
    lista.push_back(2);
    lista.push_back(2);
    lista.push_back(2);
    lista.push_back(2);

    elimina_duplicados(lista);

    cout << "Lista 3: " << endl;

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;


}