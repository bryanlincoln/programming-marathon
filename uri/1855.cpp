#include <bits/stdc++.h>
#define N 100

using namespace std;

int main() {
    int x, y, i, j;
    char map[N][N], dir;
    bool visitado[N][N];
    
    cin >> x >> y;
    
    for(i = 0; i < y; i++) {
        scanf("%s", map[i]);
        
        for(j = 0; j < x; j++) {
            visitado[i][j] = false;
        }
    }
    
    i = j = 0;
    for(;;) {
        if(visitado[i][j]) {
            cout << "!" << endl;
            break;
        }
        else if(map[i][j] == '<' || map[i][j] == '>' || map[i][j] == 'v' || map[i][j] == '^') {
            dir = map[i][j];
        }
        else if(map[i][j] == '*') {
            cout << "*" << endl;
            break;
        }
        
        visitado[i][j] = true;
        
        if(dir == '<' && j > 0) {
            j--;
        } else if(dir == '>' && j < x-1) {
            j++;
        } else if(dir == 'v' && i < y-1) {
            i++;
        } else if(dir == '^' && i > 0) {
            i--;
        } else {
            cout << "!" << endl;
            break;
        }
    }
    
    return 0;
}
