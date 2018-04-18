#include <bits/stdc++.h>

using namespace std;

int main() {    
    int N, M, temp, k, v;
    
    while(scanf("%d %d", &N, &M) != EOF) {
        map<int, vector<int> > vetor;
        
        for(int i = 1; i <= N; i++) {
            cin >> temp;
            vetor[temp].push_back(i);
        }
        
        while(M--) {
            cin >> k >> v;
            cout << (k > vetor[v].size() ? 0 : vetor[v].at(k-1)) << endl;
        }
    } 

    return 0;
}