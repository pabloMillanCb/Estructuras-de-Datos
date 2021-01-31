#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

float evalua(string expresion, int num_variables) { //pair<char, float> *variables,

    stack<char> digitos, operandos;
    float ret = 0.0;

    for (int i = 0; i < num_variables; i++) {

        char c = expresion[i];

        if (c > 47 && c < 58)
            digitos.push(c);
        else
            operandos.push(c);

        
    }

    return ret;
}

int main () {

    string operacion1 = "53^2*2/9+",
           operacion2 = "abcde+*+",
           operacion3 = "ab+cd*+e*";

           cout << evalua(operacion1, 9) << endl;



}