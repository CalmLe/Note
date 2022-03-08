#include  <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
vector<PII> vec;
int r, n;
LL cnt = 1;
//自定义比较规则，second小的排前面，若是second相等则，first小的排前面
inline bool cmp(PII a, PII b) {
    return a.second < b.second;
}
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == '-') w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w;
}
int main(void) {
    n = read();
    for(int i = 0; i < n; i++) vec.push_back({read(), read()});
    sort(vec.begin(), vec.end(), cmp);
    r = vec[0].second;
    for (int i = 0; i < n; i++) {
        if(vec[i].first >= r) {
            cnt++;
            r = vec[i].second;
        }
    }
    printf("%lld", cnt);
    return 0;
}