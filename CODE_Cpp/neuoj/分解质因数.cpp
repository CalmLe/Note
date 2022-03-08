#include <bits/stdc++.h>
using namespace std;
vector<int> divide(int x) {
    vector<int> c;
    for (int i = 2; i <= x / i; i++) {
        if(x % i == 0) {
            while(x % i == 0) {
                x /= i;
                c.push_back(i);
            }
        }
    }
    if(x > 1) c.push_back(x);
    return c;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n) {
        auto res = divide(n);
        cout << n << ":" ;
        for (int i = 0; i < res.size(); i ++) cout << " " << res[i] ;
    }
    return 0;
}