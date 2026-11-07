#include <iostream>
#include <vector>

std::vector<long>& sort_by_inserts(std::vector<long>&);

int main() {
    long size;
    std::cin >> size;
    std::vector<long> arr(size);
    for (auto& i : arr)
        std::cin >> i;
    arr = sort_by_inserts(arr);
    for (auto i : arr)
        std::cout << i << std::endl;
    return 0;
}
std::vector<long>& sort_by_inserts(std::vector<long>& arr) {
    long size = arr.size();
    long temp, item;
    for (long i = 1; i < size; i++) {
        temp = arr[i];
        item = i - 1;
        while (item >= 0 && arr[item] > temp) {
            arr[item + 1] = arr[item];
            arr[item] = temp;
            item--;
        }
    }
    return arr;
}

