#include <iostream>

using namespace std;

const int N = 10e6 + 10;

int n;

int arr[N],temp[N];

void merge_sort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(arr, l , mid);
    merge_sort(arr, mid + 1, r);
    int k = 0, i = l , j =mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i];
            i++;
        }else{
            temp[k++] =arr[j];
            j++;
        }
    }
    while (i <= mid ) {
        temp[k++] = arr[i];
        i++;
    }
    while (j <= r) {
        temp[k++] =arr[j];
        j++;
    }
    
    for (int i =l, j=0; i <= r; i++ , j++) arr[i] = temp[j];
    
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n;i++) {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr,0,n-1);
    
    for (int i = 0;i < n; i++) {
        printf("%d ",arr[i]);
    }
    
    
    
    return 0;
    
}