#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
//head 表示头节点的下标
//e[i] 表示节点i的值
//ne[i] 表示节点i的next指针是多少;
//idx  存储当前已经用到的那个点
int e[maxn], ne[maxn], idx, head;
void init() {
    head = -1;
    idx = 0;
}

// 在头节点后插入节点
void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

// 在下标是k后面增加节点
void insert(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// 将下标是k后面的点给删掉
void remove(int k) {
    ne[k] = ne[ne[k]];
}
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    while (!isdigit(c)) {
        if (c == '-') w = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    return s * w;
}
int main(void) {
    int n, x, k;
    n = read();
    char ch;
    init();
    while (n--) {
        cin >> ch;
        if (ch == 'H') {
            x = read();
            add_to_head(x);
        }
        else if(ch == 'I') {
             k = read();
             x = read();
             insert(k - 1, x);
        }
        else{
            k = read();
            remove(k - 1);
            //删除头节点的特判
            if(!k) head = ne[head];
        }
    }
    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    return 0;
}













