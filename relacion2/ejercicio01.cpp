#include<map>
#include<string>
#include<iostream>

using namespace std;

string encripta(string cad, const map<char, char> &codigo) {

    string out = "";

    for (int i = 0; i < cad.size(); i++){

        if (codigo.find(cad[i]) == codigo.end())
            out += cad[i];
        else
            out += codigo.find(cad[i])->second;
    
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

    string s1 = "qwerty";
    string s2 = "ytrewq";
    string s3 = "";
    string s4 = "qwertu";
    string s5 = "uiopñ";

    cout << s1 << " se traduce en " << encripta(s1, encriptacion) << endl;
    cout << s2 << " se traduce en " << encripta(s2, encriptacion) << endl;
    cout << s3 << " se traduce en " << encripta(s3, encriptacion) << endl;
    cout << s4 << " se traduce en " << encripta(s4, encriptacion) << endl;
    cout << s5 << " se traduce en " << encripta(s5, encriptacion) << endl;
}