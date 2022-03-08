//降维压缩 + 前缀和 + dp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 120 + 10;
int arr[maxn][maxn], sum[maxn];
int res = -0x7fffffff, dp;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
int main(void) {
    int n;
    n = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = read();
			arr[i][j] += arr[i - 1][j];
        }
    }
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 1; k <= n; k++) {
				sum[k] = arr[i][k] - arr[j][k];
				if(k == 1) dp = sum[1];
				else dp = max(dp + sum[k], sum[k]);
				res = max(res, dp);
			}
		}
	}
    printf("%d\n", res);
    return 0;
}