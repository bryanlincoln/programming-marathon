#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, totaldist;
    map<string, vector<string> > graph;
    cin >> n >> m;

    while(m--) {
        string a, b;

        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    priority_queue< pair<int, string>, vector< pair<int, string> >, greater< pair<int, string> > > que;
    map<string, int> dist;
    map<string, bool> vis;

    dist["Entrada"] = 0;
    que.push({0, "Entrada"});
    while(!que.empty()) {
        string atual = que.top().second;
        que.pop();

        if(vis[atual]) continue;
        vis[atual] = true;

        for(int i = 0; i < graph[atual].size(); i++) {
            string vizinho = graph[atual].at(i);
            if(!vis[vizinho] && (dist[vizinho] == 0 || dist[vizinho] > dist[atual] + 1)) {
                dist[vizinho] = dist[atual] + 1;
                que.push({dist[vizinho], vizinho});
            }
        }
    }
    totaldist = dist["*"];

    map<string, int> dist2;
    map<string, bool> vis2;
    dist2["*"] = 0;
    que.push({0, "*"});
    while(!que.empty()) {
        string atual = que.top().second;
        que.pop();

        if(vis2[atual]) continue;
        vis2[atual] = true;

        for(int i = 0; i < graph[atual].size(); i++) {
            string vizinho = graph[atual].at(i);
            if(!vis2[vizinho] && (dist2[vizinho] == 0 || dist2[vizinho] > dist2[atual] + 1)) {
                dist2[vizinho] = dist2[atual] + 1;
                que.push({dist2[vizinho], vizinho});
            }
        }
    }
    totaldist += dist2["Saida"];

    cout << totaldist << endl;

    return 0;
}