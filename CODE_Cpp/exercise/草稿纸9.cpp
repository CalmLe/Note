#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 20;
typedef long long LL;
LL amt, temp;
int arr[maxn], n, x;
inline int read() {
    char c = getchar();
    int s = 0 , w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s  * w;
}
int main(void) {
    n = read(), x = read();
    for(int i = 0; i < n; i++) arr[i] = read();
    for(int i = 1; i < n; i++) { 
    //
        if(arr[i] + arr[i - 1] > x) {
            temp = arr[i] + arr[i - 1] - x;
            amt += temp;
            //其实这里的根本不可能出现arr[i] >= temp,若出现了则arr[i - 1] >= x了就不会进入这个条件里面
            if(arr[i] >= temp) arr[i] -= temp;
            else arr[i] = 0;
        } 
    }
    printf("%lld\n", amt);
    return 0;
}
