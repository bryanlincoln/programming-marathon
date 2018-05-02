#include <bits/stdc++.h>
#define N 21
using namespace std;

char mapa[N][N];
int caminhos[N][N] = {-1};
int l, c;

int main() {
    cin >> l >> c;

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            char temp;
            cin >> temp;
            mapa[i][j] = temp;
        }
    }

    caminhos[0][0] = 0;

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            if(mapa[i][j] == '+' || mapa[i][j] == '|') {
                if(i + 1 < l && (caminhos[i+1][j] > caminhos[i][j] + 1 || caminhos[i+1][j]) == -1)
                    caminhos[i+1][j] = caminhos[i][j] + 1;
                if(i - 1 >= 0 && (caminhos[i-1][j] > caminhos[i][j] + 1 || caminhos[i-1][j]) == -1)
                    caminhos[i-1][j] = caminhos[i][j] + 1;
            }
            if(mapa[i][j] == '+' || mapa[i][j] == '-') {
                if(j + 1 < c && (caminhos[i][j+1] > caminhos[i][j] + 1 || caminhos[i][j+1]) == -1)
                    caminhos[i][j+1] = caminhos[i][j] + 1;
                if(j - 1 >= 0 && (caminhos[i][j-1] > caminhos[i][j] + 1 || caminhos[i][j-1]) == -1)
                    caminhos[i][j-1] = caminhos[i][j] + 1;
            }
        }
    }



    return 0;
}