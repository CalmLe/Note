#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>a, b, temp;
vector<int> add (vector<int>&a, vector<int>&b) {
    vector<int>c;
    int t = 0;
    for (register int i = 0; i < a.size() || i < b.size(); i++) {
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if(t) c.push_back(t);
    return c;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin >> n;
    a.push_back(1);
    b.push_back(1);
    for (register int i = 2; i <= n; i++){
        temp = add(a, b);
        b = a;
        a = temp;
    } 
    for (register int i = a.size() - 1; i >= 0; i--) cout << a[i];
}