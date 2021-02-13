#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void partition_approach(int *arr, int n) {
    int j = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            swap(arr[i], arr[j++]);
}

void two_pointer_approach(int *arr, int n) {
    int i = 0, j = n - 1;
    while (i <= j) {
        if (arr[i] < 0 && arr[j] < 0) i++;
        else if (arr[i] > 0 && arr[j] > 0) j--;
        else if (arr[i] < 0 && arr[j] > 0) {i++; j--;}
        else swap(arr[i++], arr[j--]);
    }
}

int main() {
    int *arr1, *arr2, n;
    cout << "Enter Size : ";
    cin >> n;
    arr1 = new int[n];
    arr2 = new int[n];
    cout << "Enter Array : ";
    for (int i = 0; i < n; i++) {cin >> arr1[i]; arr2[i] = arr1[i];}
    partition_approach(arr1, n);
    two_pointer_approach(arr2, n);
    for (int i = 0; i < n; i++) {cout << arr1[i] << " ";} cout << endl;
    for (int i = 0; i < n; i++) {cout << arr2[i] << " ";} cout << endl;
    delete arr1, arr2;
    return 0;
}
