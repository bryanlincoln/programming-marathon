#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        map<int, pair<int, int> > vertices;
        map<int, vector<int> > edges;
        vector<int> notInMST(n+1);

        for(int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            graph[i] = {x, y};
        }
        int m, a; // declara a aqui fora pra ser a origem do prim
        cin >> m;
        for(int i = 0; i < m; i++) {
            int b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > que;
        map<int, bool> inMST;
        que.push({0, a});

        while(!que.empty()) {
            int u = que.top().second;
            que.pop();

            inMST[u] = true;
            for()
        }
    }
    return 0;
}