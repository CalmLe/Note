/*
1.分析若是用朴素算法做的话时间复杂度是o(n2)
2.画一个平面直角坐标系，横坐标对应下标，然后纵坐标对应的是值，若是下降趋势（或者平缓），那么下标小的点就没有用，最后发现会变成严格的递增的曲线
3.这样的话可以去掉很多没有实际意义的元素，大大降低时间复杂度，这就是单调栈的思想；

>>>  单调栈的时间复杂度是o(n)；

常见模型：找出每个数左边离它最近的比它大/小的数
int tt = 0;
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;
    stk[ ++ tt] = i;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int stk[maxn], arr[maxn], tt;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    while(!isdigit(c)) {
        if(c == '-') w = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    return s * w;
}
bool check(int a, int b) {
    return arr[a] >= arr[b];
}
int main(void) {
    int n, temp;
    n = read();
    for (int i = 0; i < n; i++) {
        arr[i] = read();
        while(tt && check(stk[tt], i)) tt--;
        if(tt) printf("%d ", arr[stk[tt]]);
        else printf("-1 ");
        stk[++tt] = i;
    }
    return 0;
}

