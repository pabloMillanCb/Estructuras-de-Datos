#include<map>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

template <typename T>
class vector_dinamico {

private:
    list<T> lista;

public:
    vector_dinamico() {}

    class iterator {
    protected:
        typename list<T>::iterator iter;

    public:
        iterator() {}
        
        iterator(typename list<T>::iterator it) {iter = it;}

        T operator*() {return *iter;}

        typename list<T>::iterator operator()() {return iter;}

        T operator++(int) {
            iter++;
            return *iter;
        }

        T operator--(int) {
            iter--;
            return *iter;
        }

        bool operator==(const iterator &it) const { return iter == it.iter;}

        bool operator!=(const iterator &it) const { return iter != it.iter;}

    };

    iterator insert(iterator it, const T &x) { //eficiencia constante

        return iterator(lista.insert(it(), x));
    }

    iterator erase(iterator it) { //eficiencia constante
        iterator salida = end();

        if (it != end())
            salida = lista.erase(it());

        return salida;
    } 

    iterator erase(int i) { //eficiencia lineal O(i)

        typename list<T>::iterator it;

        if (i >= 0 && i < lista.size()) {
            it = lista.begin();
            for (int j = 0; j < i && it != lista.end(); j++)
                it++;

            if (it != lista.end())
                it = lista.erase(it);
        }
        else {
            it = lista.end();
        }
        
        return it;
    }

    void push_back(const T &x) { lista.push_back(x); } //eficiencia constante

    T& operator[](int i) { //eficiencia lineal O(i)

        typename list<T>::iterator it = lista.begin();

        if (i >= 0 && i < lista.size()){
            
            for (int j = 0; j < i; j++)
                it++;
        }

        return *it;
    }

    int size() const {return lista.size();} //eficiencia constante

    iterator begin() { //eficiencia constante
        typename list<T>::iterator iter = lista.begin();
        iterator it(iter);
        return it; 
    } 

    iterator end() { //eficiencia constante
        typename list<T>::iterator iter = lista.end();
        iterator it(iter);
        return it; 
    } 

};

int main() {

    vector_dinamico<int> v;

    vector_dinamico<int>::iterator it = v.begin();

    it = v.insert(it, 2);
    it = v.insert(it, 3);
    it = v.insert(it, 5);
    it = v.insert(it, 1);
    it = v.insert(it, 2);
    it = v.insert(it, 8);

    cout << "size: " << v.size() << endl;

    v.push_back(4);
    v.push_back(3);
    v.push_back(0);
    v.push_back(5);

    cout << "size: " << v.size() << endl;

    cout << "Antes de borrar:\n";

    for (int i = 0; i < v.size(); i++) {

        cout << v[i] << endl;
    }

    v.erase(0);

    cout << "Despues de borrar:\n";

    for (int i = 0; i < v.size(); i++) {

        cout << v[i] << endl;
    }
    
    it = v.end(); //it--;

    v.erase(it);

    cout << "Despues de borrar otra vez:\n";

    for (int i = 0; i < v.size(); i++) {

        cout << v[i] << endl;
    }



}