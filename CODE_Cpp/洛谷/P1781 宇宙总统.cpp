#include <bits/stdc++.h>
using namespace std;
typedef struct person {
    int id;
    vector<int> arr;
};
person p[25];
int n;
char temp;
bool cmp (person p1, person p2) {
    if(p1.arr.size() != p2.arr.size()) return p1.arr.size() > p2.arr.size();
    else {
        for (register int i = 0; i < p1.arr.size(); i++) {
            if (p1.arr[i] != p2.arr[i]) return p1.arr[i] > p2.arr[i];
        }
    }
    return true;
}
int main(void) {
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) { 
        cin >> s;
        p[i].id = i + 1;
        for (int j = 0; j < s.size(); j++) p[i].arr.push_back(s[j] - '0');
    }
    sort(p, p + n, cmp);
    cout << p[0].id << endl;
    for (register int i = 0; i < p[0].arr.size(); i++) cout << p[0].arr[i];
    return 0;
}