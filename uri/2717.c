#include <stdio.h>

int main() {
	int n, a, b;
	
	scanf("%d %d %d", &n, &a, &b);
	printf("%s\n", (n >= a + b) ? "Farei hoje!" : "Deixa para amanha!");
	
	return 0;
}
