#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    int N;
    while(scanf("%d",&N) != EOF) {
        vector<int>dp(N+1);        //定义一个dp数组，dp[i]表示到达i层的方法数
        //初始化
        dp[0]=1;
        dp[1]=1;
        if(N<=1){
            printf("%d\n",dp[N]);
        }else{
            for (int i=2;i<=N;i++) {
                dp[i] = dp[i-1] + dp[i-2];  //递推关系
            }
            printf("%d",dp[N]);
        }




    }
    return 0;
}