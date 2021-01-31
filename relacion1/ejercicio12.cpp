#include<iostream>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

class comp {
public:
    bool operator()(const string a, const string b) {

        bool greater;

        if (a.size() == b.size()) {

            bool equals = true;
            int i = 0;
            while (i < min(a.size(), b.size()) && equals) {

                equals = a[i] == b[i];
                greater = a[i] > b[i];
                i++;
            }
        }

        else
            greater = a.size() < b.size();

        return greater;
    }
};

int main() {

    priority_queue<string, vector<string>, comp > cola;

    cola.push("cocacola");
    cola.push("pedagogico");
    cola.push("epico");
    cola.push("goku");
    cola.push("prestidigitador");
    cola.push("finzo");
    cola.push("funzo");
    cola.push(" ");
    cola.push("");

    while (!cola.empty()) {

        cout << cola.top() << endl;
        cola.pop();
    }
}