#include<bits/stdc++.h>
using namespace std;

struct Pair {
    int max;
    int min;
};

Pair linear_getMinMax(int *arr, int size) {
    Pair minmax;
    if (size == 1) {
        minmax.max = arr[0];
        minmax.min = arr[1];
        return minmax;
    }

    if (size == 2) {
        minmax.max = max(arr[0], arr[1]);
        minmax.min = min(arr[0], arr[1]);
        return minmax;
    }

    minmax.max = arr[0];
    minmax.min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > minmax.max) minmax.max = arr[i];
        else if (arr[i] < minmax.min) minmax.min = arr[i];
    }
    return minmax;
}

Pair tournament_getMinMax(int *arr, int low, int high) {
    Pair minmax;
    if (high == low) {
        minmax.max = arr[high];
        minmax.min = arr[low];
        return minmax;
    }

    if (high == low + 1) {
        if (arr[high] > arr[low]) {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        else {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        return minmax;
    }

    int mid = floor((high + low) / 2);
    Pair minmax1 = tournament_getMinMax(arr, low, mid);
    Pair minmax2 = tournament_getMinMax(arr, mid + 1, high);

    minmax.max = max(minmax1.max, minmax2.max);
    minmax.min = min(minmax1.min, minmax2.min);

    return minmax;
}

Pair pair_getMinMax(int *arr, int size) {
    int i;
    Pair minmax;
    if (size % 2 == 0) {
        minmax.max = max(arr[0], arr[1]);
        minmax.min = min(arr[0], arr[1]);
        i = 2;
    }
    else {
        minmax.max = arr[0];
        minmax.min = arr[0];
        i = 1;
    }
    while (i < size - 1) {
        if (arr[i] < arr[i + 1]) {
            minmax.max = max(minmax.max, arr[i - 1]);
            minmax.min = min(minmax.min, arr[i]);
        }
        else {
            minmax.max = max(minmax.max, arr[i]);
            minmax.min = min(minmax.min, arr[i - 1]);
        }
        i += 2;
    }
    return minmax;
}

int main() {
    int arr1[] = {1};
    int arr2[] = {4, 2};
    int arr[] = {2, 7, 3, 1, 9, 0, 4};
    Pair pair;

    pair = linear_getMinMax(arr1, sizeof(arr1) / sizeof(int));
    cout << "Linear : " << pair.max << " " << pair.min << endl;

    pair = tournament_getMinMax(arr2, 0, sizeof(arr2) / sizeof(int) - 1);
    cout << "Tournament : " << pair.max << " " << pair.min << endl;

    pair = pair_getMinMax(arr, sizeof(arr) / sizeof(int));
    cout << "Pair : " << pair.max << " " << pair.min << endl;


    pair = linear_getMinMax(arr1, sizeof(arr1) / sizeof(int));
    cout << "Linear : " << pair.max << " " << pair.min << endl;

    pair = tournament_getMinMax(arr2, 0, sizeof(arr2) / sizeof(int) - 1);
    cout << "Tournament : " << pair.max << " " << pair.min << endl;

    pair = pair_getMinMax(arr, sizeof(arr) / sizeof(int));
    cout << "Pair : " << pair.max << " " << pair.min << endl;


    pair = linear_getMinMax(arr1, sizeof(arr1) / sizeof(int));
    cout << "Linear : " << pair.max << " " << pair.min << endl;

    pair = tournament_getMinMax(arr2, 0, sizeof(arr2) / sizeof(int) - 1);
    cout << "Tournament : " << pair.max << " " << pair.min << endl;

    pair = pair_getMinMax(arr, sizeof(arr) / sizeof(int));
    cout << "Pair : " << pair.max << " " << pair.min << endl;

    return 0;
}
