#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int n;
	char testes[100][50];
	
	cin >> n;
	
	// pra cada caso de teste
	while(n--) {
		int l, ac = 0;
		cin >> l;
		// pra cada linha seguinte
		for(int i = 0; i < l; i++) {
			cin >> testes[i];
			// pra cada palavra
			for(int j = 0; j < strlen(testes[i]); j++) {
				ac += testes[i][j] - 'A'; // posição no alfabeto
				ac += i; // posição do elemento
				ac += j; // posição na string
			}
		}
		cout << ac << endl;
	}
	
	return 0;
}
