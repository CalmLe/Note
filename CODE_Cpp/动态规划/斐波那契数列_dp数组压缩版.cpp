//时间复杂度 n
//空间复杂度 1
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N;
    while(scanf("%d",&N) != EOF) {
        int temp=0;
        vector<int>dp(2);
        dp[0]=0;
        dp[1]=1;
        if(N <= 1) printf("%d",dp[N]);
        else{
            for (int i=2;i<=N;i++) {
                temp = dp[0] + dp[1];
                dp[0] = dp[1];
                dp[1] = temp;
            }
            printf("%d",dp[1]);
        }
    }
    return 0;
}