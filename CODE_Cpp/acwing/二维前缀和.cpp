#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 10, M = 1000 + 10;

int arr[N][M],s[N][M];

int n, m, q;

int main(void) {
    cin >> n >> m >> q;
    for (int i = 1; i <=n; i++) 
        for (int j = 1; j <= m; j++) 
        cin >> arr[i][j];
        
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m ;j++) 
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + arr[i][j];
    
    while (q--) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << endl;
    }
    
    return 0;
}
