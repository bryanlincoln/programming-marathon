#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

long dijkstra(map< int, vector<pair<int, int> > > graph, int v, int s, int f) {
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    long dist[MAX];
    bool vis[MAX];

    for(int i = 0; i < v; i++) {
        vis[i] = false;
        dist[i] = 1e9;
    }

    que.push({0, s});
    while(!que.empty()) {
        int atual = que.top().second;
        que.pop();

        if(vis[atual]) continue;

        for(int i = 0; i < graph[atual].size(); i++) {
            int vizinho = graph[atual].at(i).first;
            int custo = graph[atual].at(i).second;

            if(dist[vizinho] > dist[atual] + custo) {
                dist[vizinho] = dist[atual] + custo;
                que.push({dist[vizinho], vizinho});
            }
        }

        vis[atual] = true;
    }

    return dist[f];
}

int main() {
    ios::sync_with_stdio(0);
    int n;

    cin >> n;
    while(n--) {
        int v, e;
        map< int, vector<pair<int, int> > > graph;

        cin >> v >> e;
        for(int i = 0; i < e; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }

        for(map< int, vector<pair<int, int> > >::iterator it = graph.begin(); it != graph.end(); it++) {
            for(int i = 0; i < it->second.size(); i++)
                cout << it->first << " -> " << it->second.fisrt << " (" << it->second.second << ")" << endl;
        }
        
        int s, f;
        cin >> s >> f;

        long min = dijkstra(graph, v, s, f);

        if(min < 1e9) cout << min << endl;
        else cout << "NO" << endl;
        
    }

    return 0;
}