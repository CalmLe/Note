#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int maxx = -0x7fffffff;
int arr[maxn][maxn];

int main(void){
    ios::sync_with_stdio(false);            
    int n, m, c;   
    while (cin >> n >> m >> c) {
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> arr[i][j];
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
        int xx, yy;
        /* 
        错误代码xx = i跟yy = j 不在if的条件里面！！！！！！，其实从i = c， j = c开始循环还好很多
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i + c - 1 <= n && j + c - 1 <= m) {
                    result = max(result, arr[i + c - 1][j + c - 1] - arr[i - 1][j + c - 1] - arr[i + c - 1][j - 1] + arr[i - 1][j - 1]);
                    xx = i;
                    yy = j;
                }
            }
        } 
        */
        for (int i = c; i <= n; i++) {
            for (int j = c; j <= m; j++) {
                if (arr[i][j] - arr[i][j - c] - arr[i - c][j] + arr[i - c][j - c] > maxx) {
                    maxx = arr[i][j] - arr[i][j - c] - arr[i - c][j] + arr[i - c][j - c];
                    xx = i - c + 1;
                    yy = j - c + 1;
                }
            }
        }
        cout << xx << " " << yy << endl;
    }
    return 0;
}