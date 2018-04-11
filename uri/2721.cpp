#include <iostream>

using namespace std;

int main() {
	unsigned long long A, tmp;
	
	A = 0;
	for(int i = 0; i < 9; i++) {
		cin >> tmp;
		A+=tmp;
	}
	
	switch(A%9) {
		case 1: 
			cout << "Dasher\n";
			break;
		case 2:
			cout << "Dancer\n";
			break;
		case 3:
			cout << "Prancer\n";
			break;
		case 4:
			cout << "Vixen\n";
			break;
		case 5:
			cout << "Comet\n";
			break;
		case 6:
			cout << "Cupid\n";
			break;
		case 7:
			cout << "Donner\n";
			break;
		case 8:
			cout << "Blitzen\n";
			break;
		case 0:
			cout << "Rudolph\n";
			break;
	}
	
	return 0;
}
