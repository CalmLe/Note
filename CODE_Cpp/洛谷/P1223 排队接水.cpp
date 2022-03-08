#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector<PII> T;
double res;
bool cmp(PII a, PII b) {
    return a.first < b.first ? true : false;
}
inline int read() {
    char c = getchar();
    int s =0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = - 1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
int main(void) {
    int n = read();
    for (int i = 0; i < n; i++) T.push_back({read(), i + 1});
    sort(T.begin(), T.end(), cmp);
    for (int i = 0; i < n; i++) printf("%d ", T[i].second);
    printf("\n");
    for (int i = n; i >= 1; i--) {
        res += (i - 1) * T[n - i].first;
    }
    res /= n;
    printf("%.2lf\n",res); 
}