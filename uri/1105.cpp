#include<bits/stdc++.h>

using namespace std;

int main() {
	int B, N, D, C;
	long R[21], V;

	ios::sync_with_stdio(0);
	
	cin >> B >> N;
	
	while(B != 0 || N != 0) {
		for(int i = 0; i < B; i++) {
			cin >> R[i];
		}
		for(int i = 0; i < N; i++) {
			cin >> D >> C >> V;
			R[D-1] -= V;
			R[C-1] += V;
		}
		for(int i = 0; i < B; i++) {
			if(R[i] < 0) {
				cout << "N\n";
				B = -1;
				break;
			}
		}
		if(B > -1) {
			cout << "S\n";
		}
		
		cin >> B >> N;
	}
	
	return 0;
}
