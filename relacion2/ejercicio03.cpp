#include<map>
#include<string>
#include<iostream>

using namespace std;

//nota: todo parece indicar que los valores del map se inicializan todos a 0
map<string,int> contar(string texto) {

    map<string, int> recuento;
    string palabra;

    for (int i = 0; i < texto.size(); i++) {

        //string s(1, texto[i]);
        if (texto[i] != ' ' && texto[i] != ',' && texto[i] != '.' 
        && texto[i] != ':' && texto[i] != ';' && texto[i] != '-' 
        && texto[i] != '(' && texto[i] != ')' && texto[i] != '?' 
        && texto[i] != '!'){
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

int main() {

    string s1 = "Lorem ipsum dolor y sit-amet, consectetur? adipiscing? elit!. -Vivamus eu. .risus sit amet augue dignissim facilisis eu vel dui. Mauris vel metus ac massa malesuada auctor. Quisque turpis massa, pulvinar at sollicitudin at, placerat vel magna. Nulla ut vestibulum quam. Nullam at elit sit amet tortor scelerisque ultricies. Quisque semper nisi mi, eget condimentum mauris volutpat at. Duis aliquet auctor scelerisque. Duis imperdiet commodo diam non facilisis. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. ";
    string s2 = "";
    string s3 = "..,:;..:;:;.,,.,. , :; :;:, :; :; :, :;";
    string s4 = "..,:;..:;:;.,,.,. , :; :;:, :; :; :, :;buenas tardes buenas";

    map<string, int> recuento1 = contar(s1);
    map<string, int> recuento2 = contar(s2);
    map<string, int> recuento3 = contar(s3);
    map<string, int> recuento4 = contar(s4);

    cout << "CASO 1: texto lore ipsum. Se han generado:\n";

    for (map<string, int>::iterator i = recuento1.begin(); i != recuento1.end(); i++)
        cout << i->first << " -> se ha encontrado " << i->second << " veces." << endl;

    cout << endl << endl;
    
    cout << "CASO 2: texto vacío. Se han generado:\n";

    for (map<string, int>::iterator i = recuento2.begin(); i != recuento2.end(); i++)
        cout << i->first << " -> se ha encontrado " << i->second << " veces." << endl;

    cout << endl << endl;

    cout << "CASO 3: texto sin palabras. Se han generado:\n";

    for (map<string, int>::iterator i = recuento3.begin(); i != recuento3.end(); i++)
        cout << i->first << " -> se ha encontrado " << i->second << " veces." << endl;

    cout << endl << endl;

    cout << "CASO 4: Palabra al final del texto. Se han generado:\n";

    for (map<string, int>::iterator i = recuento4.begin(); i != recuento4.end(); i++)
        cout << i->first << " -> se ha encontrado " << i->second << " veces." << endl;

    cout << endl << endl;

}