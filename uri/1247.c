#include<stdio.h>
#include<math.h>

int main() {
    int vf, vg, d;
    float hip;

    while(scanf("%d %d %d", &d, &vf, &vg) != EOF) {
        hip = sqrt(144 + pow(d, 2));
        
        if(12.0/vf >= hip/(vg)) {
            printf("S\n");
        }
        else {
            printf("N\n");
        }
    }

    return 0;
}
