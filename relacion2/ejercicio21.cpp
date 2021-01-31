#include<vector>
#include<list>
#include<map>
#include<iostream>

using namespace std;

struct paciente {

    string nombre;
    string apellidos;
    string dni;
    int gravedad;
};

/*Declaro una lista de pacientes y 2 maps de punteros a pacientes para hacer
busquedas mas rapidas y ahorrar espacio. Esos dos maps están encadenados a un
iterador por cada paciente, para poder hacer los borrados eficientes.*/

class urgencias {

private:

    typedef list<paciente>::iterator it_paciente;
    typedef multimap<string, pair<paciente*, it_paciente>>::iterator it_apell;

    multimap<int, pair<paciente*, it_apell>, greater<int>> orden_urgencia;
    multimap<string, pair<paciente*, it_paciente>> orden_apellidos;

    list<paciente> pacientes;

public:

    urgencias() {}

    void insertar_paciente(const paciente &p) {

        pacientes.push_back(p);
        it_paciente pac = pacientes.end(); pac--;
        paciente *pa = &(pacientes.back());

        pair<string, pair<paciente*, it_paciente> > par_apellidos(p.apellidos, pair<paciente*, it_paciente>(pa, pac));
        it_apell it = orden_apellidos.insert(par_apellidos);

        pair<int, pair<paciente*, it_apell>> par_urgencia(p.gravedad, pair<paciente*, it_apell>(pa, it));
        orden_urgencia.insert(par_urgencia);
    }

    paciente mas_grave() {

        paciente salida;
        if (this->size() > 0){

            it_apell i_apell = (orden_urgencia.begin()->second).second;
            it_paciente i_paciente = (i_apell->second).second;
            salida = *((orden_urgencia.begin()->second).first);

            orden_apellidos.erase(i_apell);
            orden_urgencia.erase(orden_urgencia.begin());
            pacientes.erase(i_paciente);
        }

        return salida;
    }

    paciente buscar_paciente(string nombre, string apellidos) const {

        paciente salida;

        if (this->size() > 0){

            multimap<string, pair<paciente*, it_paciente>>::const_iterator it = orden_apellidos.find(apellidos);
            while (it != orden_apellidos.cend()) {

                paciente tmp = *(it->second.first);
                if (tmp.apellidos == apellidos && tmp.nombre == nombre){

                    salida = tmp;
                    it = orden_apellidos.cend();
                }
            }
        }

        return salida;
    }

    int size() const{
        return pacientes.size();
    }
    
    class iterator {
    protected:

        multimap<string, pair<paciente*, it_paciente>>::const_iterator iter; 

    public:

        iterator() {}

        iterator(multimap<string, pair<paciente*, it_paciente>>::const_iterator& it) {
            iter = it;
        }

        paciente operator++(int) {
            return *((iter++->second).first);
        }

        paciente operator--(int) {
            return *((iter--->second).first);
        }

        paciente operator*() {
            return *((iter->second).first);
        }

        bool operator==(iterator &it) {
            return iter == it.iter;
        }

        bool operator==(iterator it) {
            return iter == it.iter;
        }

        bool operator !=(iterator &it) {
            return iter != it.iter;
        }

        bool operator !=(iterator it) {
            return iter != it.iter;
        }

        void operator=(iterator &it) {

            iter = it.iter;
        }

        void operator=(iterator it) {

            iter = it.iter;
        }

    };

    iterator begin() const {
        multimap<string, pair<paciente*, it_paciente>>::const_iterator i(orden_apellidos.cbegin());
        iterator it(i);
        return it;
    }

    iterator end() const {
        multimap<string, pair<paciente*, it_paciente>>::const_iterator i(orden_apellidos.cend());
        iterator it(i);
        return it;
    }

};

int main() {


    urgencias hospital;
    paciente p;

    cout << hospital.size() << endl;

    p.nombre = "Pablo";
    p.apellidos = "Millan Cubero";
    p.dni ="999999999";
    p.gravedad = 10;

    hospital.insertar_paciente(p);
    cout << hospital.size() << endl;

    p.nombre = "Antonio";
    p.apellidos = "Sanchez Alcaraz";
    p.dni ="999999999";
    p.gravedad = 5;

    hospital.insertar_paciente(p);
    cout << hospital.size() << endl;

    p.nombre = "Sasel";
    p.apellidos = "Landia";
    p.dni ="999999999";
    p.gravedad = 100;

    hospital.insertar_paciente(p);
    cout << hospital.size() << endl;

    p.nombre = "Jordi";
    p.apellidos = "Conde Molina";
    p.dni ="999999999";
    p.gravedad = 15;

    hospital.insertar_paciente(p);
    cout << hospital.size() << endl;

    urgencias::iterator it = hospital.begin(), it2 = it;

    cout << "Orden por apellidos:\n";

    while (it != hospital.end()) {
        cout << (*it).apellidos << " " << (*it).nombre << endl;
        it++;
    }
    cout << (it == hospital.end());

    cout << "\nAtendemos por orden de urgencias:\n";

    while (hospital.size() > 0) {
        paciente tmp = hospital.mas_grave();
        cout << "Se atiende a " << tmp.nombre << " con urgencia " << tmp.gravedad << endl;
        cout << "Quedan " << hospital.size() << endl;
    }

}