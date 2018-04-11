#include <iostream>

using namespace std;

int main() {
	unsigned long long x, m;
	
	cin >> x;
	cin >> m;
	
	while (x != 0 || m != 0) {
		cout << m * x << endl;
	
		cin >> x;
		cin >> m;
	}
	
	return 0;
}
