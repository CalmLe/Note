#include <bits/stdc++.h>
using namespace std;
const int maxn = 32;
int arr[maxn], k = 0, comba[maxn][maxn];
int main(void) {
    int sum = 0;
    while(scanf("%d",&arr[++k]) != EOF) sum += arr[k];
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j <= i; j++) {
            if(!j) comba[i][j] = 1;
            else   comba[i][j] = comba[i - 1][j] + comba[i - 1][j - 1];
        }
    }
    k = k - 1;
    long long int cnt = 0;
    for (int i = 0; i <= k - 1; i++) cnt += comba[k - 1][i];
    printf("%lld\n", cnt * sum);
    return 0;
}