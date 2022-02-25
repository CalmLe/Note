#include <bits/stdc++.h>
using namespace std;
typedef struct stu{
    int id;  //学号
    int a;   //语文
    int sum;  //总分
};
const int maxn = 300 + 10;
stu arr[maxn];
inline int read() {
    char c = getchar();
    int s = 0, w = 1;
    while (!isdigit(c)) {
        if (c == '-') w = -1;
        c =getchar();
    }
    while (isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    return s * w;
}
bool cmp (stu stu1, stu stu2) {
    if (stu1.sum != stu2.sum) return stu1.sum > stu2.sum;
    if (stu1.a != stu2.a) return stu1.a > stu2.a;
    return stu1.id < stu2.id;
}
int main(void) {
    int n; 
    cin >> n;
    //while (scanf("%d", &n) != EOF) {
        //freopen("in.txt","r",stdin);
        for (int i = 1; i <= n; i++) {
            arr[i].a = read();
            arr[i].id = i;
            arr[i].sum = arr[i].a + read() + read();
        }
        sort(arr + 1, arr + n + 1, cmp);
        for (int i = 1; i <= n && i <= 5; i++) {
            printf("%d %d\n", arr[i].id, arr[i].sum);
        }
   // }
    return 0;
}
