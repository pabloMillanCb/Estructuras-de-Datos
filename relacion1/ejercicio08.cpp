#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

bool palindromo(string cadena) {

    stack<char> pila;
    queue<char> cola;
    bool palindromo = cadena.size() > 0;
    string tmp = "";

    /*El siguiente bucle tiene la funcion de eliminar los espacios del string.
    Hace que este peor optimizada la funcion, pero es la unica forma de hacer
    que funcione tambien para palindromos con espacio. Podriamos ahorrarnos este
    bucle si se pudieran usar dos colas o dos pilas, pero como hay que usar una de
    cada, no he encontrado otra manera de que luego en un solo recorrido del string
    cada contenedor pille exactamente la mitad de las palabras*/

    for (int i = 0; i < cadena.size(); i++) 
        if (cadena[i] != ' ') tmp += cadena[i];

    int n = tmp.size()/2+(tmp.size()%2!=0)*1;
    

    for (int i = 0; i < tmp.size()/2 && palindromo; i++){
        
        pila.push(tmp[i]);
        cola.push(tmp[i+n]);
    }

    while (!pila.empty() && palindromo) {
        
        palindromo = pila.top() == cola.front();
        pila.pop(); cola.pop();
    }

    return palindromo;
}

int main() {

    string cad1 = "senorgolosologrones", cad2 = "hoaloh", cad3 = "soolloos", cad4 = "popop", cad5 = " ", 
    cad6 = "senor goloso logrones se es o no se es somos o no somos senor goloso logrones";

    cout << cad1 << ": " << palindromo(cad1) << endl;
    cout << cad2 << ": " << palindromo(cad2) << endl;
    cout << cad3 << ": " << palindromo(cad3) << endl;
    cout << cad4 << ": " << palindromo(cad4) << endl;
    cout << cad5 << ": " << palindromo(cad5) << endl;
    cout << cad6 << ": " << palindromo(cad6) << endl;

}