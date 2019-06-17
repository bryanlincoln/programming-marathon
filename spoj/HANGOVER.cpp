#include<bits/stdc++.h>
using namespace std;
int main() {
    float lim, len;
    while(cin >> lim && lim > 0) {
        long c;
        for(c = 1, len = 0; len < lim; c++) len += 1.0/(c + 1);
        cout << c - 1 << " card(s)" << endl;
    }
    return 0;
}