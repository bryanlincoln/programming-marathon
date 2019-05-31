#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    map< pair<int, int>, string> codes;

    cin >> n;

    while(n--) {
        int c1, c2;
        string name;

        cin >> c1 >> c2 >> name;

        codes[{c1, c2}] = name;
    }

    cin >> n;

    while(n--) {
        int c1, c2;
        cin >> c1 >> c2;
        cout << codes[{c1, c2}] << endl;
    }

    return 0;
}