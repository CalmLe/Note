/*
vector<int> v;
v.max_size() = 4611686018427387903; 共19位数,

*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int>& A ,vector<int>&B) {         // 加& 直接修改，而不是copy一份
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
        
    }
    if(t)C.push_back(t);   
    return C;
}


int main(void) {
   string s1, s2;
   cin >> s1 >> s2;
   vector<int> A, B;
   for (int i = s1.size() - 1; i >= 0; i--) A.push_back(s1[i] - '0');   // 从个位开始存
   for (int i = s2.size() - 1; i >= 0; i--) B.push_back(s2[i] - '0');
    
    auto c =add(A, B);
    
    for (int i = c.size() - 1; i >= 0; i--) cout<< c[i]; 
    
    
    
    return 0; 
}
/*
#include <bits/stdc++.h>

using namespace std;

vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);                                 //不要忘记这个东西了！！！
    while (C.size() > 1 && C.back() == 0) C.pop_back();    //有了上面那句就不需要下面那句了
    return C;
}

int main(void) {
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    
    vector<int> C = add(A, B);
    
    for (int i= C.size() - 1; i >= 0; i--) cout << C[i];
    
    return 0;
 }

*/