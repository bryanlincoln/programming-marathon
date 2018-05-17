#include <bits/stdc++.h>
#define N 510

using namespace std;

bool adj[N][N];

int main() {
    long n, e;

    cin >> n >> e;
    
    while(n != 0 || e != 0) {
        map<long, vector<pair<long, long> > > graph; // i -> adjascentes (no, hora)

        for(long i = 0; i <= n; i++) {
            for(long j = 0; j <= n; j++) {
                adj[i][j] = false;
            }
        }

        while(e--) {
            long x, y, h;
            cin >> x >> y >> h;
            
            graph[x].push_back({y, h});
            adj[x][y] = true;
        }
        
        long k;
        cin >> k;
        while(k--) {
            long o, d;
            cin >> o >> d;

            vector<int> dist;
            vector<bool> vis;
            dist.resize(n+1, 1e9);
            vis.resize(n+1, false);

            priority_queue<pair<long, long>, vector<pair<long, long> >, greater<pair<long, long> > > que;
            dist[o] = 0;
            que.push({0, o});
            while(!que.empty()) {
                long atual = que.top().second;
                que.pop();

                if(vis[atual]) continue;

                for(long i = 0; i < graph[atual].size(); i++) {
                    long vizinho = graph[atual].at(i).first;
                    long custo = graph[atual].at(i).second;
                    if(adj[vizinho][atual]){
                        custo = 0;
                    }

                    if(!vis[vizinho] && dist[vizinho] > dist[atual] + custo) {
                        dist[vizinho] = dist[atual] + custo;
                        que.push({dist[vizinho], vizinho});
                    }
                }

                vis[atual] = true;
            }
            
            if(dist[d] < 1e9) {
                cout << dist[d] << endl;
            } else {
                cout << "Nao e possivel entregar a carta" << endl;
            }
        }
        cout << endl;
        cin >> n >> e;
    }
    
    return 0;
}
