#include<map>
#include<set>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

template <typename T>
void elimina(list<T> &l, const vector<T> &v) {

    set<T,greater<int>> vsort;

    for (typename vector<T>::const_iterator i = v.cbegin(); i != v.cend(); i++)
        vsort.insert(*i);

    typename list<T>::iterator i = l.begin();
    while (i != l.end()){

        if (vsort.find(*i) != vsort.end())
            i = l.erase(i);
        else
            i++;
    }
}

//Abajo dejo comentada una solución de eficiencia O(n*m). La de arriba es O(t*log t) siendo t = max(n,m), pero
//en realidad la grafica tendria una curva de n*log n + m*log m asi que el que merezca la pena dependera de los
//datos que se vayan a usar

/*template <typename T>
void elimina(list<T> &l, const vector<T> &v) {

    for (typename vector<T>::const_iterator i = v.cbegin(); i != v.cend(); i++) {

        typename list<T>::iterator j = l.begin();
        while (j != l.end()){

            if (*i == *j)
                j = l.erase(j);
            else
                j++;
        }
    }
}*/

int main() {

    list<int> lista;
    vector<int> vector;

    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(1);
    lista.push_back(5);
    lista.push_back(3);
    lista.push_back(6);

    vector.push_back(1);
    vector.push_back(6);

    elimina(lista, vector);

    for (typename list<int>::iterator i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

    /*Considero que para este unico ejemplo se cubre cualquier caso posible*/

}