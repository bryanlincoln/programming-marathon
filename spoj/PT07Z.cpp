#include <bits/stdc++.h>

using namespace std;

map<int, pair<bool, vector<int> > > graph; // nó - visitado - lista de nós conectados

pair<int, int> longest(int r) {
    graph[r].first = true;

    if(graph[r].second.size() == 0)
        return {0, 0};

    pair<int, int> maiores = {0, 0}, temp;
    for(int i = 0; i < graph[r].second.size(); i++) {
        if(!graph[graph[r].second.at(i)].first) {
            temp = longest(graph[r].second.at(i));

            if(temp.first + 1 > maiores.first) {
                if(temp.second > maiores.second)
                    maiores = temp;
                else
                    maiores.first = temp.first;
            } 
            else if(temp.first > maiores.second)
                maiores.second = temp.first;
        }
    }

    return {maiores.first, maiores.second};
}

int main() {
    int n;
    int u, v;

    cin >> n;
    
    while(n--) {
        cin >> u >> v;
        graph[u].first = graph[v].first = false;
        graph[u].second.push_back(v);
        graph[v].second.push_back(u);
    }
    
    pair<int, int> r = longest(u);

    cout << r.first + r.second << endl;
    
    return 0;
}
