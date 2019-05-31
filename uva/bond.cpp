#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q, i, j, k, a, b, cost;
    while(cin >> n >> m) {
        vector< vector< pair<int, int> > > graph(n + 1, vector<int>(n + 1, {1e9 + 1}));
        for(i = 0; i < m; i++) {
            cin >> a >> b >> cost;
            graph[a][b] = graph[b][a] = cost;
        }
        for(k = 1; k <= n; k++) {
            graph[k][k] = 0;
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= n; j++) {
                    if(i == j) continue;
                    if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
        cin >> q;
        while(q--) {
            cin >> i >> j;
            cout << graph[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}