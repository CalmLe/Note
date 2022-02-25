#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int n;
int arr[maxn], temp[maxn];
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    while (!isdigit(c)) {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    return s * w;
}
int main(void) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) arr[i] = read();
        for (int i = 1; i < n; i++) temp[i] = abs(arr[i] - arr[i - 1]);
        sort(temp  + 1, temp + n);
        int flag = 1;
        for (int i = 1; i < n; i++) {
            if (temp[i] != i) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) printf("Jolly\n");
        else printf("Not jolly\n"); 
        
    
}