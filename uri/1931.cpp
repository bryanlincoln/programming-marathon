#include <bits/stdc++.h>
using namespace std;
#define N 10002

int pred[N];

long dijkstra(map<int, vector<pair<int, int> > > graph, int c) {
    int dist[N];
    bool vis[N];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    
    for(int i = 1; i <= c; i++) {
        dist[i] = 1e9;
        vis[i] = false;
    }

    dist[1] = 0;
    que.push({0, 1});
    while(!que.empty()) {
        int atual = que.top().second;
        que.pop();

        if(vis[atual]) continue;

        for(int i = 0; i < graph[atual].size(); i++) {
            int vizinho = graph[atual].at(i).first;
            int custo = graph[atual].at(i).second;
            if(!vis[atual] && dist[vizinho] > dist[atual] + custo && (vizinho != c || (pred[atual] + 1) % 2 == 0)) {
                dist[vizinho] = dist[atual] + custo;
                pred[vizinho] = pred[atual] + 1;
                que.push({-dist[vizinho], vizinho});
            }
        }
        vis[atual] = true;
    }

    return dist[c];
}

int main() {
    int c, v;
    map<int, vector<pair<int, int> > > graph;
    cin >> c >> v;

    for(int i = 0; i < v; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    long min = dijkstra(graph, c);

    if(min < 1e9) cout << min << endl;
    else cout << "-1" << endl;

    return 0;
}