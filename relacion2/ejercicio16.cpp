#include<map>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

template <typename T>
list<pair<T, int> > comprimir(const list<T> &l) {

    list<pair<T, int> > salida;
    typename list<T>::const_iterator i = l.cbegin();

    if (l.size() > 0){

        int count = 0;
        T elem = *i;

        while (i != l.cend()) {

            if (*i == elem){
                count++;
                i++;}
            else {
                
                salida.push_back(pair<T, int>(elem, count));
                elem = *i;
                count = 1;
                i++;
            }
        }

        salida.push_back(pair<T, int>(elem, count));
    }

    return salida;
}

template <typename T>
list<T> descomprimir(const list<pair<T, int> > &lc) {

    list<T> salida;
    typename list<pair<T, int> >::const_iterator i = lc.cbegin();

    if (lc.size() > 0) {

        while (i != lc.cend()) {

            for (int n = 0; n < i->second; n++)
                salida.push_back(i->first);
            
            i++;
        }
    }

    return salida;
}

int main() {

    list<int> lista1, lista2, lista3, lista, lista4, lista5;

    lista2.push_back(2);
    lista2.push_back(2); // 2
    lista2.push_back(3); // 1
    lista2.push_back(5);
    lista2.push_back(5);
    lista2.push_back(5); // 3
    lista2.push_back(10);
    lista2.push_back(10); // 2
    lista2.push_back(12);
    lista2.push_back(12);
    lista2.push_back(12); // 3
    lista2.push_back(2);
    lista2.push_back(2);
    lista2.push_back(2); // 3
    lista2.push_back(12);
    lista2.push_back(12); // 2
    lista2.push_back(13);
    lista2.push_back(13);
    lista2.push_back(13);
    lista2.push_back(13); // 4

    list<pair<int, int> > lit = comprimir(lista2);

    cout << "Prueba 1, lista normal: " << endl;

    for (list<pair<int, int> >::iterator i = lit.begin(); i != lit.end(); i++ ) {
        cout << i->first << " " << i->second << endl;
    }

    cout << endl << endl;

    lista = descomprimir(lit);

    for (list<int>::iterator i = lista.begin(); i != lista.end(); i++ ) {
        cout << *i << endl;
    }

    lit = comprimir(lista1);

    cout << "Prueba 2, lista sin elementos: " << endl;

    for (list<pair<int, int> >::iterator i = lit.begin(); i != lit.end(); i++ ) {
        cout << i->first << " " << i->second << endl;
    }

     cout << endl << endl;

    lista = descomprimir(lit);

    for (list<int>::iterator i = lista.begin(); i != lista.end(); i++ ) {
        cout << *i << endl;
    }

    lista3.push_back(1);
    lista3.push_back(2);
    lista3.push_back(3);
    lista3.push_back(4);
    lista3.push_back(5);
    lista3.push_back(6);

    lit = comprimir(lista3);

    cout << "Prueba 3, lista sin elementos repetidos: " << endl;

    for (list<pair<int, int> >::iterator i = lit.begin(); i != lit.end(); i++ ) {
        cout << i->first << " " << i->second << endl;
    }

     cout << endl << endl;

    lista = descomprimir(lit);

    for (list<int>::iterator i = lista.begin(); i != lista.end(); i++ ) {
        cout << *i << endl;
    }

    lista4.push_back(1);
    lista4.push_back(1);
    lista4.push_back(1);
    lista4.push_back(1);
    lista4.push_back(1);
    lista4.push_back(1);

    lit = comprimir(lista4);

    cout << "Prueba 4, lista con elementos idénticos entre ellos: " << endl;

    for (list<pair<int, int> >::iterator i = lit.begin(); i != lit.end(); i++ ) {
        cout << i->first << " " << i->second << endl;
    }

     cout << endl << endl;

    lista = descomprimir(lit);

    for (list<int>::iterator i = lista.begin(); i != lista.end(); i++ ) {
        cout << *i << endl;
    }

    lista5.push_back(1);

    lit = comprimir(lista5);

    cout << "Prueba 5, lista con un unico elemento: " << endl;

    for (list<pair<int, int> >::iterator i = lit.begin(); i != lit.end(); i++ ) {
        cout << i->first << " " << i->second << endl;
    }

     cout << endl << endl;

    lista = descomprimir(lit);

    for (list<int>::iterator i = lista.begin(); i != lista.end(); i++ ) {
        cout << *i << endl;
    }

    

}