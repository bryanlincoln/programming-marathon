#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        map<int, vector<int> > graph;

        while(m--) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int c, r, e;
        cin >> c >> r >> e;

        vector<int> dist;
        vector<bool> vis;
        dist.resize(n+1, 1e9);
        vis.resize(n+1, false);
        
        priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
        que.push({0, c});
        dist[c] = 0;
        while(!que.empty()) {
            int atual = que.top().second;
            que.pop();

            if(vis[atual]) continue;

            for(int i = 0; i < graph[atual].size(); i++) {
                int vizinho = graph[atual].at(i);
                if(vizinho != e && !vis[vizinho] && dist[vizinho] > dist[atual] + 1) {
                    dist[vizinho] = dist[atual] + 1;
                    que.push({dist[vizinho], vizinho});
                }
            }

            vis[atual] = true;
        }

        cout << dist[r] << endl;
    }
    return 0;
}