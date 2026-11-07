/*
 * Binary search
 *
 * Finds a value in a sorted array by comparing it with the middle element
 * and discarding the half where it can't be. Recursive.
 *
 * Time:   O(log n)
 * Memory: O(log n) recursion stack
 *
 * Input:  n, then n integers in ascending order, then the value to find
 * Output: index of the value (0-based) or -1 if it's not there
 *
 * Example: echo "5  1 3 5 7 9  7" | ./binary_search
 */
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
	std::cout << binary_search(arr, num, 0, static_cast<long>(arr.size()) - 1) << std::endl;
}
