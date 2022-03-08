#include <bits/stdc++.h>
using namespace std;
int main(void) {
    vector<int> vec(10, 0);
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = i;
    }
    auto it1 = vec.begin();
    cout << it1;
    return 0;
}