#include<map>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

template <typename T>
typename list<T>::const_iterator contenida(const list<T> &l1, const list<T> &l2) {

    typename list<T>::const_iterator i2 = l2.begin(),
                                     i1 = l1.begin(),
                                     iout = i2;
    int count2 = 0, count1 = l1.size();

    while (i2 != l2.end() && i1 != l1.end() && count1 + count2 <= l2.size()) {

        if (*i1 == *i2) {

            i1++;
            i2++;
            count1--;
            count2++;
        }

        else {

            i1 = l1.begin();
            count1 = l1.size();

            if (*i1 != *i2){
                i2++;
                count2++;    
            }

            iout = i2;
        }
    }

    if (i1 != l1.end() || count1 + count2 > l2.size())
        iout = l2.end();

    return iout;
}

int main() {

    list<int> lista1, lista2, lista;
    list<int>::const_iterator it;
/*
    lista1.push_back(3);
    lista1.push_back(3);
    lista1.push_back(5);
    lista1.push_back(5);
    lista1.push_back(8);

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

    cout << "\nPrueba 1, contenida en medio de la lista: \n";

    it = contenida(lista1, lista2);

    for (list<int>::const_iterator i = it; i != lista2.end(); i++)
        cout << *i << endl;

    lista1.clear(); lista2.clear();

    lista1.push_back(2);
    lista1.push_back(3);
    lista1.push_back(3);
    lista1.push_back(5);
    lista1.push_back(5);
    lista1.push_back(8);

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

    cout << "\nPrueba 2, contenida al principio: \n";

    it = contenida(lista1, lista2);

    for (list<int>::const_iterator i = it; i != lista2.end(); i++)
        cout << *i << endl;

    lista1.clear(); lista2.clear();

    lista1.push_back(10);
    lista1.push_back(11);
    lista1.push_back(12);
    lista1.push_back(13);

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

    cout << "\nPrueba 3, contenida al final: \n";

    it = contenida(lista1, lista2);

    for (list<int>::const_iterator i = it; i != lista2.end(); i++)
        cout << *i << endl;

    lista1.clear(); lista2.clear();

    lista1.push_back(2);
    lista1.push_back(3);
    lista1.push_back(7);
    lista1.push_back(5);
    lista1.push_back(8);

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

    cout << "\nPrueba 4, no contenida: \n";

    it = contenida(lista1, lista2);

    for (list<int>::const_iterator i = it; i != lista2.end(); i++)
        cout << *i << endl;

    lista1.clear(); lista2.clear();

    lista1.push_back(7);
    lista1.push_back(11);
    lista1.push_back(12);
    lista1.push_back(13);
    lista1.push_back(16);
    lista1.push_back(17);

    lista2.push_back(2);
    lista2.push_back(3);
    lista2.push_back(4);
    lista2.push_back(5);
    lista2.push_back(6);
    lista2.push_back(8);
    lista2.push_back(10);
    lista2.push_back(11);
    lista2.push_back(12);
    lista2.push_back(13);

    cout << "\nPrueba 5, contenida solo una parte al final: \n";

    it = contenida(lista1, lista2);

    for (list<int>::const_iterator i = it; i != lista2.end(); i++)
        cout << *i << endl;

    lista1.clear(); lista2.clear();

    lista2.push_back(10);
    lista2.push_back(11);
    lista2.push_back(12);
    lista2.push_back(13);
    lista2.push_back(16);
    lista2.push_back(17);

    lista1.push_back(2);
    lista1.push_back(3);
    lista1.push_back(3);
    lista1.push_back(5);
    lista1.push_back(5);
    lista1.push_back(8);
    lista1.push_back(10);
    lista1.push_back(11);
    lista1.push_back(12);
    lista1.push_back(13);



    cout << "\nPrueba 6, termina de buscar cuando el espacio de l2 restante es menor que lo que ocupa l1: \n";

    it = contenida(lista1, lista2);

    for (list<int>::const_iterator i = it; i != lista2.end(); i++)
        cout << *i << endl;
*/
    //lista1.clear(); 
    //lista2.clear();

    lista1.push_back(3);
    lista1.push_back(3);
    lista1.push_back(5);
    lista1.push_back(5);
    lista1.push_back(8);

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

    lista1.clear();

    cout << "\nPrueba 7\n";

    it = contenida(lista1, lista2);

    if (it == lista2.begin())
        cout << "Es end\n";

}