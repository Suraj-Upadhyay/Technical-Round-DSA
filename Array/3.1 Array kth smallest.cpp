#include<bits/stdc++.h>
using namespace std;

int kth_smallest(int *arr, int size, int k) {
    sort(arr, arr + size);
    return arr[k - 1];
}

int main() {
    int *arr, size, k;
    cout << "Enter size : ";
    cin >> size;
    arr = new int[size];
    cout << "Enter Array : ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    cout << "Enter k : ";
    cin >> k;
    cout << "kth smallest is : " << kth_smallest(arr, size, k) << endl;
    return 0;
}
