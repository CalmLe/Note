#include <bits/stdc++.h>
using namespace std;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for (;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for (;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
bool is_prime(int n) {
    if(n <= 1) return false;
//要么成对出现，要么没有，约数是成对出现的，因此只需要遍历到sqrt（n）即可
    for (int i = 2; i <= n / i; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int main(void) {
    int n, x;
    n = read();
    for (int i = 0; i < n; i++) {
        x = read();
        if(is_prime(x)) printf("%d ", x);
    }
    return 0;
} 
