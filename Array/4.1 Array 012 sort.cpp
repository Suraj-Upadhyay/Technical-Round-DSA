#include<bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n) {
    int sorting_array[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) sorting_array[arr[i]]++;
    int limit = sorting_array[0], num = 0;
    for (int i = 0; i < n; i++) {
        if (!sorting_array[num]) num++;
        arr[i] = num;
        sorting_array[num]--;
    }
}

int main() {
    int *arr, n;
    cout << "Enter size : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter Array : ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort012(arr, n);
    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
