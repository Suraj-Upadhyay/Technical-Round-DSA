#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void inverse_iterative (int *arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void inverse_recursive (int *arr, int start, int end) {
    if (start >= end) return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    inverse_recursive(arr, start + 1, end - 1);
}

void display(int *arr, int num) {
    for (int i = 0; i < num; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int num = sizeof(arr) / sizeof(int);

    inverse_iterative(arr, 0, num - 1);
    display(arr, num);

    inverse_recursive(arr, 0, num - 1);
    display(arr, num);

    return 0;
}
