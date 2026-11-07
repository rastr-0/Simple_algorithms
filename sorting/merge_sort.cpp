#include <iostream>
#include <vector>
void merge_sort(std::vector<long>& arr, long left, long right);
void merge(std::vector<long>& arr, long left, long mid, long right);
int main() {
    long size = 0;
    std::cin >> size;
    std::vector<long>arr(size);
    for (auto& i : arr)
        std::cin >> i;
    merge_sort(arr, 0, size - 1);
    for (auto i : arr)
        std::cout << i << std::endl;
}
void merge_sort(std::vector<long>& arr, long left, long right) {
    if (left < right) {
        long md = left + (right - left) / 2;
        merge_sort(arr, left, md);
        merge_sort(arr, md + 1, right);
        merge(arr, left, md, right);
    }
}
void merge(std::vector<long>& arr, long left, long mid, long right) {
    long n1, n2;
    n1 = mid - left + 1;
    n2 = right - mid;
    std::vector<long>L(n1);
    std::vector<long>M(n2);
    for (long i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (long j = 0; j < n2; j++)
        M[j] = arr[mid + j + 1];

    long i, j, k;
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
