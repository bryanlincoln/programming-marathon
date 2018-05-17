#include <bits/stdc++.h>
#define N 510

using namespace std;

bool vis[N];
bool adj[N][N];
long dist[N];

long min(map<long, vector<pair<long, long> > > graph, long n, long o, long d) {
    priority_queue<pair<long, long>, vector<pair<long, long> >, greater<pair<long, long> > > que;

    for(long i = 1; i <= n; i++) {
        vis[i] = false;
        dist[i] = 1e9;
    }

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
                que.push({-dist[vizinho], vizinho});
            }
        }

        vis[atual] = true;
    }

    return dist[d];
}

int main() {
    long n, e;

    cin >> n >> e;
    
    while(n != 0 || e != 0) {
        map<long, vector<pair<long, long> > > graph; // i -> adjascentes (no, hora)

        for(long i = 0; i < n; i++) {
            for(long j = 0; j < n; j++) {
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
            long res = min(graph, n, o, d);
            
            if(res == 1e9) {
                cout << "Nao e possivel entregar a carta" << endl;
            } else {
                cout << res << endl;
            }
        }
        cout << endl;
        cin >> n >> e;
    }
    
    return 0;
}
