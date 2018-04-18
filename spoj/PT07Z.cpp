#include <bits/stdc++.h>

using namespace std;

pair<int, int> longest(map<int, pair<bool, vector<int> > > graph, int r) {
    pair<int, int> maior = {0, r}, temp;

    graph[r].first = true;

    for(int i = 0; i < graph[r].second.size(); i++) {
        if(graph[graph[r].second.at(i)].first)
            continue;

        temp = longest(graph, graph[r].second.at(i));
        if(temp.first > maior.first) {
            maior = temp;
        }
    }

    return {maior.first + 1, maior.second};
}

int main() {
    int n, m, u, v;
    map<int, pair<bool, vector<int> > > graph1, graph2;

    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        
        graph1[u].first = graph1[v].first = false;
        graph1[u].second.push_back(v);
        graph1[v].second.push_back(u);

        graph2[u].first = graph2[v].first = false;
        graph2[u].second.push_back(v);
        graph2[v].second.push_back(u);
    }

    pair<int, int> d1, d2;

    d1 = longest(graph1, u);
    d2 = longest(graph2, d1.second);

    cout << d1.first + d2.first << endl;
    
    return 0;
}
