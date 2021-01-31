#include<map>
#include<string>
#include<iostream>

using namespace std;

map<string, string> params(string cad) {

    int i = 0;
    string param = "";
    string opcion = "";
    map<string, string> salida;

    while (cad[i] != ' ' && i < cad.size()){

        if (cad[i] == '-')
            i = cad.size();
        i++;
    };

    while (i < cad.size()) {

        while (cad[i] == ' ' && i < cad.size())
            i++;

        if (cad[i] == '-' && i < cad.size()){

            param = "";

            while (cad[i] != ' ' && i < cad.size()){

                param += cad[i];
                i++;
            }

            salida[param];
        }

        else if ( i < cad.size() && param != "") {

            opcion = "";

            while (cad[i] != ' ' && i < cad.size()){

                opcion += cad[i];
                i++;
            }
            
            salida[param] = opcion;
            param = "";
        }

        i++;
    }

    return salida;
}

int main() {

    string s1 = "tar -z -x -f fichero",
           s2 = "tar",
           s3 = "tar fichero fichero",
           s4 = "tar -z fichero directorio -f",
           s5 = "tar -z fichero -z directorio",
           s6 = "-z tar -z fichero",
           s7 = "";
    map<string, string> mapa;

    cout << "Para el caso " << s1 << endl;
    mapa = params(s1);

    for (map<string, string>::iterator i = mapa.begin(); i != mapa.end(); i++) {

        cout << i->first << " con operador " << i-> second << endl;
    }

    cout << "----------------" <<endl;

    cout << "Para el caso " << s2 << endl;
    mapa = params(s2);

    for (map<string, string>::iterator i = mapa.begin(); i != mapa.end(); i++) {

        cout << i->first << " con operador " << i-> second << endl;
    }

    cout << "----------------" <<endl;

    cout << "Para el caso " << s3 << endl;
    mapa = params(s3);

    for (map<string, string>::iterator i = mapa.begin(); i != mapa.end(); i++) {

        cout << i->first << " con operador " << i-> second << endl;
    }

    cout << "----------------" <<endl;

    cout << "Para el caso " << s4 << endl;
    mapa = params(s4);

    for (map<string, string>::iterator i = mapa.begin(); i != mapa.end(); i++) {

        cout << i->first << " con operador " << i-> second << endl;
    }

    cout << "----------------" <<endl;

    cout << "Para el caso " << s5 << endl;
    mapa = params(s5);

    for (map<string, string>::iterator i = mapa.begin(); i != mapa.end(); i++) {

        cout << i->first << " con operador " << i-> second << endl;
    }

    cout << "----------------" <<endl;

    cout << "Para el caso " << s6 << endl;
    mapa = params(s6);

    for (map<string, string>::iterator i = mapa.begin(); i != mapa.end(); i++) {

        cout << i->first << " con operador " << i-> second << endl;
    }

    cout << "----------------" <<endl;

    cout << "Para el caso " << s7 << endl;
    mapa = params(s7);

    for (map<string, string>::iterator i = mapa.begin(); i != mapa.end(); i++) {

        cout << i->first << " con operador " << i-> second << endl;
    }

    cout << "----------------" <<endl;


}