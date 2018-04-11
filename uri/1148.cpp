#include <bits/stdc++.h>

using namespace std;

map<int, vector<pair<int, int> > > graph; // i -> adjascentes (no, hora)
bool * visitado;

int min(int o, int d) {
    int min_h;
    int tmp_min;
    
    if(o == d) {
        return 0;
    }
    
    if(graph[o].size() == 0 || visitado[o]) {
        return -1;
    }
    
    visitado[o] = true;
    
    min_h = graph[o].at(0).second + min(graph[o].at(0).first, d);
    for(int i = 1; i < graph[o].size(); i++) {
        tmp_min = min(graph[o].at(i).first, d);
        if((min_h == -1 && tmp_min >= 0) || min_h > tmp_min) {
            min_h = graph[o].at(i).second + tmp_min;
        }
    }

    return min_h;
}

int main() {
    int n, e, x, y, h, k, o, d, res;

    cin >> n >> e;
    
    while(n != 0 | e != 0) {
        while(e--) {
            cin >> x >> y >> h;
            
            graph[x].push_back({y, h});
            graph[y].push_back({x, h});
        }
        
        visitado = (bool *) calloc(graph.size(), graph.size() * sizeof(bool));
        
        cin >> k;
        while(k--) {
            cin >> o >> d;
            
            res = min(o, d);
            
            if(res == -1) {
                cout << "Nao e possivel entregar a carta" << endl;
            } else {
                cout << res << endl;
            }
        }
        
        free(visitado);
        cout << endl;
    }
    
    return 0;
}
