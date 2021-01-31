#include<vector>
#include<map>
#include<iostream>

using namespace std;

vector<pair<pair<float, float>, int> > contar(const vector< pair<float, float> > &v) {

    vector<pair<pair<float, float>, int> > salida;
    map<pair<float, float>, int> dic;

    if (v.size() > 0){    

        for (vector< pair<float, float> >::const_iterator it = v.cbegin(); it != v.cend(); it++) //n
            dic[*it]++; //log n
        
        typename map<pair<float, float>, int>::iterator d_it = dic.begin();

        while (d_it != dic.end()) { //n
            
            salida.push_back(*d_it);
            d_it++;
        }
    }

    return salida;
}

int main() {

    vector<pair<pair<float, float>, int>>::iterator it;

    vector<pair<float, float>> vector2;
    vector<pair<pair<float, float>, int>> vector;
    
    vector2.push_back(pair<float,float>(3, 4));
    vector2.push_back(pair<float,float>(3, 5));
    vector2.push_back(pair<float,float>(6, 8));
    vector2.push_back(pair<float,float>(3, 2));
    vector2.push_back(pair<float,float>(9, 4));
    vector2.push_back(pair<float,float>(2, 7));
    vector2.push_back(pair<float,float>(2, 7));
    vector2.push_back(pair<float,float>(3, 4));
    vector2.push_back(pair<float,float>(6, 8));
    vector2.push_back(pair<float,float>(1, 4));
    vector2.push_back(pair<float,float>(9, 4));
    vector2.push_back(pair<float,float>(5, 2));
    vector2.push_back(pair<float,float>(6, 8));

    vector = contar(vector2);

    it = vector.begin();

    cout << "Prueba 1, caso normal: " << endl;

    while (it != vector.end()) {
        cout << it->first.first << " " << it->first.second << " ha aparecido " << it->second << " veces" << endl;
        it++;
    }

    vector2.clear();

    vector = contar(vector2);

    it = vector.begin();

    cout << "Prueba 2, vector vacío: " << endl;

    while (it != vector.end()) {
        cout << it->first.first << " " << it->first.second << " ha aparecido " << it->second << " veces" << endl;
        it++;
    }

    vector2.clear();
    vector2.push_back(pair<float,float>(6, 8));

    vector = contar(vector2);

    it = vector.begin();

    cout << "Prueba 3, un unico elemento: " << endl;

    while (it != vector.end()) {
        cout << it->first.first << " " << it->first.second << " ha aparecido " << it->second << " veces" << endl;
        it++;
    }
}