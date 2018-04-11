#include <stdio.h>
#include <stdlib.h>

int map(char c) {
    switch(c) {
        case '1':
            return 2;
        case '2':
        case '3':
        case '5':
            return 5;
        case '4':
            return 4;
        case '6':
        case '9':
        case '0':
            return 6;
        case '7':
            return 3;
        case '8':
            return 7;
        default:
            return 0;
    }
}

int main() {
    char N[101];
    int t;
    int leds;
    int i;
    
    scanf("%d", &t);
    for(;t;t--) {
        scanf(" %s", N);
        
        for(i = leds = 0; N[i] != '\0'; i++) {
            leds += map(N[i]);
        }
        
        printf("%d leds\n", leds);
    }
    
    return 0;
}
