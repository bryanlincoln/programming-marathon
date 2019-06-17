#include<bits/stdc++.h>
using namespace std;
int main() {
    double w, h;
    while(cin >> w >> h && (w != 0 || h != 0)) {
        cout << (h - w) * M_PI * w * w << endl;
    }
    return 0;
}