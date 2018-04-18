#include <bits/stdc++.h>

using namespace std;

map<int, pair<bool, vector<int> > > graph;

pair<int, int> longest(int r) {
    pair<int, int> maior = {0, r}, temp;

    graph[r].first = true;

    for(int i = 0; i < graph[r].second.size(); i++) {
        if(graph[graph[r].second.at(i)].first)
            continue;

        temp = longest(graph[r].second.at(i));
        if(temp.first > maior.first) {
            maior = temp;
        }
    }

    return {maior.first + 1, maior.second};
}

int main() {
    int n, m, u, v;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        
        graph[u].first = graph[v].first = false;
        graph[u].second.push_back(v);
        graph[v].second.push_back(u);
    }

    pair<int, int> d1, d2;

    d1 = longest(u);
    d2 = longest(d1.second);

    cout << d1.first + d2.first << endl;
    
    return 0;
}
