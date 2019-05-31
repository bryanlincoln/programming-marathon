#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k, c, s;

    cin >> n >> k;
    
    while(n != 0 && k != 0) {
        stack<pair<int, int> > fila;
        bool deu = true;

        while(n--) {
            cin >> c >> s;

            while(fila.size() > 0 && fila.top().second <= c) {
                fila.pop();
            }

            if(fila.size() > 0 && (fila.size() >= k || s > fila.top().second))
                deu = false;

            fila.push({c, s});
        }

        if(deu)
            cout << "Sim" << endl;
        else
            cout << "Nao" << endl;
        
        cin >> n >> k;
    }

    return 0;
}