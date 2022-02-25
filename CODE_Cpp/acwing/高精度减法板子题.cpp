#include <bits/stdc++.h>

using namespace std;
//是否A >= B
bool cmp (vector<int>& A, vector<int>& B) {
    if (A.size() != B.size()) return A.size() >= B.size();
    for (int i = A.size(); i >=0; i--)
        if (A[i] != B[i])
           return A[i] > B[i];
    return true;
}

vector<int> sub (vector<int>& A, vector<int>& B) {
    vector<int> c;
    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        // 下面两句都可以用这个来替代 c.push_back((t + 10) % 10);
        if (t >= 0) c.push_back(t);
        else c.push_back(t + 10);
        //判断是否借位，好确定t的初始值
        if (t >= 0) t = 0;
        else t = 1;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main(void) {
    string a,b;
    cin >> a >> b;
    vector<int>A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');  //从各位开始储存，解决了借位问题
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    
    if(cmp(A, B)) {
        auto C = sub(A , B);
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    }else{
        auto C = sub(B , A);
        cout<<'-';
        for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    }
    return 0;
}