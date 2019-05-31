#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        map< int, vector<int> > graph;
        int l, a, b;
        bool can = true;
        cin >> l;
        while(l--) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        queue<int> que;
        vector<bool> vis(n, false);
        vector<int> color(n, 0);
        que.push(b);
        color[b] = 1;
        while(!que.empty()) {
            int atual = que.front();
            que.pop();

            if(vis[atual]) continue;
            vis[atual] = true;

            for(int i = 0; i < graph[atual].size(); i++) {
                int viz = graph[atual][i];
                if(color[viz] > 0 && color[viz] == color[atual]) {
                    can = false;
                    break;
                }
                color[viz] = (color[atual] % 2) + 1;
                que.push(viz);
            }

            if(!can) break;
        }

        if(can) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}