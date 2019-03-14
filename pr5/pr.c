#include <stdio.h>
#include <inttypes.h>

int64_t testf(int, int, int);

int main(void) {
    int x,y,z; 
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    printf("%ld\n", testf(x, y, z));
}
