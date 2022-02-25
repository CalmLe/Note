#include <bits/stdc++.h>
using namespace std;
typedef struct stu{
    string name;
    int y;
    int m;
    int d;
    int id;
};
bool cmp (stu stu1, stu stu2) {
    if (stu1.y != stu2.y) return stu1.y < stu2.y;
    if (stu1.m != stu2.m) return stu1.m < stu2.m;
    if (stu1.d != stu2.d) return stu1.d < stu2.d;
    return stu1.id > stu2.id;
}
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
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
const int maxn = 100 + 10;
stu p[maxn];
int main(void) {
    int n;
    n = read();
    for (int i = 0; i < n; i++) {
        cin >> p[i].name;
        p[i].y = read();
        p[i].m = read();
        p[i].d = read();
        p[i].id = i;
    }
    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << p[i].name << endl;
    }
    return 0;
    
}