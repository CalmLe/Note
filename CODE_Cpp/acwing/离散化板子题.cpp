#include <bits/stdc++.h>
using namespace std;
// 数组的大小n + 2 * m;
const int maxn = 3e5 + 20;
typedef pair<int,int> PII;
//前缀和数组
int arr[maxn];
//储存离散化后的值
vector<int> alls;
//add用来在x处插入c,所以也要用类似于结构体的东西比如pair
//query用来存储询问的左端点跟右端点
//这里必须得用类型于结构体的东西比如pair();
vector<PII> add, query;
//快读模板
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for (;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for (;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
//二分查找这里返回值要特别注意一下，因为前缀和数组是从1开始的所以返回值要加1
int find(int x) {
    int l = - 1, r = alls.size();
    //int mid = r + l >> 1;
    while(l + 1 < r) {
        int mid = (r - l >> 1) + l;
        if(alls[mid] < x) l = mid;
        else r = mid;  
    }
    //因为前缀和数组是从1开始的而这个alls是从0开始的所以得+1
    if(r < alls.size() && alls[r] == x) return r + 1;
//unique函数的实现思路是双指针算法
}
vector<int>::iterator unique(vector<int>&a) {
    //i用来遍历所有数, j用来指示存到了第几个元素了
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        if(!i || a[i - 1] != a[i]) a[j++] = a[i];
    }
    //a.begin()是迭代器(iterator)类型不能单独返回j否则是error
    return a.begin() + j;
}
int main(void) {
    int n, m, l, r, x, c;
    n = read();
    m = read();
    for (int i = 0; i < n; i++) {
        x= read(), c = read();
        add.push_back({x, c});
        alls.push_back(x);
    }
    //这里为什么要把l，r放入alls里呢？因为如果没有加入l，r最好可能查找不出来
    //加入l跟r了，不改变前缀和
    for (int i = 0; i < m; i++) {
        l = read(), r = read();
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    //去重操作,然后再删除重复的元素
    alls.erase(unique(alls), alls.end()); //手写unique()
    //alls.erase(unique(alls.begin(),alls.end()), alls.end());
    for (auto item : add){
        int x = find(item.first);
        arr[x] += item.second;
    }
    for (int i = 1; i <= alls.size(); i++) arr[i] += arr[i - 1];
    for (auto item : query){
        l = find(item.first), r = find(item.second);
        printf("%d\n",arr[r] - arr[l - 1]);
    }
    return 0;
}