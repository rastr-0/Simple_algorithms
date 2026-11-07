/*
 * Gapped exchange sort
 *
 * Compares and swaps elements that are `h` apart, halving h each round
 * (n/2, n/4, ..., 1). The big gaps move far-away elements quickly, the final
 * h = 1 round finishes the job. NOTE: it looks like Shell sort but isn't one -
 * Shell sort does an *insertion* sort for each gap.
 *
 * Time:   O(n^2)
 * Memory: O(1)
 *
 * Input:  n, then n integers
 * Output: the sorted numbers, one per line
 *
 * Example: echo "5  3 1 4 1 5" | ./gapped_exchange_sort
 */
#include <iostream>
#include <utility>
#include <vector>
std::vector<long>& gapped_exchange_sort(std::vector<long>& arr);
int main() {
    long size;
    std::cin >> size;
    std::vector<long> arr(size);
    for (auto& i : arr) {
        std::cin >> i;
    }
    arr = gapped_exchange_sort(arr);
    for (auto i : arr) {
        std::cout << i << std::endl;
    }

}
std::vector<long>& gapped_exchange_sort(std::vector<long>& arr) {
    long size = arr.size();
    long h = size / 2;
    while (h > 0) {
        for (long i = 0; i < size; i++) {
            for (long j = i + h; j < size; j += h) {
                if(arr[i] > arr[j])
                    std::swap(arr[i], arr[j]);
            }
        }
        h /= 2;
    }
    return arr;
}
