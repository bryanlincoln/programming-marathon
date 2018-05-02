#include <bits/stdc++.h>
#define N 101
using namespace std;

int main() {
    int l, c, mapa[N][N];

    cin >> l >> c;

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            char temp;
            cin >> temp;
            mapa[i][j] = temp - '0';
        }
    }

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            cout << mapa[i][j];
        }
    }

    return 0;
}