#include <bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int>& A, vector<int>& B) {
    vector<int> C(A.size() + B.size() + 10);         
    for (int i = 0; i < A.size(); i++) 
        for (int j = 0; j < B.size(); j++) 
            C[i + j] += A[i] * B[j];
    int t = 0;
    for (int i = 0; i < C.size() || t; i++) {     //这里可以不用 || t的，因为前面初始化C的大小已经大于结果的位数了
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0 ) C.pop_back();
    return C;
}

int main(void) { 
    string a, b;
    cin >> a >> b;
    vector<int>A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto c = mul(A, B);
    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
    cout << endl;
    return 0;
}