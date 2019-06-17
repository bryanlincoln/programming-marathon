#include<bits/stdc++.h>
using namespace std;
int main() {
    long long int n, sqrtn;
    cin >> n;
    sqrtn = sqrt(n)+10;
    if(n % 2 == 0) cout << 2 << endl;
    while(n % 2 == 0) n /= 2;
    for(long long int i = 3; i <= sqrtn; i+=2) {
        if(n % i == 0) cout << i << endl;
        while(n % i == 0) n /= i;
    }
    if(n > 1) cout << n << endl;
    return 0;
}