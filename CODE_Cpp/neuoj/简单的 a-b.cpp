#include <bits/stdc++.h>
using namespace std;
//判断a是否大于等于b
bool cmp(vector<int>&a, vector<int>&b) {
    if(a.size() != b.size()) return a.size() >= b.size();
    for (int i = a.size() - 1; i >= 0; i--) {
        if(a[i] != b[i]) return a[i] >= b[i];
    }
    return true;
}
vector<int> add(vector<int>&a, vector<int>&b) {
    vector<int>c;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++){
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if(t) c.push_back(t);
    return c;
}
//默认a >= b;
vector<int> sub(vector<int>&a, vector<int>&b) {
    vector<int>c;
    int t = 0;
    //if(!cmp(a,b)) return sub(b,a);
  //  else{
        for (int i = 0; i < a.size(); i++) {
            t = a[i] - t;
            if(i < b.size()) t -= b[i];
            c.push_back((t + 10) % 10);
            if(t >= 0) t = 0;
            else t = 1;
        }
        while(c.size() > 1 && c.back() == 0) c.pop_back();
        return c;
    //}
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    vector<int>A, B, C;
    while(cin >> a >> b) {
        bool flag1 = false, flag2 = false; 
        for(int i = a.size() - 1; i >= 0; i--) {
            if(a[i] == '-') {
                flag1 = true;
            }else{
                A.push_back(a[i] - '0');
            }
        }
        for (int i = b.size() - 1; i >= 0; i--) {
            if(b[i] == '-') {
                flag2 = true;
            }else{
                B.push_back(b[i] - '0');
            }
        }
        //A - B
        if((flag1 && !flag2) || (!flag1 && flag2)) {
            C = add(A,B);
            if(flag1) cout << '-';
        }else{
            C = sub(A,B);
            if(cmp(A,B)) C = sub(A,B);
            else C = sub(B,A);
            if((!cmp(A,B) && !flag1 && !flag2) || (cmp(A,B) && flag1 && flag2 && a != b)) cout << '-';
        }
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    }
    
    return 0;
}