#include <bits/stdc++.h>
#define N 21
#define DIRS 4
using namespace std;

string mapa[N+2];
int esq[N+2][N+2];
int l, c;
int x[DIRS] = {0,0,1,-1};
int y[DIRS] = {1,-1,0,0};
char ok[DIRS] = {'|', '|', '-', '-'};

int main() {
    ios::sync_with_stdio(false);

    cin >> l >> c;

    mapa[0].insert(mapa[0].begin(), c+2, '*');
    for(int i = 1; i <= l; i++) {
        cin >> mapa[i];
        mapa[i] = "*" + mapa[i] + "*";
    }
    mapa[l+1].insert(mapa[l+1].begin(), c+2, '*');

    queue<pair<int, int> > bfs;

    bfs.push({1, 1});
    esq[1][1] = 1;

    while(!bfs.empty()) {
        int i = bfs.front().first, j = bfs.front().second;
        bfs.pop();

        if(i == l && j == c) {
            break;
        }

        for(int dir = 0; dir < DIRS; dir++) {
            if(mapa[i + y[dir]][j + x[dir]] == '*') continue;
            
            if(mapa[i][j] == '+' || mapa[i][j] == ok[dir]) {
                bfs.push({i + y[dir], j + x[dir]});
                esq[i + y[dir]][j + x[dir]] = esq[i][j] + 1;
            }
        }

        mapa[i][j] = '*';
    }


    cout << (esq[l][c] == 0 ? -1 : esq[l][c]) << endl;


    return 0;
}