#include <stdio.h>
#include <stdlib.h>

int abs(int n) {
    return n >= 0 ? n : -n; 
}

int main() {
    int N, B, *balls, i, j, flag;
    
    while(1) {
        scanf("%d %d", &N, &B);
        
        if(N + B == 0) 
            break; 
            
        balls = (int *) malloc(B * sizeof(int));
        
        for(i = 0; i < B; i++) {
            scanf("%d", &balls[i]);
        }
        
        for(; N + 1; N--) {
            flag = 0;
            for(i = B - 1; i + 1; i--) {
                for(j = i; j + 1; j--) {
                    if(abs(balls[i] - balls[j]) == N) {
                        flag = 1;
                        break;
                    }
                }
                if(flag) {
                    break;
                }
            }
            if(!flag) {
                printf("N\n");
                break;
            }
        }
        if(flag)
            printf("Y\n");
            
        free(balls);        
    }
    
    return 0;
}
