#include<bits/stdc++.h>
using namespace std;
int main() {
    long int n, d;
    while(cin >> n && cin >> d && n && d) {
        long long int sum = 0, i; 
        for (i = 2; i <= n; i++) sum = (sum + d) % i; 
        cout << n << " " << d << " " << sum + 1 << endl;
    }
    return 0;
}