#include<iostream>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

class comp {
public:
    bool operator()(const string a, const string b) {

        int v_a = 0, v_b = 0;
        bool greater;

        for (int i = 0; i < max(a.size(), b.size()); i++) {

            if (i < a.size()) {
                if (tiene_vocal(a[i]))
                    v_a++;
            }

            if (i < b.size()) {
                if (tiene_vocal(b[i]))
                    v_b++;
            }
        }

        if (v_a == v_b) {

            bool equals = true;
            int i = 0;
            while (i < min(a.size(), b.size()) && equals) {

                equals = a[i] == b[i];
                greater = a[i] > b[i];
                i++;
            }
        }
        else
            greater = v_a < v_b;

        return greater;
    }
private:
    bool tiene_vocal(char c) {
        return c == 'a' || c == 'o' || c == 'i' || c == 'o' || c == 'u';
    }
};


int main() {

    priority_queue<string, vector<string>, comp > cola;

    cola.push("muercielago");
    cola.push("granada");
    cola.push("curcielago");
    cola.push("aaoeoeaoeoeoaeoaeoe");
    cola.push("sklmcml");
    cola.push("");
    cola.push("z");

    while (!cola.empty()) {

        cout << cola.top() << endl;
        cola.pop();
    }

    cout << "aaaaa" << endl;

}