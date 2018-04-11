#include <bits/stdc++.h>

using namespace std;

int longest(map<int, vector<int> > graph, int r) {
    if(graph[r] == NULL || graph[r].size() == 0) {
        return 0;
    }
    
    int maior = longest(graph, graph[r].at(0));
    
    for(int i = 1; i < graph[r].size(); i++) {
        int temp;
        if(maior < (temp = longest(graph, graph[r].at(i))) {
            maior = temp;
        }
    }
    
    return maior + 1;
}

int main() {
    map<int, vector<int> > graph;
    int n;
    int u, v;
    int r = -1;
    
    cin >> n;
    
    while(n--) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    
    cout << longest(graph, 
    
    return 0;
}
