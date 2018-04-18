#include <bits/stdc++.h>

using namespace std;

int main() {
    int C, N;

    while(scanf("%d %d", &C, &N) != EOF) {
        list<pair<int, int> > livre; // início e tamanho
        list<pair<int, int> >::iterator it;
        list<pair<int, int> >::iterator inicio;
        map<int, pair<int, int> > carros; // placa, indice, tamanho
        char acao;
        int P, Q, sum = 0;

        livre.clear();
        livre.push_back({0, C});

        while(N--) {
            cin >> acao >> P;

            if(acao == 'C') {
                cin >> Q;
                for(it = livre.begin(); it != livre.end(); it++) {
                    if(it->second >= Q) {
                        carros[P] = {it->first, Q};
                        sum += 10;

                        it->first += Q;
                        it->second -= Q;

                        if(it->second <= 0) {
                            it = livre.erase(it);
                        }

                        break;
                    }
                }
            } else if(livre.size() > 0) {
                inicio = livre.end();

                for(it = livre.begin(); it != livre.end(); it++) {
                    if(it->first + it->second == carros[P].first) {
                        it->second += carros[P].second;
                        inicio = it;
                    }
                    else if(it->first >= carros[P].first + carros[P].second) {
                        if (it->first == carros[P].first + carros[P].second) {
                            if(inicio != livre.end()) {
                                inicio->second += it->second;
                                it = livre.erase(it);
                            } else {
                                it->first = carros[P].first;
                                it->second += carros[P].second;
                            }
                        }
                        else if(inicio == livre.end()) {
                            livre.insert(it, {carros[P].first, carros[P].second});
                        }

                        break;
                    }
                }
                if(it == livre.end() && inicio == livre.end()) {
                    livre.insert(it, {carros[P].first, carros[P].second});
                }
            }
            else {
                livre.push_back({carros[P].first, carros[P].second});
            }
        }

        cout << sum << endl;
    }


    return 0;
}