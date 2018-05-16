#include <bits/stdc++.h>
#define N 110
#define DIRS 4
using namespace std;

int x[DIRS] = {0,0,1,-1};
int y[DIRS] = {1,-1,0,0};

int bfs(int mapa[N][N], int s, int l, int c) {
    int i, j;
    int esq[N][N];
    queue<pair<int, int> > que;

    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= c; j++) {
            esq[i][j] = 0;
        }
    }
    que.push({s, 1});
    while(!que.empty()) {
        i = que.front().first, j = que.front().second;
        que.pop();

        if(j == c) {
            break;
        }
        
        if(mapa[i][j] == 0) continue;

        for(int dir = 0; dir < DIRS; dir++) {
            if(abs(mapa[i + y[dir]][j + x[dir]] - mapa[i][j]) > 1) continue;
            if(esq[i + y[dir]][j + x[dir]] == 0 || esq[i + y[dir]][j + x[dir]] > esq[i][j] + 1) {
                que.push({i + y[dir], j + x[dir]});
                esq[i + y[dir]][j + x[dir]] = esq[i][j] + 1;
            }
        }
        mapa[i][j] = 0;
    }

    return esq[i][c];
}

int main() {
    ios::sync_with_stdio(false);
    
    int mapa[N][N], l, c;
    cin >> l >> c;

    for(int i = 1; i <= l; i++) {
        string linha;
        cin >> linha;
        linha = "0" + linha + "0";

        for(int j = 1; j <= c; j++) {
            mapa[i][j] = linha[j] - '0' + 2;
        }
    }

    int min = bfs(mapa, 1, l, c);
    for(int i = 2; i <= l; i++) {
        int temp = bfs(mapa, i, l, c);
        if(min == 0 || (temp > 0 && min > temp)) min = temp;
    }

    if(min > 0) {
        cout << min << endl;
    } else {
        cout << "IMPOSSIVEL" << endl;
    }

    return 0;
}