#include <bits/stdc++.h>
using namespace std;
map<int,int> mymap;
int n, m;
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    for(;!isdigit(c); c = getchar()) if(c == -1) w = -1;
    for(;isdigit(c); c = getchar()) s = (s << 3) + (s << 1) + (c ^ 48);
    return s * w; 
}
int main(void) {
    n = read(), m = read();
    for (int i = 0; i < m; i++) {
        mymap[read()]++;
    }
    /* for(auto item : mymap) {
        for (int i = 0; i < item.second; i++) {
            printf("%d ", item.first);
        }
    } */
    /* for (auto item : mymap) {
        for (int i = 0; i < item->second; i++) {
            printf("%d ", item->first);
        }
    } */
    for (auto itor = mymap.begin(); itor != mymap.end(); itor++) {
        for (int i = 0; i < itor->second; i++) {
            printf("%d ",itor->first);
        }
    }
    return 0;
}