#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Início da primeira metade
    int j = mid + 1; // Início da segunda metade
    int k = left;    // Início do vetor temporário
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (left < right) {
        mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int N;
    cin >> N;
    
    int arr[N];
    int temp[N];
    
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    int result = mergeSortAndCount(arr, temp, 0, N - 1);
    
    cout << result << endl;
    
    return 0;
}
