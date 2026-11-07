#include <iostream>
#include <vector>
long binary_search(std::vector<long>& arr, long num, long left, long right) {
	if (right >= left) {
		long md = left + (right - left) / 2;
		if (arr[md] == num)
			return md;
		if (arr[md] > num)
			return binary_search(arr, num, left, md - 1);
		return binary_search(arr, num, md + 1, right);
	}
	return -1;
}
int main() {
	long size, num;
	std::cin >> size;
	std::vector<long> arr(size);
	for (auto& i : arr)
		std::cin >> i;
	std::cin >> num;
	std::cout << binary_search(arr, num, 0, arr.size() - 1);
}
