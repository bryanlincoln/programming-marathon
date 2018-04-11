#include <stdio.h>

int main() {
	unsigned long long n, a, l, m;
	
	scanf("%llu", &n);
	
	while(n--) {
		scanf("%llu", &a);
		
		for(l = 0, m = 0; a > 0; a /= 2) {
			if(a%2 == 1) {
				l++;
			} else {
				if(l > m)
					m = l;
				l = 0;
			}
		}
		
		if(l > m)
			m = l;
		
		printf("%llu\n", m);
	}
	
	return 0;
}
