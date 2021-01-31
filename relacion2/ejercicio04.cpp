#include<map>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

map<string,int> contar(string texto) {

    map<string, int> recuento;
    string palabra;

    for (int i = 0; i < texto.size(); i++) {

        //string s(1, texto[i]);
        if (texto[i] != ' ' && texto[i] != ',' && texto[i] != '.' && texto[i] != ':' && texto[i] != ';'){
            palabra += texto[i];
        }
        else if (palabra != ""){
            recuento[palabra]++;
            palabra = "";
        }
    }

    if (palabra != "")
        recuento[palabra]++;

    return recuento;
}

vector<string> veces(const map<string,int> &palabras, int num) {

    vector<string> salida;

    for (map<string, int>::const_iterator i = palabras.cbegin(); i != palabras.cend(); i++){

        if (i->second == num)
            salida.push_back(i->first);
    }

    return salida;
}

int main() {

    string s1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus eu risus sit amet augue dignissim facilisis eu vel dui. Mauris vel metus ac massa malesuada auctor. Quisque turpis massa, pulvinar at sollicitudin at, placerat vel magna. Nulla ut vestibulum quam. Nullam at elit sit amet tortor scelerisque ultricies. Quisque semper nisi mi, eget condimentum mauris volutpat at. Duis aliquet auctor scelerisque. Duis imperdiet commodo diam non facilisis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. ";
    string s2 = "";

    map<string, int> recuento1 = contar(s1);
    map<string, int> recuento2 = contar(s2);

    cout << "CASO 1: texto lore ipsum. Se han generado:\n";

    for (map<string, int>::iterator i = recuento1.begin(); i != recuento1.end(); i++)
        cout << i->first << " -> se ha encontrado " << i->second << " veces." << endl;
    
    cout << "\nAparecen 42 veces las siguientes palabras: ";

    vector<string> vec = veces(recuento1, 42);

    for (int i = 0 ; i < vec.size(); i++)
        cout << vec[i] << " ";

    cout << endl;

    cout << "\nAparecen 1 vez las siguientes palabras: ";

    vec = veces(recuento1, 1);

    for (int i = 0 ; i < vec.size(); i++)
        cout << vec[i] << " ";

    cout << endl;

    cout << "\nAparecen 2 veces las siguientes palabras: ";

    vec = veces(recuento1, 2);

    for (int i = 0 ; i < vec.size(); i++)
        cout << vec[i] << " ";

    cout << endl;

    cout << "\nAparecen 4 veces las siguientes palabras: ";

    vec = veces(recuento1, 4);

    for (int i = 0 ; i < vec.size(); i++)
        cout << vec[i] << " ";

    cout << endl;

}