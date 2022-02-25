#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;
int e[maxn], l[maxn], r[maxn];
int m, idx, x, k;
void init() {
    //头结点0, 末节点1
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}
//在k节点的左边插入一个数
void insert(int k ,int x) {
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}
//删除k结点
void remove(int k) {
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}
inline int read() {
    register char c = getchar();
    register int s = 0, w = 1;
    while (!isdigit(c)) {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    return s * w;
}
int main(void) {
    m = read();
    string s;
    init();
    while (m--) {
        cin >> s;
        if (s == "D") {
            k = read();
            remove(k + 1);
        }else if(s == "IR") {
            k = read();
            x = read();
            insert(k + 1, x);
        }else if(s == "IL") {
            k = read();
            x = read();
            insert(l[k + 1], x);
        }else if(s == "R") {
            x = read();
            insert(l[1], x);
        }else{
            x = read();
            //犯错误地方insert(r[0], x);
            insert(0, x);
        }
    }
    //犯错误的地方 int i = 0;
    for (register int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";  
    return 0;
}