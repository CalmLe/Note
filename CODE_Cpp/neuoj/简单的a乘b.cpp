#include <bits/stdc++.h>
using namespace std;
vector<int>mul (vector<int>& a, vector<int>& b){
    //最大位数位a.size() + b.size()位， 这里若是不开出大小，就不能用C.size()了
    vector<int>c(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i++) 
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    //这里t的作用可以说是算个中间量
    int t = 0;
    for (int i = 0; i < c.size(); i++) {
        t += c[i];
        c[i] = t % 10;
        t /= 10;
    }
    //为什么不要加下面这句话的原因
    //比如你拿最大3位数和2位数相乘999*99得到98901，最高位是9小于10，那其他数相乘就更小于10了
    /*
    while(t) {
        c.push_back(t % 10);
        t /= 10;
    }
    */
    //必须要去掉前导0；
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
/*
vector<int>fun (vector<int>& a, int b){
    int t;
    vector<int>c;
    for (int i = 0; i < a.size(); i++) {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(t) {
        c.push_back(t % 10);
        t /= 10;
    }
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
*/
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    string a, b;
    vector<int>A, B, C;
    cin >> a >> b;
    //cnt记录负号出现的次数
    int cnt = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        if(a[i] == '-') cnt++;
        else A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        if(b[i] == '-') cnt++;
        else B.push_back(b[i] - '0');
    }
    if(cnt % 2 != 0 && a[0] != '0' && b[0] != '0') cout << '-';
    C = mul(A, B);
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl; 
    return 0;
}