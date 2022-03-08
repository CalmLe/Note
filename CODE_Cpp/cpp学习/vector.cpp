#include <bits/stdc++.h>
using namespace std;
int main(void) {
    vector<int> my_vector;
    for (int i = 0; i < 5; i++) my_vector.push_back(i);
    for (iterator it = my_vector.begin(); it != my_vector.end(); it++) cout << *it << endl;
}