#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, u, v, atual;
    map<int, vector<int> > graph;
    map<int, bool> visitado;
    bool flag = false;
    queue<int> q;
    
    cin >> n >> m;
     
    while(m--) {
        cin >> u >> v;
        
        graph[u].push_back(v);
    }
    
    if(graph.size() == 0) {
        cout << "YES" << endl;
        return 0;
    }
    
    q.push(graph.begin()->first);
    
    while(!q.empty()) {
        atual = q.front();
        q.pop();
        
        if(visitado[atual]) {
            flag = true;
            break;
        }
        
        visitado[atual] = true;
        
        for(int i = 0; i < graph[atual].size(); i++) {
            q.push(graph[atual].at(i));
        }
    }
    if(flag) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    
    return 0;
}
