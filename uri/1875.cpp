#include<bits/stdc++.h>

using namespace std;

int main() {
	int C, P;
	char t1, t2;
	
	unsigned long R, G, B;
	
	ios::sync_with_stdio(0);
	
	cin >> C;
	
	while(C--) {
		cin >> P;
		R = G = B = 0;
		for(int i = 0; i < P; i++) {
			cin >> t1 >> t2;
			if(t1 == 'R') {
				if(t2 == 'G') { // R marcou em G
					R+=2;
				} else { // R marcou em B
					R++;
				}
			} else if(t1 == 'G') { 
				if(t2 == 'R') { // G marcou em R
					G++;
				} else { // G marcou em B
					G+=2;
				}
			} else if(t1 == 'B') {
				if(t2 == 'R') { // B marcou em R
					B+=2;
				} else { // B marcou em G
					B++;
				}
			}
		}
		
		if(R == B && B == G) {
			cout << "trempate" << endl;
		} else if((R == B && B > G)|| (B == G && G > R) || (R == G && G > B)) {
			cout << "empate" << endl;
		} else {
			if(R > B) {
				if(R > G) {
					cout << "red" << endl;
				} else {
					cout << "green" << endl;
				}
			} else if(B > G) {
				cout << "blue" << endl;
			} else {
				cout << "green" << endl;
			}
		}
	}
	
	return 0;
}
