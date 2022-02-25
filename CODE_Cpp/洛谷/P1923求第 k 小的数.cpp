#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10;
int arr[maxn];
int n, k;
int quick_sort(int arr[], int l, int r) {
    if (l >= r) return arr[l];
    int i = l - 1, j = r + 1, x = arr[(r - l >> 1) + l];
    while (i < j) {
        while (arr[++i] < x);
        while (arr[--j] > x);
        if (i < j) swap(arr[i], arr[j]);
    }
    if (j >= k)  quick_sort(arr, l, j);
    else   quick_sort(arr, j + 1, r);
    
    
}
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
inline void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9) write(x/10);
	putchar(x%10 + '0');
}
int main(void) {
    ios::sync_with_stdio(false);
    while (cin >> n >> k) {
        /* for (int i = 0; i < n; i++) cin >> arr[i]; */
        for (int i = 0; i < n; i++) arr[i] = read();
        int res = quick_sort(arr, 0 , n - 1);
        /* cout << res; */
        write(res);
    }
    return 0;
}