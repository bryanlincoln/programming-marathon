#include <bits/stdc++.h>
#define M 101
using namespace std;

int main() {
    int l, c, s, ri, rj, cards = 0;
    char mapa[M][M], dir;

    cin >> l >> c >> s;

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            char temp;
            cin >> temp;
            if(temp == '.' || temp == '*' || temp == '#')
                mapa[i][j] = temp;
            else {
                dir = temp;
                ri = i;
                rj = j;
                mapa[i][j] = '.';
            }
        }
    }

    while(s--) {
        char cmd;
        cin >> cmd;

        if(cmd == 'F') {
            switch(dir) {
                case 'N':
                    if(ri - 1 >= 0 && mapa[ri-1][rj] != '#') {
                        mapa[ri][rj] = '.';
                        ri--;
                        if(mapa[ri][rj] == '*')
                            cards++;
                    }
                break;
                case 'S':
                    if(ri + 1 < l && mapa[ri+1][rj] != '#') {
                        mapa[ri][rj] = '.';
                        ri++;
                        if(mapa[ri][rj] == '*')
                            cards++;
                    }
                break;
                case 'L':
                    if(rj + 1 < c && mapa[ri][rj+1] != '#') {
                        mapa[ri][rj] = '.';
                        rj++;
                        if(mapa[ri][rj] == '*')
                            cards++;
                    }
                break;
                default:
                    if(rj - 1 >= 0 && mapa[ri][rj-1] != '#') {
                        mapa[ri][rj] = '.';
                        rj--;
                        if(mapa[ri][rj] == '*')
                            cards++;
                    }
                break;
            }
        } else {
            if(dir == 'N') {
                switch(cmd) {
                    case 'D':
                        dir = 'L';
                    break;
                    default:
                        dir = 'O';
                    break;
                }
            } else if(dir == 'S') {
                switch(cmd) {
                    case 'D':
                        dir = 'O';
                    break;
                    default:
                        dir = 'L';
                    break;
                }                
            } else if(dir == 'L') {
                switch(cmd) {
                    case 'D':
                        dir = 'S';
                    break;
                    default:
                        dir = 'N';
                    break;
                }
            } else if(dir == 'O') {
                switch(cmd) {
                    case 'D':
                        dir = 'N';
                    break;
                    default:
                        dir = 'S';
                    break;
                }
            }
        }
    }

    cout << cards << endl;

    return 0;
}