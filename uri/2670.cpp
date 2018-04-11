#include <iostream>

using namespace std;

int main() {
	int a[3], A, B, C;
	
	for(int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	
	A = 2*a[1] + 4*a[2]; // se tiver no primeiro
	B = 2*a[0] + 2*a[2]; // no segundo
	C = 4*a[0] + 2*a[1]; // se tiver no terceiro
	
	// se tiver no primeiro andar
	if(A < B && A < C) {
		cout << A << endl;
	}
	else if(A < B) {
		cout << C << endl;
	} 
	else if(A < C) {
		cout << B << endl;
	} 
	else if(B < C) {
		cout << B << endl;
	}
	else {
		cout << C << endl;
	}

	return 0;
}
