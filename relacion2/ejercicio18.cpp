#include<vector>
#include<iostream>

using namespace std;
template<typename T>
void intercalar(vector<T> &v, vector<pair<int, T> > pos) {

    for (typename vector< pair<int, T> >::const_iterator it = pos.cbegin(); it != pos.cend(); it++) {

        if (it->first <= v.size() && it->first >= 0) {
            typename vector<T>::iterator vit = v.begin();
            for (int i = 0; i < it->first; i++)
                vit++;
            v.insert(vit, it->second);
        }
    }
}

int main() {

    vector<int> v;
    vector<pair<int, int> > pos;

    v.push_back(5);
    v.push_back(8);
    v.push_back(1);
    v.push_back(9);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);

    pos.push_back(pair<int, int>(0, 9));
    pos.push_back(pair<int, int>(-1, 15)); //no se mete por ser menor que 0
    pos.push_back(pair<int, int>(9, 22)); //no se mete por ser mayor que v.size()
    pos.push_back(pair<int, int>(8, 33));
    pos.push_back(pair<int, int>(6, 90));

    intercalar(v, pos);

    pos.clear();
    pos.push_back(pair<int, int>(9, 101)); //no se mete por salirse del rango
    pos.push_back(pair<int, int>(8, 100)); // se mete justo al final
    intercalar(v, pos);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

}