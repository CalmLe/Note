#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int*dp;
    int n;
    while (scanf("%d",&n) != EOF) {
        dp = (int*)malloc((n+5)*sizeof(int));
        dp[1] = dp[2] = 1;
            for (int i = 3;n>2 && i <= n; i++) {
                dp[i] = dp[i-1] + dp[i-2];
            }
            printf("%d",dp[n]);
            
    }





    return 0;
}