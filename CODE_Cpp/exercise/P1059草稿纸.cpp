#include <bits/stdc++.h>
using namespace std;
int n;
set<int> a;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    while (!isdigit(c)) {
        if(c == '-') w = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        s = (s << 1) + (s << 3) + (c ^ 48);
        c = getchar();
    }
    return s * w;
}
int main(void) {
    while (cin >> n) {
        for (register int i = 0; i < n; i++) a.insert(read());
        cout << a.size() << endl;
        for (auto it = a.begin(); it != a.end(); it++) cout << *it <<" ";
    }
    return 0;
} 