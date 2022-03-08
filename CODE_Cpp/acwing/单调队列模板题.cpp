#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int arr[maxn], q[maxn], tt = -1, hh = 0;
void init() {
    tt = -1;
    hh = 0;
} 
inline int read(){
     char c = getchar();
     int s = 0, w = 1;
     while (!isdigit(c)) {
         if(c == '-') w = -1;
         c = getchar();
     }
     while(isdigit(c)) {
         s = (s << 3) + (s << 1) + (c ^ 48);
         c = getchar();
     }
     return s * w;
}
int main(void) {
    int n, k;
    cin.tie(0);
    ios::sync_with_stdio(false);
    n = read();
    k = read();
    for(register int i = 0; i < n; i++) arr[i] = read();
    for(register int i = 0; i < n; i++) {
        while(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && arr[q[tt]] >= arr[i]) tt--;
        q[++tt] = i; 
        if(i >= k - 1) cout << arr[q[hh]] << " ";
    }
    cout << endl;
    init();
    for(register int i = 0; i < n; i++) {
        while(hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && arr[q[tt]] <= arr[i]) tt--;
        q[++tt] = i;
        if(i >= k - 1) cout << arr[q[hh]] << " ";
    }
}