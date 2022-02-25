#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int maxx = -0x7fffffff;
int arr[N][N];
int max (int a, int b) {
    return (a >= b) ? a : b;
}
int main(void){
    ios::sync_with_stdio(false);
    int n, m, c;
    int maxx = -0x7fffffff;
    while (cin >> n >> m >> c) {
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> arr[i][j];
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
        int xx, yy;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i + c - 1 <= n && j + c - 1 <= m) {
                    if (arr[i + c - 1][j + c - 1] - arr[i - 1][j + c - 1] - arr[i + c - 1][j - 1] + arr[i - 1][j - 1] > maxx) {
                        maxx = arr[i + c - 1][j + c - 1] - arr[i - 1][j + c - 1] - arr[i + c - 1][j - 1] + arr[i - 1][j - 1];
                        xx = i;
                        yy = j;
                    }
                }
            }
        } 
       

        cout << xx << " " << yy << endl;
    }
    return 0;
}