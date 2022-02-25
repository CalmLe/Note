#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int arr[N][N], b[N][N];

int n, m, q;

void insert(int x1, int x2, int y1, int y2, int c){
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main(void) {
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> arr[i][j];
            
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            insert(i,i,j,j,arr[i][j]);
            
    int x1, x2, y1, y2, c;
    
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, x2, y1, y2, c);
    }

    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= m; j++)  
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1]; 
            
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) 
            cout << b[i][j]<<" ";
        cout<< endl;
    }
        
    
            
    return 0;
    
    
}