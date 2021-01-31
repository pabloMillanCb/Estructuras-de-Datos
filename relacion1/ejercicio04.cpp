#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class pila {

private:

    queue<T> cola1, *p1 = &cola1;
    queue<T> cola2, *p2 = &cola2;

public:

    void push(T i) {

        (*p1).push(i);
    }

    void pop() {

        queue<T> *tmp;

        while ((*p1).size() > 1){
            (*p2).push((*p1).front());
            (*p1).pop();
        }
        (*p1).pop();

        tmp = p2;
        p2 = p1;
        p1 = tmp;
    }

    int size() {
        return (*p1).size();
    }

    T top() {

        queue<T> *tmp;

        while ((*p1).size() > 1){
            (*p2).push((*p1).front());
            (*p1).pop();
        }
        
        T ret = (*p1).front();
        (*p2).push(ret);
        (*p1).pop();
        tmp = p2;
        p2 = p1;
        p1 = tmp;

        return ret;
    }

    bool empty() {
        return (*p1).size() == 0;
    }

};

int main() {



}