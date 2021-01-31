#include<iostream>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

template <typename T>
struct NOM_AP {

    string nombre, apellidos;
    T prioridad;

    NOM_AP(string nom, string ap, T prt) {
        nombre = nom;
        apellidos = ap;
        prioridad = prt;

    }

    bool operator >(const NOM_AP& s) const{
        
    
        return prioridad > s.prioridad;
    }

};

template <typename T>
class comp {
public:
    bool operator()(const T a,const T c) {

        return a > c;
    }

};

int main() {

    
    NOM_AP<int> nom1("Pablo", "Millan Culero", 5), nom2("Juan", "Ocana Valenzuela", 2), nom3("Jose Luis", "Gallego Pena", 7),
                nom4("German", "Vicente Dorado", 5), nom5("Alina", "Sierra Laser", -1);

    priority_queue<NOM_AP<int>, vector<NOM_AP<int>>, comp<NOM_AP<int>> >cola;

    cola.push(nom1);
    cola.push(nom2);
    cola.push(nom3);
    cola.push(nom4);
    cola.push(nom5);
    
    while (!cola.empty()) {

        cout << cola.top().apellidos << " " << cola.top().nombre << endl;
        cola.pop();
    }
}