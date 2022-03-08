#include <bits/stdc++.h>
using namespace std;
int main(void) {
    vector<int> vec(5);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = i;
    }
    //迭代器不能输出
    cout << vec.begin();
}