#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef unsigned long long llu;

llu fibo (llu num) {
    if (num == 0 || num == 1)
        return num;
    return fibo(num - 1) + fibo(num - 2);
}

llu fact(llu num){
    if (num == 1)
        return 1;
    else
        return num * fact(num - 1);
}

llu div(llu fiboNum) {
    return (fibo(fiboNum) * pow(6, fiboNum) * pow(fiboNum - 1, 4)) / fact(fiboNum - 1);
}

int main(int argc, char * argv[]) {
    llu E;
    printf("Enter your e number:\n");
    scanf(E);
    clock_t time;
    time = clock();
    llu pr_res, curFibo = 3;
    for (int i = 0; i < 1000000; i++) {
        pr_res = div(curFibo);
        printf("%llu  %llu\n", curFibo, pr_res);
        curFibo++;
    }
    time = clock() - time;
    float est = (float)time / CLOCKS_PER_SEC;
    printf("Done in %f secs\n", est);
    return 0;
}