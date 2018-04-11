#include <stdio.h>
#include <stdlib.h>

int main() {
    int A;
    
    while(scanf("%d", &A) != EOF) {
        printf("%c\n", (A%6==0 ? 'Y' : 'N'));
    }
    
    return 0;
}
