#include <bits/stdc++.h>
using namespace std;
#define N 10002

int pred[N];

int main() {
    int c, v;
    map<int, vector<pair<int, int> > > graph;
    cin >> c >> v;

    for(int i = 0; i < v; i++) {
        int a, b, custo;
        cin >> a >> b >> custo;
        graph[a].push_back({b, custo});
        graph[b].push_back({a, custo});
    }

    vector<int> dist;
    vector<bool> vis;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    dist.resize(c+10, 1e9);
    vis.resize(c+10, false);

    dist[1] = 0;
    que.push({0, 1});
    while(!que.empty()) {
        int atual = que.top().second;
        que.pop();

        if(vis[atual]) continue;

        for(int i = 0; i < graph[atual].size(); i++) {
            int vizinho = graph[atual].at(i).first;
            int custo = graph[atual].at(i).second;
            if(!vis[atual] && dist[vizinho] > dist[atual] + custo && (vizinho != c || pred[atual] % 2 == 1)) {
                dist[vizinho] = dist[atual] + custo;
                pred[vizinho] = pred[atual] + 1;
                que.push({dist[vizinho], vizinho});
            }
        }
        vis[atual] = true;
    }

    if(dist[c] < 1e9) cout << dist[c] << endl;
    else cout << "-1" << endl;

    return 0;
}