#include <bits/stdc++.h>
#define N 26
using namespace std;

int gaiolas[N][N];

int main() {
    int l, c, k;

    cin >> l >> c >> k;

    gaiolas[1][1] = 1;
    for(int i = 0; i < k; i++) {
        int gl, gc;
        cin >> gl >> gc;
        gaiolas[gl][gc] = -1;
    }

    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= c; j++) {
            if(i == 1 && i == j) continue;
            if(gaiolas[i][j] == -1)
                gaiolas[i][j] = 0;
            else
                gaiolas[i][j] = gaiolas[i-1][j] + gaiolas[i][j-1];
        }
    }

    cout << gaiolas[l][c] << endl;

    return 0;
}