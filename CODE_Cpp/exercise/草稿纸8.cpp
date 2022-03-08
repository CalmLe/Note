#include  <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
vector<PII> vec;
int n, r;
LL cnt = 1;
//自定义比较规则，first小的排前面，若是first相等则，second小的排前面
inline bool cmp(PII a, PII b) {
    if(a.first < b.first) return true;
    if(a.first > b.first) return false;
    if(b.second <= b.second) return true;
    return false;
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
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i].first >= r) 
        {
            cnt++;
            r = vec[i].second;
        }
    printf("%lld", cnt);
    return 0;
    }
}