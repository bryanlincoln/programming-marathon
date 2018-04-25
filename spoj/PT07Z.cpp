#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

map<int, vector<int>> graph;
bool vis[MAX] = {false};

int deepness(int * raiz, bool visitado) {
    int atual = *raiz;

    vis[atual] = visitado;

    int maiorId = atual, maiorPath = 0;
    for(int i = 0; i < graph[atual].size(); i++) {
        if(vis[graph[atual].at(i)] == visitado) continue;
        int temp = graph[atual].at(i);
        int r = deepness(&temp, visitado);
        if(maiorPath < r) {
            maiorId = temp;
            maiorPath = r;
        }
    }

    *raiz = maiorId;

    return maiorPath + 1;
}

int main() {
    int N;

    cin >> N;
    N--;
    while(N--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int raiz = graph.begin()->first;
    int first = deepness(&raiz, true);
    int second = deepness(&raiz, false);

    cout << second - 1 << endl;

    return 0;
}