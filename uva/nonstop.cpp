#include <bits/stdc++.h>

using namespace std;

int main() {
    int ni, ncase = 1;

    while(cin >> ni && ni) {
        map<int, vector<pair<int, int> > > graph; // from -> [to, cost]

        for(int i = 1; i <= ni; i++) {
            int roads;
            cin >> roads;

            while (roads > 0) {
                int outroad, cost;
                cin >> outroad >> cost;
                graph[i].push_back({outroad, cost});
                roads--;
            }
        }

        int s, t;
        cin >> s >> t;

        priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > que;
        vector<bool> vis;
        vector<int> dist;
        vector<int> pred;

        dist.resize(ni + 1, INT_MAX);
        pred.resize(ni + 1, INT_MAX);
        vis.resize(ni + 1, false);

        que.push({0, s});
        dist[s] = 0;
        pred[s] = -1;

        while(!que.empty()) {
            int atual = que.top().second;
            que.pop();

            if(vis[atual]) continue;

            for(int i = 0; i < graph[atual].size(); i++) {
                int vizinho = graph[atual].at(i).first;
                int cost = graph[atual].at(i).second;

                if(dist[vizinho] > dist[atual] + cost) {
                    dist[vizinho] = dist[atual] + cost;
                    pred[vizinho] = atual;
                    que.push({dist[vizinho], vizinho});
                }
            }

            vis[atual] = true;
        }

        vector<int> path;
        int atual = t;
        do {
            path.insert(path.begin(), atual);
            atual = pred[atual];
        } while(atual > -1);

        cout << "Case " << ncase << ": Path =";
        for(int i = 0; i < path.size(); i++) cout << " " << path[i];
        cout << "; " << dist[t] << " second delay" << endl;
        ncase++;
    }

    return 0;
}