#include <iostream>
#include <vector>
std::vector<long>& insertion_sort(std::vector<long>& arr);
int main() {
    long size;
    std::cin >> size;
    std::vector<long> arr(size);
    for (auto& i : arr) {
        std::cin >> i;
    }
    arr = insertion_sort(arr);
    for (auto i : arr) {
        std::cout << i << std::endl;
    }

}
std::vector<long>& insertion_sort(std::vector<long>& arr) {
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
