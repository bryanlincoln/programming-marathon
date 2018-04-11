#include <stdio.h>
#define T 101

int main() {
	int n, i, j, t1p, t2p, empt;
	char str[T], t1str[T], t2str[T];
	
	scanf("%d", &n);
	getchar();
	
	for(j = 0; j < n; j++) {
		printf("Instancia %d\n", j+1);
		gets(str);
		gets(t1str);
		gets(t2str);
		
		for(i = t1p = t2p = 0, empt = 0; str[i] != '\0'; i++) {
			if(str[i] == t1str[i] && str[i] == t2str[i]) {
				t1p++;
				t2p++;
			}
			else if(str[i] == t1str[i]) {
				t1p++;
				
				if(empt == 0)
					empt = 1;
			}
			else if(str[i] == t2str[i]) {
				t2p++;
				
				if(empt == 0)
					empt = 2;
			}
		}
		
		if(t1p > t2p) {
			printf("time 1\n\n");
		} else if(t2p > t1p) {
			printf("time 2\n\n");
		} else if(empt == 1) {
			printf("time 1\n\n");
		} else if(empt == 2) {
			printf("time 2\n\n");
		} else {
			printf("empate\n\n");
		}
	}

	return 0;
}
