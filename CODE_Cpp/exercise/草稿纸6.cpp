#include <bits/stdc++.h>
using namespace std;

inline double my_ceil(double x) {
    if(x >= 0) return x == (long long) x ? x : (long long) x + 1;
    else return  x == (long long) x ? x : (long long) x;
}

int main(void) {
    for(double i = -1; i <= 1; i += 0.000001) {
        if(my_ceil(i) != ceil(i)) printf("NO");
        //else printf("0k");
    }
    printf("end");
}