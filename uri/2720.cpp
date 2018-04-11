#include<bits/stdc++.h>

#define T 100000

using namespace std;

typedef struct Present {
    unsigned long id;
    long vol;
} present;

bool sortId (const present p1, const present p2) {
    return p1.id < p2.id;
}
bool sortVol(const present p1, const present p2) {
    if(p1.vol == p2.vol) {
        if(p1.id < p2.id) {
            return true;
        }
    } else if(p1.vol > p2.vol)
        return true;

    return false;
}

int main() {
    int t, n, k, a, l, c;
    present p[T], m[T];
	
  	ios::sync_with_stdio(0);
  
    cin >> t;

    while(t--) {
        cin >> n;
        cin >> k;

        int a, l, c;
        for(int i = 0; i < n; i++) {
            cin >> p[i].id;
            cin >> a;
            cin >> l;
            cin >> c;
            p[i].vol = (long)a * l * c;
        }
    
        sort(p, p + n, sortVol);

        for(int i = 0; i < k; i++) {
            m[i] = p[i];
        }

        sort(m, m+k, sortId);

        for(int i = 0; i < k; i++) {
            cout << m[i].id;
            if(i < k - 1)
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}
