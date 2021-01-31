/*
PREORDEN: GEAIBMCLDFKJH
INORDEN:  IABEGLDCFMKHJ

                G
               / \
              E   M
             /   / \
            /   C   K
           /   / \   \
          /   L   F   J
          A    \     /
         / \    D   H
        I   B

POSTORDEN: IBAEDLFCHJKMG
*/

#include<string>
#include<iostream>
#include "bintree.h"

using namespace std;
string postorden(string preorden, string inorden) {
    size_t raiz = inorden.find(preorden[0]);
    if (preorden.size() <= 2) {
        return string(1, inorden[(raiz+1)%2])+inorden[raiz];
    }
    return postorden(preorden.substr(1,raiz), inorden.substr(0,raiz)) +
                postorden(
                            preorden.substr(raiz+1, preorden.size()-raiz-1),
                            inorden.substr(raiz+1, preorden.size()-raiz-1)
                            ) +
                inorden[raiz];
}

string postorden(string preorden, string inorden) {

    string salida = "", p1 = preorden, p2 = preorden, i1 = "", i2 = "";
    int t;

    t = inorden.find_first_of(preorden[0]);

    p1.erase(0, 1);
    p2.erase(0, t+1);

    for (int i = 0; i < t; i++) {
        i1 += inorden[i];
    }

    for (int i = t+1; i < inorden.size(); i++) {
        i2 += inorden[i];
    }

    if (i1.size() > 1) i1 = postorden(p1, i1); 
    if (i2.size() > 1) i2 = postorden(p2, i2);

    salida = i1+i2+preorden[0];

    return salida;
}

int main() {

    string in = "IABEGLDCFMKHJ", pre = "GEAIBMCLDFKJH";

    cout << postorden(pre, in) << endl;

    in = "AIBEGLDCFMKHJ"; pre = "GEAIBMCLDFKJH";

    cout << postorden(pre, in) << endl;

    cout << "\n\nPROGRAMA COMPROBADOR\n\n";

    bintree<char> A('G');
    bintree<char>::node n;

    A.insert_left(A.root(), 'E');
    A.insert_right(A.root(), 'M');
    n = A.root().left();
    A.insert_left(n, 'A');
    n = n.left();
    A.insert_left(n, 'I');
    A.insert_right(n, 'B');

    n = A.root().right(); //n = M
    A.insert_left(n, 'C');
    A.insert_right(n, 'K');

    A.insert_left(n.left(), 'L'); //n = C
    A.insert_right(n.left().left(), 'D'); //n = L
    A.insert_right(n.left(), 'F'); //n = C

    A.insert_right(n.right(), 'J');
    A.insert_left(n.right().right(), 'H');

    bintree<char>::preorder_iterator itpre = A.begin_preorder();
    bintree<char>::inorder_iterator itin = A.begin_inorder();
    bintree<char>::postorder_iterator itpost = A.begin_postorder();

    string inorder = "", postorder = "", preorder = "";

    while (itpre != A.end_preorder()) {

        preorder += *itpre;
        ++itpre;
    }

    while (itin != A.end_inorder()) {

        inorder += *itin;
        ++itin;
    }

    while (itpost != A.end_postorder()) {

        postorder += *itpost;
        ++itpost;
    }

    cout << "Preorden: " << preorder << endl;
    cout << "Inorden: " << inorder << endl;
    cout << "Postorden: " << postorder << endl;
    cout << "Postorden calculado: " << postorden(preorder, inorder) << endl;

    if (postorder == postorden(preorder, inorder)) {

        cout << "El programa es correcto\n";
    }
    else
    {
        cout << "El programa no es correcto\n";
    }
}

