#include<functional>
#include<vector>
#include<set>
#include<iostream>
#include<list>

using namespace std;

template<typename T>
class tabla_hash {

private:

    vector<set<T>> tabla;
    int M, size, a, b;

    void rehash(int newM) {

        iterator it = begin();

        list<T> lista;

        while (it != end()) {
            lista.push_back(*it);
            it++;
        }

        M = M*2+1;
        a = M-1;
        size = 0;

        tabla.clear();
        tabla.resize(M);

        for (typename list<T>::iterator i = lista.begin(); i != lista.end(); i++) {
            insert(*i);
        }
    }

public:

    tabla_hash() {
        M = 13;
        a = M-1;
        b = 3;
        size = 0;
        tabla.resize(13);
    }

    void insert(const T &x) {

        size++;

        int index = hash<T>()(x);
        tabla[(a*index+b)% M].insert(x);

        if (size > M/2)
            rehash(2*M+1);

    }

    void erase(const T &x) {

        int index = hash<T>()(x);
        int erased = tabla[(a*index+b)% M].erase(x);
        if (erased == 1) size--;

    }

    bool find(const T &x) const {
        
        int index = hash<T>()(x);
        index = (a*index+b)% M;
        bool s = false;
        if (tabla[index].find(x) != tabla[index].end())
            s = true;

        return s;
    }

    int siz() {
        return size;
    }

    int eme() {
        return M;
    }

    class iterator {
    private:
        typename set<T>::iterator sit;
        int index;
        const vector<set<T>> *tabla;

    public:

        iterator() {index = 0;}
        iterator(const tabla_hash<T>::iterator &orig) {

            int index = orig.index;
            sit = orig.sit;
        }

        iterator(typename set<T>::iterator it, int i, const vector<set<T>> *tab) {

            index = i;
            sit = it;
            tabla = tab;
        }

        iterator operator++(int) {

            sit++;

            if (sit == (*tabla)[index].end() && index < (*tabla).size()-1) {

                index++;
                while ((*tabla)[index].size() < 1 && index < (*tabla).size()-1) {

                    index++;
                }

                sit = (*tabla)[index].begin();
            }

            return *this;
        }

        iterator operator--(int) {

            if (sit == (*tabla)[index].begin()) {
                index--;
                while ((*tabla)[index].size() < 1 && index > 0) {
                    index--;
                }

                sit = (*tabla)[index].end();
                sit--;
            }

            else {
                sit--;
            }

            return *this;
        }

        bool operator==(iterator it){return index == it.index && sit == it.sit;}
        bool operator==(iterator &it){return index == it.index && sit == it.sit;}

        bool operator!=(iterator it){return index != it.index || sit != it.sit;}
        bool operator!=(iterator &it){return index != it.index || sit != it.sit;}
        
        void operator=(iterator it) {
            sit = it.sit;
            index = it.index;
            tabla = it.tabla;
        }
        void operator=(iterator &it) {
            sit = it.sit;
            index = it.index;
            tabla = it.tabla;
        }

        T operator*() {
            return *sit;
        }

    };

    iterator begin() const {

        int i = 0;

        while (tabla[i].size() < 1 && i < M) {
            i++;
        }

        typename set<T>::iterator it = tabla[i].begin();
        iterator salida(it, i, &tabla);

        return salida;
    }

    iterator end() const {
        
        int i = M-1;
        typename set<T>::iterator it = tabla[i].end();
        iterator salida(it, i, &tabla);

        return salida;
    }
};

int main() {

    tabla_hash<int> t;

    t.insert(34);
    t.insert(9);
    t.insert(12);
    t.insert(41);
    t.insert(22);
    //t.insert(4);

    tabla_hash<int>::iterator it = t.begin();

    cout << "\nRecorrido de principio a fin:\n " << endl;

    while (it != t.end()) {

        cout << *it << endl;
        it++;
    }

    it = t.end();
    it--;

    cout << "\nRecorrido de fin a principio:\n " << endl;

    cout << *it << endl;
    while (it != t.begin()) {

        it--;
        cout << *it << endl;
    }

    t.insert(32);
    t.insert(23);
    t.insert(6);
    t.insert(3);
    t.insert(99);

    it = t.begin();

    cout << "\nRecorrido 2 de principio a fin:\n " << endl;

    while (it != t.end()) {

        cout << *it << endl;
        it++;
    }

    it = t.end();
    it--;

    cout << "\nRecorrido 2 de fin a principio:\n " << endl;
    cout << *it << endl;

    while (it != t.begin()) {

        it--;
        cout << *it << endl;
    }

    cout << endl << endl;

    if (t.find(99)) {
        cout << "99 está dentro de la tabla\n";
    }
    if (!t.find(7)) {
        cout << "7 no está dentro de la tabla\n";
    }

    cout << t.siz() << endl;
    t.erase(99);
    cout << t.siz() << endl;

    if (!t.find(99)) {
        cout << "99 no está dentro de la tabla\n";
    }

    it = t.begin();

    cout << "\nRecorrido 3 de principio a fin:\n " << endl;

    while (it != t.end()) {

        cout << *it << endl;
        it++;
    }

    cout << endl << endl;

    cout << t.siz() << endl;
    t.erase(7);
    cout << t.siz() << endl;

    it = t.begin();

    cout << "\nRecorrido 4 de principio a fin:\n " << endl;

    while (it != t.end()) {

        cout << *it << endl;
        it++;
    }

}