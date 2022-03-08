#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
typedef pair<int,int> PII;
typedef long long LL;
LL w;
int values[maxn], weights[maxn], N, T;
double res;
vector<PII> vec;
bool cmp(PII a, PII b) {
    return (a.second * 1.0 / a.first) >= (b.second * 1.0 / b.first) ? true : false;
}
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for (;!isdigit(c); c = getchar())if(c == '-') w = -1;
    for (;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return w * s;
}
int main(void) {
    N = read(), T = read();
    for (int i = 0; i < N; i++) {
        vec.push_back({read(), read()});
    }
    sort(vec.begin(), vec.end(), cmp);
    /* for (int i = 0; i < vec.size(); i++) printf("%d %d\n",vec[i].first, vec[i].second); */
    for (int i = 0; i < N; i++) {
        if(w + vec[i].first <= T) res += vec[i].second, w += vec[i].first;
        else {
            res += 1.0 * vec[i].second / vec[i].first * (T - w);
            break;
        }
    }
    printf("%.2lf",res);
    return 0;
}