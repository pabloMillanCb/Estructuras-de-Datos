#include <iostream>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
void insertar(queue<T> &P, int pos, const T &x) {

    queue<T> ret;
    int i = 0, size = P.size();

    while (!P.empty()) {
        

        if (i == pos)
            ret.push(x);
        else{
            ret.push(P.front());
            P.pop();
        }
        i++;
    }

    if (size == ret.size())
        ret.push(x);

    P = ret;
}

int main() {

    

}