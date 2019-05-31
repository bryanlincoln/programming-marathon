#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    for(int Case = 1; Case <= N; Case++) {
        int n, m, S, T;
        map<int, vector<pair<int, int> > > graph;

        cin >> n >> m >> S >> T;

        while(m--) {
            int a, b, cost;
            cin >> a >> b >> cost;
            graph[a].push_back({b, cost});
            graph[b].push_back({a, cost});
        }

        vector<int> dist(n+1, INT_MAX);
        vector<bool> vis(n+1, false);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;

        que.push({0, S});
        dist[S] = 0;

        while(!que.empty()) {
            int atual = que.top().second;
            que.pop();

            if(vis[atual]) continue;
            vis[atual] = true;

            for(auto vizinho : graph[atual]) {
                if(!vis[vizinho.first] && dist[vizinho.first] > dist[atual] + vizinho.second) {
                    dist[vizinho.first] = dist[atual] + vizinho.second;
                    que.push({dist[vizinho.first], vizinho.first});
                }
            }
        }

        cout << "Case #" << Case << ": ";
        if(dist[T] < 1e9) cout << dist[T] << endl;
        else cout << "unreachable" << endl;
    }
    return 0;
}