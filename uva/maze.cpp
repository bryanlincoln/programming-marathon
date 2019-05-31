#include <bits/stdc++.h>
using namespace std;

int d[] = {-1, 1};
int main() {
    int l, r, c;
    while(cin >> l >> r >> c && (l || r || c)) {
        vector< vector< vector<char> > > graph(l);
        vector< vector< vector<bool> > > vis(l);
        vector< vector< vector<int> > > dist(l);
        int si = -1, sj = -1, sk = -1;
        for(int i = 0; i < l; i++) {
            graph[i].resize(r);
            vis[i].resize(r);
            dist[i].resize(r);
            for(int j = 0; j < r; j++) {
                graph[i][j].resize(c);
                vis[i][j].resize(c, false);
                dist[i][j].resize(c, 1e9);
                for(int k = 0; k < c; k++) {
                    cin >> graph[i][j][k];
                    if(graph[i][j][k] == 'S')
                        si = i, sj = j, sk = k;
                }
            }
        }
        int res = -1;
        queue< pair<int, pair<int, int> > > que;
        que.push({si, {sj, sk}});
        dist[si][sj][sk] = 0;
        while(!que.empty()) {
            if(res >= 0) break;
            pair<int, pair<int, int> > atual = que.front();
            que.pop();
            int i = atual.first, j = atual.second.first, k = atual.second.second;
            if(vis[i][j][k]) continue;
            vis[i][j][k] = true;
            int ai, aj = 0, ak = 0;
            for(ai = 0; ai < 2; ai++) {
                if(i + d[ai] >= 0 && i + d[ai] < l && !vis[i + d[ai]][j][k] && dist[i + d[ai]][j][k] > dist[i][j][k] + 1 && graph[i + d[ai]][j][k] != '#') {
                    dist[i + d[ai]][j][k] = dist[i][j][k] + 1;
                    if(graph[i + d[ai]][j][k] == 'E')
                        res = dist[i + d[ai]][j][k];
                    que.push({i + d[ai], {j, k}});
                }
            }
            for(aj = 0; aj < 2; aj++) {
                if(j + d[aj] >= 0 && j + d[aj] < r && !vis[i][j + d[aj]][k] && dist[i][j + d[aj]][k] > dist[i][j][k] + 1 && graph[i][j + d[aj]][k] != '#') {
                    dist[i][j + d[aj]][k] = dist[i][j][k] + 1;
                    if(graph[i][j + d[aj]][k] == 'E')
                        res = dist[i][j + d[aj]][k];
                    que.push({i, {j + d[aj], k}});
                }
            }
            for(ak = 0; ak < 2; ak++) {
                if(k + d[ak] >= 0 && k + d[ak] < c && !vis[i][j][k + d[ak]] && dist[i][j][k + d[ak]] > dist[i][j][k] + 1 && graph[i][j][k + d[ak]] != '#') {
                    dist[i][j][k + d[ak]] = dist[i][j][k] + 1;
                    if(graph[i][j][k + d[ak]] == 'E')
                        res = dist[i][j][k + d[ak]];
                    que.push({i, {j, k + d[ak]}});
                }
            }
        }
        if(res == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << res << " minute(s)." << endl;
    }
    return 0;
}