#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long int a, b, g;
        cin >> a >> b;
        g = __gcd(a, b);
        cout << b / g << " " << a / g << endl;
    }
    return 0;
}