/*
证明
1.对数字u进行分解质因数，u = p1 ^ a1 * p2 ^ a2 * p3 ^ a3 * ..... * pk ^ ak
2.u的质因子有且仅有p1, p2, p3 ...... pk
3. x % i == 0说明x能被整除，i只有两种情况，i要么是质数，要么是质数组成的合数
4.若i是质数的话就会进出循环里面然后算出有多少个这样的质数
5.若i是质数组成的合数，那么必然存在比i小的质因子，p又因为经过刚才那样处理过后，2 ~ i-1的质因子以及除完了矛盾所以i是质数组成的合数不成立
*/
#include <bits/stdc++.h>
using namespace std;
void divide(int x) {
    for (int i = 2; i <= x / i; i++){    
    // 一个数最多只包含一个大于sqrt(N)的质因子，可以采用反证法若是存在多个，则他们相乘就大于n了，矛盾
    //所以循环终止条件为 i <= x 大于sqrt(n)的一个可以单独拿出来判断
        if(x % i ==0) {     //**这是个非常需要注意的地方，只要满足x % i == 0，i必然是质数**，简单的证明如上
            int s = 0;      //s表示这个质因数的次数
            while(x % i ==0) {
                x /= i;
                s++;
            }
            printf("%d %d\n",i, s);
        }
    }
    if(x > 1) printf("%d %d\n", x, 1);     
    puts("");                  //相当于printf("\n");
}
inline int read(){
    char c = getchar();
    int s = 0, w = 1;
    while(!isdigit(c)) {
        if(c == '-') w = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        s = (s << 3) + (s << 1) + (c ^ 48);
        c = getchar();
    }
    return w * s;
}
int main(void) {
    int n, k;
    n = read();
    while(n--) {
        k = read();
        divide(k);
    }
    return 0;
}
