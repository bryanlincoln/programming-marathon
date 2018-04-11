#include<stdio.h>
#include<math.h>

int prime(unsigned long n) {
    unsigned long i;
    for(i = sqrt(n); i > 1; i--) {
        if(n%i==0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N;
    unsigned long temp;
    
    scanf("%d", &N);
    
    while(N--) {
        scanf("%ld", &temp);
        if(prime(temp)) {
            printf("Prime\n");
        } 
        else {
            printf("Not Prime\n");
        }
    }
    return 0;
}
