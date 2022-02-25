#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10;
int arr[maxn];
int n, k;

inline int read()
{
    register int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') 
    {
        x=(x<<3)+(x<<1)+(c^48); //等价于x*10+c-48,使用位运算加速
        c=getchar();
    }
    return x*f;
}
int main(void) {
    while (cin >> n >> k) {
        for (int i = 0; i < n; i++) arr[i] = read();
        sort(arr, arr + n);
        printf("%d",arr[k]);
    }
    return 0;
}