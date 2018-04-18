#include <bits/stdc++.h>

using namespace std;

int main() {
    char tecla;
    int cursor;
    string linha;
    
    while(scanf("%c", &tecla) != EOF) {
        if(tecla == '\n') {
            cout << linha << endl;
            cursor = 0;
            linha = "";
        }
        else if(tecla == '[') {
            cursor = 0;
        }
        else if(tecla == ']') {
            cursor = linha.size();
        }
        else {
            linha.insert (cursor, 1, tecla);
            cursor++;
        }
    }
    
    return 0;
}