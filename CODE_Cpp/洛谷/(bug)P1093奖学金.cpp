#include <bits/stdc++.h>
using namespace std;
typedef struct student {
    int ID;
    int a;
    int total;
};
const int maxn = 300 + 10;
int n; 
student arr[maxn];
student temp[maxn];
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
void merge_sort(student arr[], int l , int r) {
    if(l >= r) return ;
    int mid = (r - l >> 1) + l;
    merge_sort(arr, l ,mid);
    merge_sort(arr, mid + 1, r);
    int k = 0, i = l,  j = mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i].total > arr[j].total) {
            temp[k].total = arr[i].total;
            temp[k].ID = arr[i].ID;
            i++, k++;
        }
        else if (arr[i].total == arr[j].total) {
            temp[k].total = arr[j].total;
            if(arr[i].a > arr[j].a) {
                temp[k].ID = arr[i].ID;
                i++, k++;
            }else if (arr[i].a < arr[j].a) {
                temp[k].ID = arr[j].ID;
                j++, k++;
            }else{
                if(arr[i].ID < arr[j].ID) {
                    temp[k].ID = arr[i].ID;
                    k++, i++;
                }else{
                    temp[k].ID = arr[j].ID;
                    j++, k++;
                }
            }
        }else{
            temp[k].total = arr[j].total;
            temp[k].ID = arr[j].ID;
            j++, k++;
        }
    }
    while(i <= mid) {
        temp[k].total = arr[i].total;
        temp[k].ID = arr[i].ID;
        i++, k++;
    }
    while(j <= r) {
        temp[k].total = arr[j].total;
        temp[k].ID = arr[j].ID;
        k++, j++;
    }
    for (int i = l, j = 0; i <= r; i++, j++) {
        arr[i].total = temp[j].total;
        arr[i].ID = temp[j].ID;
    }
}
int main(void) {
    //while (cin >> n) {
        cin >> n;
        for (register int i = 1; i <= n; i++) {
            arr[i].ID = i;
            arr[i].a = read();
            arr[i].total = arr[i].a + read() + read();
        }
        merge_sort(arr, 1, n);
        for (int i = 1; i <= n && i <= 5; i++) cout << arr[i].ID << " " << arr[i].total << endl;
   // }
   return 0;
}