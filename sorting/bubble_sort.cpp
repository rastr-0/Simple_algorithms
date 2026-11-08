/*
 * Bubble sort
 *
 * Repeatedly walks through the array and swaps neighbours that are in the
 * wrong order. After pass i the i biggest elements are at the end.
 *
 * Time:   O(n^2)
 * Memory: O(1)
 *
 * Input:  n, then n integers
 * Output: the sorted numbers, one per line
 *
 * Example: echo "5  3 1 4 1 5" | ./bubble_sort
 */
#include <iostream>
#include <utility>
#include <vector>
std::vector<long>& bubble_sort(std::vector<long>& arr);

int main(){
	long size;
	std::cin >> size;
	std::vector<long> arr(size);
	for(auto& i : arr){
		std::cin >> i;
	}
	arr = bubble_sort(arr);
	for(auto i : arr)
		std::cout << i << std::endl;
	return 0;
}
std::vector<long>& bubble_sort(std::vector<long>& arr){
	long size = static_cast<long>(arr.size()) - 1;
	for(long i = 0; i < size; i++){
		for(long j = 0; j < size - i; j++){
			if (arr[j] > arr[j + 1]){
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
	return arr;
}
