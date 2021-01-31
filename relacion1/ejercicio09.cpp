#include<stack>
#include <iostream>

using namespace std;

stack< pair<int,int> > salida_laberinto(char **laberinto, int filas, int columnas) {

    stack <pair<int, int>> pila;
    stack<int> direccion;
    direccion.push(-1);
    int direc = 0;
    pair <int, int> posicion(-1, -1);
    bool salida = false, no_salida = false;

    for (int i = 0; i < filas && posicion.first == -1 ; i++) {
        for (int j = 0; j < columnas && posicion.first == -1; j++) {

            if (laberinto[i][j] == 'E'){
                posicion.first = i;
                posicion.second = j;
                pila.push(posicion);
            }
        }
    }

    if (posicion.first != -1) {

        while (!salida && !no_salida) {

            switch (direc)
            {
            case 0: //ir hacia arriba
                
                if (posicion.first > 0 && direccion.top() != 2) {
                    char c = laberinto[posicion.first-1][posicion.second];
                    if (c == '0'){

                        pila.push(posicion);
                        posicion.first -= 1;
                        direccion.push(0);

                    }
                    else if (c == 'S'){
                            salida = true;
                            pila.push(posicion);
                    }
                    else{
                        direc++;
                    }
                }

                else{
                    direc++;
                }

                break;
            case 1: // ir a la derecha

                if (posicion.second < columnas-1 && direccion.top() != 3) {
                    char c = laberinto[posicion.first][posicion.second+1];
                    if (c == '0'){

                        pila.push(posicion);
                        posicion.second += 1;
                        direccion.push(1);
                        direc = 0;

                    }
                    else if (c == 'S'){
                            salida = true;
                            pila.push(posicion);
                    }
                    else{
                        direc++;
                    }
                }

                else{
                    direc++;
                }
                
                

                break;
            case 2: //ir abajo

                if (posicion.first < filas -1 && direccion.top() != 0) {
                    char c = laberinto[posicion.first+1][posicion.second];
                    if (c == '0'){

                        pila.push(posicion);
                        posicion.first += 1;
                        direccion.push(2);
                        direc = 0;

                    }
                    else if (c == 'S'){
                            salida = true;
                            pila.push(posicion);
                    }
                    else{
                        direc++;
                    }
                }

                else{
                    direc++;
                }
                
                

                break;
            case 3: // ir a la izqueirda

                if (posicion.second > 0 && direccion.top() != 1) {
                    char c = laberinto[posicion.first][posicion.second-1];
                    if (c == '0'){

                        pila.push(posicion);
                        posicion.second -= 1;
                        direccion.push(3);
                        direc = 0;

                        
                    }
                    else if (c == 'S'){
                            salida = true;
                            pila.push(posicion);
                    }
                    else{
                        direc++;
                    }
                }

                else{
                    direc++;
                }
                
                break;
            case 4:

                char c = laberinto[posicion.first][posicion.second];
                if (c != 'E'){

                    posicion = pila.top();
                    direc = direccion.top();
                    pila.pop();
                    direccion.pop();

                    direc++;
                }
                else {
                    no_salida = true;
                }

                break;
            
            }

            cout << "Posicion = " << posicion.first << " " << posicion.second << endl;
            cout << "direc = " << direc << endl;
            int a;
            //cin >> a;
            
        }
        
    }

    return pila;

}



int main(){
    char laberinto[5][18],
    lab[6*18] = {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1',
                 '1','1','E','1','1','1','1','1','1','0','1','1','1','0','0','1','1','1',
                 '1','1','0','0','1','0','1','1','1','0','1','1','1','1','0','0','1','1',
                 '1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1','1',
                 '1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1',
                 '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'};
    
    char **lbrnt;
    
    int n = 0;

    char **m;
    int nfil = 6, ncol = 18;
    m =new char*[nfil];
    for(int i=0; i<nfil;++i)
        m[i] = new char[ncol];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 18; j++) {
            m[i][j] = lab[n];
            n++;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 18; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }

    stack< pair<int,int> > pila = salida_laberinto(m, 6, 18);

    while (!pila.empty()){
        m[pila.top().first][pila.top().second] = '@';
        pila.pop();
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 18; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }

}