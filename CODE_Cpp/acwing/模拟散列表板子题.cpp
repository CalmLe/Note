//开放寻址法 模拟散列表
#include <bits/stdc++.h>
using namespace std;
int n, x;
//1.储存询问
string query;
//2.取模的时候要取质数，这样的话可以减少哈希冲突
const int N = 2e5 + 3;
//3.如果数组上的数是null的话，表示这个位置上是空(按照题目给的数据是不会取到这个值的)
int arr[N], null = 0x3f3f3f3f;
inline int find(int x) {
    int k =  (x % N + N) % N;
/*
    4.当arr[k] == null 时， 即里面没有这个数，返回应该插入位置的下标
    5.当arr[k] == x 时， 即能找到k这个数，并且返回这个数的下标
*/
    while(arr[k] != null && arr[k] != x) {
        k++;
    //6.一定要注意这个的这个特殊判断，很重要
        if(k == N) k = 0;
    }
    return k;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //7.一定要记得初始化，这里的memset函数值得学习一下
    memset(arr, 0x3f, sizeof(arr));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> query >> x;
        if(query == "I") {
            arr[find(x)] = x;
        }
        else {
            if(arr[find(x)] == 0x3f3f3f3f) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}
/*
方法二直接调用函数
#include <bits/stdc++.h>
using namespace std;
map<int,int>my_map;
int x, n;
string queryuery;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> queryuery >> x;
        if(queryuery == "I") {
            my_map[x]++;
        }
        else {
            if(my_map.find(x) != my_map.end()) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

*/