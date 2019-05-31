#include <bits/stdc++.h>
#define M 101
using namespace std;

int n, graph[M][M];
bool vis[M];

int main() {
    cin >> n;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            string cost;
            int icost;

            cin >> cost;

            if(cost == "x") icost = 1e9;
            else icost = atoi(cost.c_str());

            graph[i][j] = graph[j][i] = icost;
        }
    }

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > que;
    vector<int> dist(n, 1e9);
    que.push({0, 0});
    dist[0] = 0;

    while(!que.empty()) {
        int atual = que.top().second;
        que.pop();

        if(vis[atual]) continue;
        vis[atual] = true;

        for(int i = 0; i < n; i++) {
            if(atual == i) continue;
            if(dist[i] > dist[atual] + graph[atual][i]) {
                dist[i] = dist[atual] + graph[atual][i];
                que.push({dist[i], i});
            }
        }
    }

    int maxtime = 0;
    for(int i = 0; i < n; i++) {
        if(dist[i] > maxtime) maxtime = dist[i];
    }

    cout << maxtime << endl;

    return 0;
}