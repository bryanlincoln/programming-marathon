#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, n, c;
    
    while(scanf("%d", &t) != EOF) {            
        for(n = 1; n <= t; n+=2) {
            for(c = 0; c < t/2 - n/2; c++) {
                printf(" ");
            }
            for(c = 0; c < n; c++) {
                printf("*");
            }
            printf("\n");
        }
        
        for(c = 0; c < t/2; c++) {
            printf(" ");
        }
        printf("*\n");
        for(c = 0; c < t/2 - 1; c++) {
            printf(" ");
        }
        printf("***");
        printf("\n\n");
    }
    return 0;
}
