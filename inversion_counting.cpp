#include <iostream>
#include <vector>

long long merge(std::vector<int>& arr, int low, int mid, int high) {
    std::vector<int> temp(high - low + 1);
    long long inversions = 0;

    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }

    return inversions;
}

long long mergeSort(std::vector<int>& arr, int low, int high) {
    long long inversions = 0;

    if (low < high) {
        int mid = low + (high - low) / 2;

        inversions += mergeSort(arr, low, mid);
        inversions += mergeSort(arr, mid + 1, high);
        inversions += merge(arr, low, mid, high);
    }

    return inversions;
}

long long countInversions(std::vector<int>& arr) {
    int n = arr.size();
    return mergeSort(arr, 0, n - 1);
}