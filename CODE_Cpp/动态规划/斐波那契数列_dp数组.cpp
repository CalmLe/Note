//时间复杂度 n
//空间复杂度 n
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int N;
    while(scanf("%d",&N)!=EOF) {
        vector<int>dp(N+1);
        dp[0]=0;
        dp[1]=1;
        if(N<=1) {
            printf("%d\n",dp[N]);
        }else{
            for (int i=2;i<=N;i++) {
                dp[i] = dp[i-1] + dp[i-2];
            }
            printf("%d\n",dp[N]);
        }
        
    }
    
    


    return 0;
}

