/*
1.这里is_prime的循环终止条件推荐用i <= x / i，不推荐用i <= sqrt(x) 的原因是速度太慢了，不推荐用i * i <= x 的
原因是防止当x接近于int的范围边界值时，会因为溢出而对结果的判断产生影响，i*i在int范围里，(i+1)*(i+1)就会溢出，然后循环还不会停止，会对结果产生影响
*/
#include <bits/stdc++.h>
using namespace std;
inline int read(){
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
bool is_prime(int x) {
    if (x <=1 ) return false;
    for (int i = 2; i <= x / i; i ++) {
        if(x % i == 0) return false;
    }
    return true;
}
int main(void) {
    int n, temp;
    n = read();
    while(n--) {
        temp = read();
        if(is_prime(temp)) printf("Yes\n");
        else printf("No\n"); 
    }
    return 0;
}
