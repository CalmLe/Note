#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

//int arr[N][N];
int b[N][N];

void insert(int x1, int y1, int x2, int y2, int x){
    b[x1][y1] += x;
    b[x1][y2 + 1] -= x;
    b[x2 + 1][y1] -= x;
    b[x2 + 1][y2 + 1] += x;
}

int main(void) {
    int n, m;
    while (cin >> n >> m) {
        while (m--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >>y2;
            insert(x1, y1, x2, y2, 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                //arr[i][j] = arr[i - 1][j] + arr[i][j - 1] + b[i][j] - arr[i - 1][j - 1];
                    b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i -1][j -1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                //cout << arr[i][j] << " ";
                  cout << b[i][j] << " ";
            }
            cout << endl;
        }    
            
    }
    return 0;

}