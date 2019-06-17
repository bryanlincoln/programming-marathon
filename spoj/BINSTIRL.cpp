#include<bits/stdc++.h>
using namespace std;
int main() {
    int d;
    cin >> d;
    while(d--) {
        int n, k;
        cin >> n >> k;
        cout << ((n == 0 && k != 0 || n != 0 && k == 0) ? 0 : (((n-k) & ((k - 1) / 2)) == 0)) << endl;
    }
    return 0;
}