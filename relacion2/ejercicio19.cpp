#include<vector>
#include<list>
#include<map>
#include<iostream>

using namespace std;

struct piloto {

    string nombre;
    string apellidos;
    string escuderia;
    int puntos;
};

/*Mi implementacion de este ejercicio consta en hacer una list de pilotos para almacenarlos "fisicamente"
ahi, y despues declarar 4 maps de punteros a pilotos, que apuntan a direcciones de la list principal. Con
esta aproximacion consigo una eficiencia logarítmica en todos los consultores y en el metodo de insertar pilotos
sacrifico un poco de eficiencia, quedandose en 4*log(n). Me parece mejor opcion que tener una inserción log(n) pero
que luego 3 de los 4 consultores fueran lineales, que es como se quedaria si usara un unico contenedor en la clase*/

class pilotos {
private:

    list<piloto> lista_pilotos; //contenedor principal

    //contenedores de punteros a los pilotos de lista_pilotos
    map<string,piloto*> dic_apellidos;
    map<string,piloto*> dic_nombres;
    multimap<string,piloto*> dic_escuderia;
    multimap<int,piloto*, greater<int>> dic_posicion;

public:
    pilotos(){}

    piloto buscar_apellidos(string apellidos) const;

    piloto buscar_nombre(string nombre) const;

    list<piloto> buscar_escuderia(string escuderia) const;

    piloto posicion(int num) const;

    void insertar_piloto(const piloto &p);

    void cambiar_puntuacion(string apellidos, string nombre, int puntos);

    class iterator {
    public:

        iterator() {}

        iterator(multimap<int, piloto *>::const_iterator &it);

        piloto operator*();

        piloto operator++(int);

        piloto operator--(int);

        bool operator==(iterator it);

        bool operator!=(iterator it);

        void operator=(iterator &it);

    protected:
        multimap<int,piloto*, greater<int> >::const_iterator iter;
    };

    iterator begin() const;
    iterator end() const;
};//-------------------------------------------------

piloto pilotos::buscar_apellidos(string apellidos) const {

        map<string,piloto*>::const_iterator it = dic_apellidos.find(apellidos);
        piloto salida;
        
        if (it != dic_apellidos.cend())
            salida = *(it->second);

        return salida;
    }

piloto pilotos::buscar_nombre(string nombre) const {

        map<string,piloto*>::const_iterator it = dic_nombres.find(nombre);
        piloto salida;
        
        if (it != dic_nombres.cend())
            salida = *(it->second);

        return salida;
    }

list<piloto> pilotos::buscar_escuderia(string escuderia) const {

        multimap<string,piloto*>::const_iterator it = dic_escuderia.find(escuderia);
        list<piloto> salida;

        if (it != dic_escuderia.cend()){

            while (it->first == escuderia) {
                salida.push_back(*(it->second));
                it++;
            }
        }
        
        return salida;
    }

piloto pilotos::posicion(int num) const {

        //multimap<int,piloto*, greater<int>>::iterator = dic_posicion.begin() ;
        multimap<int, piloto*>::const_iterator it = dic_posicion.cbegin();
        piloto salida;
        
        if (num > 0 && num <= lista_pilotos.size()){

            for (int i = 0; i < (num-1); i++)
                it++;
        
            if (lista_pilotos.size() > 0) salida = *(it->second);
        }

        return salida;
    }

void pilotos::insertar_piloto(const piloto &p) {

        lista_pilotos.push_back(p);

        piloto *pa = &(lista_pilotos.back());

        dic_apellidos.insert (pair<string,piloto*>(p.apellidos, pa));
        dic_nombres.insert (pair<string,piloto*>(p.nombre, pa));
        dic_escuderia.insert (pair<string,piloto*>(p.escuderia, pa));
        dic_posicion.insert (pair<int,piloto*>(p.puntos, pa));

    }

void pilotos::cambiar_puntuacion(string apellidos, string nombre, int puntos) {

    piloto *p = dic_apellidos.find(apellidos)->second; 
}

pilotos::iterator pilotos::begin() const{
    multimap<int, piloto*>::const_iterator it(dic_posicion.cbegin());
    return iterator(it);
}

pilotos::iterator pilotos::end() const{
    multimap<int, piloto*>::const_iterator it(dic_posicion.cend());
    return iterator(it);
}



pilotos::iterator::iterator(multimap<int,piloto*, greater<int> >::const_iterator &it) {
    iter = it;
}

piloto pilotos::iterator::operator*() {
    return *(iter->second);
}

piloto pilotos::iterator:: operator++(int){
    return *(iter++->second);
}

piloto pilotos::iterator:: operator--(int){
    return *(iter--->second);
}

bool pilotos::iterator::operator==(iterator it) {
    return iter == it.iter;
}

bool pilotos::iterator::operator!=(iterator it) {
    return iter != it.iter;
}

void pilotos::iterator::operator=(iterator &it) {
    iter = it.iter;
}



int main() {

    pilotos pole;
    piloto alonso, botas, hamilton, carlos;

    alonso.apellidos = "Alonso";
    alonso.nombre = "Fernando";
    alonso.escuderia = "Renault";
    alonso.puntos = 200;

    botas.apellidos = "Bottas";
    botas.nombre = "Valteri";
    botas.escuderia = "Mercedes";
    botas.puntos = 300;

    hamilton.apellidos = "Hamilton";
    hamilton.nombre = "Lewis";
    hamilton.escuderia = "Mercedes";
    hamilton.puntos = 0;

    carlos.apellidos = "Sainz";
    carlos.nombre = "Carlos";
    carlos.escuderia = "Ferrari";
    carlos.puntos = 150;

    pole.insertar_piloto(alonso);
    pole.insertar_piloto(botas);
    pole.insertar_piloto(hamilton);
    pole.insertar_piloto(carlos);

    cout << (pole.posicion(1).apellidos) << endl;
    cout << (pole.buscar_apellidos("Alonso").nombre) << endl;
    cout << (pole.buscar_apellidos("Hamilton").escuderia) << endl;
    cout << (pole.buscar_nombre("Carlos").apellidos) << endl;
    cout << (pole.buscar_nombre("Millan").apellidos) << endl; //no existe

    list<piloto> mercedes = pole.buscar_escuderia("Mercedes");

    cout << "Pilotos de mercedes:\n";
    for (list<piloto>::iterator it = mercedes.begin(); it != mercedes.end(); it++)
        cout << "   " << it->nombre << " " << it->apellidos << endl;

    cout << "\nClasificacion de la temporada:\n";

    pilotos::iterator it = pole.begin();
    pilotos::iterator ot = pole.end();
    while (it != pole.end()) {
        cout << (*it).nombre << " " << (*it).apellidos << endl;
        it++;
    }
}