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
        nulo = T();
        n = 0;
    }

    vdisperso(const T &valor_nulo) {

        n = 0;
        nulo = valor_nulo;
    }

    vdisperso(const vector<T> &v) {

        nulo = T();

        for (int i = 0; i < v.size(); i++) {

            if (v[i] != nulo)
                coefs.push_back(pair<int, T>(i, v[i]));
        }

        n = v.size();
    }

    vdisperso(const vector<T> &v, const T &valor_nulo) {

        nulo = valor_nulo;

        for (int i = 0; i < v.size(); i++) {

            if (v[i] != nulo)
                coefs.push_back(pair<int, T>(i, v[i]));
        }

        n = v.size();
    }

    void asignar_coeficiente(int i, const T &x) {

        if (x != nulo && i >= 0 && i < n){

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

        T salida = nulo;

        typename list< pair<int, T> >::const_iterator it = coefs.cbegin();
        if (i >= n || i < 0) it = coefs.cend(); // si se accede a un indice mayor que el tamaño se devuelve un nulo

        while (it != coefs.cend() && it->first != i)
            it++;

        if (it != coefs.cend())
            salida = it->second;

        return salida;
    }

    void cambiar_nulo(const T &valor_nulo) {
        nulo = valor_nulo;
    }

    vector<T> convertir() const {

        vector<T> salida(n, nulo);

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
    list< pair<int, T> > coefs; //para mi solucion mantengo la lista ordenada
    int n;
    T nulo;
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

    vdisperso<int> v(vec, int());

    v.asignar_coeficiente(10, 5);
    cout <<"size = " << v.size() << endl;
    cout <<"size_not_nulls = " << v.size_not_nulls() << endl;
    v.asignar_coeficiente(20,15);
    cout << "size_not_nulls = " <<v.size_not_nulls() << endl;
    cout <<"v[2] = " << v[2] << endl;
    cout <<"v[10] = " << v[10] << endl;
    cout << "size = " <<v.size() << endl << endl;

    cout << "\nVector entero:\n" << endl;

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    cout << "------------" << endl;

    v.cambiar_nulo(77);
    cout << "Se cambia de nulo" << endl;
    cout << "Se convierte y se pasa a otro vector" << endl;

    vdisperso<int> v2(v.convertir(), 77);

    cout <<"size = " << v2.size() << endl;
    cout << "v[4] = " << v2[4] << endl;
    cout << "v[6] = " << v2[6] << endl;

    cout << "\nVector entero:\n" << endl;

    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << endl;

    cout << "------------" << endl;

    int n = 0;
/*
    do {
        cin >> n;
        cout << v2[n] << endl;

    }while(n != -1);
*/
}