#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, u, v;
    map<int, vector<int> > graph;
    map<int, bool> painted;

    cin >> n >> m;
     
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        
        painted[u] = painted[v] = false;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    if(graph.size() == 0) {
        cout << "YES" << endl;
        return 0;
    }

    queue<int> q;
    int visited = 0;

    q.push(u);
    while(!q.empty()) {
        int atual = q.front();
        q.pop();

        painted[atual] = true;
        visited++;
        
        for(int i = 0; i < graph[atual].size(); i++) {
            if(!painted[graph[atual].at(i)]) {
                q.push(graph[atual].at(i));
            }
        }
    }

    if(visited == n && m == n-1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
