#include <bits/stdc++.h>
using namespace std;
typedef struct person{
    int id;
    string res;
};
const int maxn = 25;
person p[maxn];
bool cmp (person a, person b) {
    if (a.res.size() != b.res.size()) return a.res.size() > b.res.size();
    return a.res >= b.res;
}
int main(void) {
    int n;
    string temp;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cin >> p[i].res;
    }
    sort(p, p + n, cmp);
    cout << p[0].id << endl << p[0].res << endl;
    return 0;
}