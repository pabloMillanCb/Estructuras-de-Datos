#include<map>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

void inserta_despues(list<int> &l, int x) {

    list<int>::iterator i = l.begin();

    while (i != l.end()) {

        if (*i == x) {
            i++;
            l.insert(i, x-1);
        }

        else {
            i++;
        }
    }
}

int main() {

    list<int> lista;

    lista.push_back(1);
    lista.push_back(3);
    lista.push_back(3);
    lista.push_back(6);
    lista.push_back(3);
    lista.push_back(8);
    lista.push_back(9);

    cout << "Caso 1: " << endl;

    inserta_despues(lista, 3);

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

    lista.clear();

    lista.push_back(3);
    lista.push_back(1);
    lista.push_back(3);
    lista.push_back(3);
    lista.push_back(6);
    lista.push_back(3);
    lista.push_back(8);
    lista.push_back(9);
    lista.push_back(3);

    cout << "Caso 2: " << endl;

    inserta_despues(lista, 3);

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

}