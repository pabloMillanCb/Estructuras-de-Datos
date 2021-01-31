#include<map>
#include<vector>
#include<list>
#include<string>
#include<iostream>

using namespace std;

template <typename T>
class vdisperso {

public:
    vdisperso() {

        n = 0;
    }

    vdisperso(const vector<T> &v) {

        for (int i = 0; i < v.size(); i++) {

            if (v[i] != T())
                coefs.push_back(pair<int, T>(i, v[i]));
        }

        n = v.size();
    }

    void asignar_coeficiente(int i, const T &x) {

        if (x != T() && i >= 0 && i < n){

            typename list< pair<int, T> >::iterator it = coefs.begin();
            while (it != coefs.end() && it->first != i)
                it++;

            if (it == coefs.end())
                coefs.push_back(pair<int, T>(i, x));
            
            else
                it->second = x;
        }
        //if (i > n) n = i+1;
    }

    T operator[] (int i) const {

        //asertion (i > 0 && i < n) lo dejo comentado por si intirfiriera con los tests

        T salida = T();

        typename list< pair<int, T> >::const_iterator it = coefs.cbegin();
        if (i >= n || i < 0) it = coefs.cend(); // si se accede a un indice mayor que el tamaño o menor que 0 se devuelve un nulo

        while (it != coefs.cend() && it->first != i)
            it++;

        if (it != coefs.cend())
            salida = it->second;

        return salida;
    }

    vector<T> convertir() const {

        vector<T> salida(n);

        typename list< pair<int, T> >::const_iterator it = coefs.begin();
        while (it != coefs.cend()){

            salida[it->first] = it->second;
            it++;
        }

        return salida; 
    }

    int size() const {
        return n;
    }

    int size_not_nulls() const {
        return coefs.size();
    }

private:
    list< pair<int, T> > coefs;
    int n;
};

int main() {

    vector<int> vec;

    vec.push_back(int());
    vec.push_back(2);
    vec.push_back(int());
    vec.push_back(1);
    vec.push_back(int());
    vec.push_back(int());
    vec.push_back(4);
    vec.push_back(int());
    vec.push_back(int());
    vec.push_back(int());
    vec.push_back(11);
    vec.push_back(int());

    vdisperso<int> v(vec);

    v.asignar_coeficiente(10, 5);
    cout <<"size = " << v.size() << endl;
    cout <<"size_not_nulls = " << v.size_not_nulls() << endl;
    v.asignar_coeficiente(5,8);
    cout << "size_not_nulls = " <<v.size_not_nulls() << endl;
    cout <<"v[2] = " << v[2] << endl;
    cout <<"v[5] = " << v[5] << endl;
    cout << "size = " <<v.size() << endl << endl;
    v.asignar_coeficiente(20,8);
    cout << "size = " <<v.size() << endl << endl;

    vdisperso<int> v2(v.convertir());

    cout << v2.size() << endl;
    cout << v2[5] << endl;

    cout << "\nVector entero:\n" << endl;

    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << endl;
/*
    int n = 0;

    do {
        cin >> n;
        cout << v2[n] << endl;

    }while(n != -1);*/

}