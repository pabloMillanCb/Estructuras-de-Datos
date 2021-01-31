#include<map>
#include<string>
#include<iostream>

using namespace std;

string desencripta(string cad, const map<char, char> &codigo) {

    string out = "";
    map<char, char> anticodigo;

    /*como para buscar un valor (no clave) en un map hay que recorrerlo linealmente
    cada vez que se busca un elemento, he optado por siempre traducir el map original
    a uno en el que las claves sean valores y viceversa. Así lo recorro una única vez
    y el resto de accesos serán O(log n). Esto será más beneficioso cuanto más largo
    sea el string a desencriptar*/

    for (map<char, char>::const_iterator i = codigo.cbegin(); i != codigo.cend(); i++)
        anticodigo[i->second] = i->first;

    for (int i = 0; i < cad.size(); i++){

        if (anticodigo.find(cad[i]) == anticodigo.end())
            out += cad[i];
        else
            out += anticodigo.find(cad[i])->second;
        
    }

    return out;
}

int main() {

    /*Para las pruebas usaremos unicamente los caracteres
    'qwerty' para el diccionario y se traduciran a 'asdfgh'*/

    map<char, char> encriptacion;

    encriptacion['q'] = 'a'; encriptacion['w'] = 's';
    encriptacion['e'] = 'd'; encriptacion['r'] = 'f';
    encriptacion['t'] = 'g'; encriptacion['y'] = 'h';

    string s1 = "asdfgh";
    string s2 = "hgfdsa";
    string s3 = "";
    string s4 = "asdfgu";
    string s5 = "uiopñ";

    cout << s1 << " se traduce en " << desencripta(s1, encriptacion) << endl;
    cout << s2 << " se traduce en " << desencripta(s2, encriptacion) << endl;
    cout << s3 << " se traduce en " << desencripta(s3, encriptacion) << endl;
    cout << s4 << " se traduce en " << desencripta(s4, encriptacion) << endl;
    cout << s5 << " se traduce en " << desencripta(s5, encriptacion) << endl;
}