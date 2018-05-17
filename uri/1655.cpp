#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n > 0) {
        map<int, vector<pair<int, double> > > graph;

        int m;
        cin >> m;
        while(m--) {
            int a, b;
            double p;

            cin >> a >> b >> p;
            graph[a].push_back({b, p/100.0});
            graph[b].push_back({a, p/100.0});
        }

        vector<double> dist;
        vector<bool> vis;
        dist.resize(n+1, 0);
        vis.resize(n+1, false);

        priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > que;
        que.push({1, 1});
        dist[1] = 1;
        while(!que.empty()) {
            int atual = que.top().second;
            que.pop();

            if(vis[atual]) continue;

            for(int i = 0; i < graph[atual].size(); i++) {
                int vizinho = graph[atual].at(i).first;
                double custo = graph[atual].at(i).second;
            
                if(!vis[vizinho] && dist[vizinho] < dist[atual] * custo) {
                    dist[vizinho] = dist[atual] * custo;
                    que.push({-dist[vizinho], vizinho});
                }
            }

            vis[atual] = true;
        }

        printf("%.6lf percent\n", dist[n]*100);

        cin >> n;
    }

    return 0;
}