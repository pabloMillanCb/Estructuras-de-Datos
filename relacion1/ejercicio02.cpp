#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool parentizada(string expresion){

    stack<char> pila;
    bool correcto = true;

    for (int i = 0; i < expresion.size() && correcto; i++) {

        if (expresion[i] == '('){
            pila.push(expresion[i]);
        }else if (expresion[i] == ')'){

            if (!pila.empty())
                pila.pop();
            else
                correcto = false;
        }
        
    }

    return pila.empty() && correcto;

}

int main() {

    string s1 = "(bu(e)nas) t(ard)es", 
           s2 = "(bue(n()as) tardes)", 
           s3 = "(bue)n)as tardes)",
           s4 = ")bue)n)as tardes)",
           s5 = "buenas tardes)))))",
           s6 = "buenas tardes";


    cout <<"S1: "<< parentizada(s1) << endl;
    cout <<"S2: "<< parentizada(s2) << endl;
    cout <<"S3: "<< parentizada(s3) << endl;
    cout <<"S4: "<< parentizada(s4) << endl;
    cout <<"S5: "<< parentizada(s5) << endl;
    cout <<"S6: "<< parentizada(s6) << endl;

}