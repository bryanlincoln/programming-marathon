#include <bits/stdc++.h>
using namespace std;
#define N 10002

int main() {
    map<int, vector<pair<int, double> > > graph;
    map<int, vector<pair<int, double> > > graph2;
    vector<double> dist;
    vector<bool> vis;
    int c, v;

    cin >> c >> v;

    for(int i = 0; i < v; i++) {
        int a, b, custo;
        cin >> a >> b >> custo;
        graph[a].push_back({b, custo});
        graph[b].push_back({a, custo});
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    vis.resize(c+1, false);
    que.push({0, 1});
    while(!que.empty()) {
        int atual = que.top().second;
        que.pop();

        if(vis[atual]) continue;

        for(int i = 0; i < graph[atual].size(); i++) {
            int vizinho = graph[atual].at(i).first;
            int custo = graph[atual].at(i).second;

            for(int j = 0; j < graph[vizinho].size(); j++) {
                int vvizinho = graph[vizinho].at(j).first;
                int vcusto = graph[vizinho].at(j).second;
                
                if(vvizinho == atual) continue;

                if(!vis[vvizinho]) {
                    graph2[atual].push_back({vvizinho, custo+vcusto});
                    graph2[vvizinho].push_back({atual, custo+vcusto});
                    que.push({0, vvizinho});
                }
            }
        }

        vis[atual] = true;
    }
    
    dist.resize(c+1, 1e9);
    vis.clear();
    vis.resize(c+1, false);
    que.push({0, 1});
    
    dist[1] = 0;
    while(!que.empty()) {
        int atual = que.top().second;
        que.pop();

        if(vis[atual]) continue;

        for(int i = 0; i < graph2[atual].size(); i++) {
            int vizinho = graph2[atual].at(i).first;
            int custo = graph2[atual].at(i).second;
            if(!vis[vizinho] && dist[vizinho] > dist[atual] + custo) {
                dist[vizinho] = dist[atual] + custo;
                que.push({dist[vizinho], vizinho});
            }
        }

        vis[atual] = true;
    }

    if(dist[c] < 1e9) cout << dist[c] << endl;
    else cout << "-1" << endl;

    return 0;
}