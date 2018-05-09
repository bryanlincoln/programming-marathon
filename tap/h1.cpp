#include <bits/stdc++.h>
#define N 102
#define DIRS 4
#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3
using namespace std;

int mapa[N][N];
int esq[N][N];
int x[DIRS] = {0,0,1,-1};
int y[DIRS] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(false);
    queue<pair<int, int> > bfs;
    int l, c;
    cin >> l >> c;

    for(int i = 1; i <= l; i++) {
        string linha;
        cin >> linha;
        linha = "0" + linha + "0";
        
        for(int j = 1; j <= c; j++) {
            mapa[i][j] = linha[j] - '0' + 2;
        }
    }

    bfs.push({1, 1});
    int i, j;
    while(!bfs.empty()) {
        i = bfs.front().first;
        j = bfs.front().second;
        bfs.pop();

        for(int dir = 0; dir < DIRS; dir++) {
            if(abs(mapa[i + y[dir]][j + x[dir]] - mapa[i][j]) > 1) continue;
            
            bfs.push({i + y[dir], j + x[dir]});
            if(j > 2 || dir != DOWN)
                esq[i + y[dir]][j + x[dir]] = esq[i][j] + 1;
        }

        mapa[i][j] = 0;
    }

    if(j == c) {
        cout << (esq[i][j] == 0 ? -1 : esq[i][j]) << endl;
    } else {
        cout << "IMPOSSIVEL" << endl;
    }


    return 0;
}