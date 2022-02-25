#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int primes[maxn], cnt;
bool st[maxn];   // 定义在全局变量默认是0，（false）
/*
朴素筛时间复杂度近似为 O(nlogn) 
*/
void get_primes_1(int n) {
    for (int i = 2; i <= n; i++) {
        if(!st[i]) {
            primes[cnt++] = i;          //如果没用被筛过就说明是质数
        }
        for (int j = i + i; j <= n; j += i) {
            st[j] = true;              //筛掉每一个数的倍数
        }
    }
}
/*
埃氏筛  时间复杂度为 O(n log log n) 近似于O(n)
埃氏筛的核心思路：每一个合数都可以被质数筛掉，所以用每个质数筛掉合数；
但这样也存在问题，因为也会存在重复筛选的情况
*/
void get_primes_2(int n) {
    for (int i = 2; i <= n; i++) {      
        if(!st[i]) {                  
            primes[cnt++] = i;         //如果没用被筛过就说明是质数
            for (int j = i + i; j <= n; j += i) {
//筛掉每一个质数(为什么筛掉质数的倍数就可以了呢？参考算术基本定理)的倍数，筛掉每个数的倍数，存在重复筛选浪费时间
                st[j] = true;  
            }
        }
    }
}
/*
线性筛 时间复杂度为n;
线性筛法的基本思路也是一样的：争取把每个合数，用它的某一个质因子筛掉
线性筛法的核心思路：每一个合数，只会被它的最小质因子筛掉,这样时间复杂度大大降低
*/
void get_primes_3(int n) {
    for (int i = 2; i <= n; i++) {
        if(!st[i]) primes[cnt++] = i;
    /*
    第二层循环枚举j的时候可以不加上j <= cnt的边界条件，因为i为合数时会在j=最小质因子时停止，i为质数时会在j=i时停止
    */
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;    // primes[j]一定是primes[j] * i的最小质因子
            if(i % primes[j] == 0) break; //至于为什么要这一句话呢？下面就来说一下
        /*
        注：为了简便这里的pj代替primes[j]
            > 若i % pj != 0, 说明pj不是i的一个质因数，记p为i的一个质因数, 则pj < p, 
            又因为pj是质数，所以pj是pj * i的最小公因子
            > 若i % pj == 0, 说明pj是i的一个质因数,此时若不跳出循环则继续执行st[primes[j+1]*i] = true,
            而prime[j+1]*i的最小质因子应该是primes[j+1]，而我们就是要通过最小质因子筛选，所以矛盾了
        */
        }
    }
}
int main(void) {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    get_primes_1(n);
    cout << cnt-- << endl;
    return 0;
} 