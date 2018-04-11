#include <stdio.h>
#define T 1000

int main() {
	int n, i_pilha = 0, diamantes;
	char temp, pilha[T+1];
	
	scanf("%d", &n);
	
	while(n--) {
		diamantes = 0;
		i_pilha = -1;
		
		scanf(" %c", &temp);
		while(temp != '\0' && temp != '\n') {
			if(temp == '<') {
				i_pilha++;
				pilha[i_pilha] = '<';
			}
			else if(temp == '>') {
				if(i_pilha >= 0 && pilha[i_pilha] == '<') {
					i_pilha--;
					diamantes++;
				} else {
					i_pilha++;
					pilha[i_pilha] = '>';
				}
			}
			scanf("%c", &temp);
		}
		printf("%d\n", diamantes);
	}
	
	return 0;
}
