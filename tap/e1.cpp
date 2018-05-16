#include <bits/stdc++.h>
#define N 1004
#define DIRS 4
using namespace std;

string mapa[N+2];
int esq[N+2][N+2];
int x[DIRS] = {0,0,1,-1};
int y[DIRS] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(false);
    int l, c, s;

    cin >> l >> c;

    mapa[0].insert(mapa[0].begin(), c, '*');
    for(int i = 1; i <= l; i++) {
        cin >> mapa[i];
        mapa[i] = mapa[i];
    }
    mapa[l+1].insert(mapa[l+1].begin(), c, '*');

    for(s = 0; s < c && mapa[1][s] == '*'; s++);

    queue<pair<int, int> > bfs;

    bfs.push({1, s});
    esq[1][s] = mapa[1][s] - '0';

    int i, j;
    while(!bfs.empty()) {
        i = bfs.front().first, j = bfs.front().second;
        bfs.pop();

        if(i == l) {
            break;
        }

        for(int dir = 0; dir < DIRS; dir++) {
            if(mapa[i + y[dir]][j + x[dir]] == '*') continue;
            
            bfs.push({i + y[dir], j + x[dir]});
            esq[i + y[dir]][j + x[dir]] = esq[i][j] + mapa[i + y[dir]][j + x[dir]] - '0';
        }

        mapa[i][j] = '*';
    }

    esq[l][j] == 0 ? cout << "impossivel" : cout << esq[l][j];

    cout << endl;

    return 0;
}