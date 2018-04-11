#include <stdio.h>

int main() {
	long s;

	while(1) {
		scanf("%ld", &s);
		if(s != (long)2002) {
			printf("Senha Invalida\n");
		}
		else {
			printf("Acesso Permitido\n");
			break;
		}
	}
	
	return 0;
}
