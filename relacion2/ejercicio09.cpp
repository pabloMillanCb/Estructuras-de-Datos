#include<map>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

template <typename T>
void inversa(list<T> &l) {

    typename list<T>::iterator b = l.begin();
    typename list<T>::iterator e = l.end();
    e--;

    for (int i = 0; i < l.size()/2; i++){

        T n = *b, m = *e;

        *b = m; 
        *e = n;
        e--;    
        b++;
    }
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

    inversa(lista);

    cout << "Lista 1: " << endl;

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

    lista.clear();

    lista.push_back(2);
    lista.push_back(5);
    lista.push_back(3);
    lista.push_back(6);

    inversa(lista);

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

    inversa(lista);

    cout << "Lista 3: " << endl;

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

    lista.clear();

    inversa(lista);

    cout << "Lista vacía: " << endl;

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;


}