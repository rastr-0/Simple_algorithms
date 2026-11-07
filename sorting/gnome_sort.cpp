/*
 * Gnome sort
 *
 * Like a garden gnome sorting flower pots: if the current element is smaller
 * than the previous one, swap them and step back, otherwise step forward.
 *
 * Time:   O(n^2), O(n) on already sorted input
 * Memory: O(1)
 *
 * Input:  n, then n integers
 * Output: the sorted numbers, one per line
 *
 * Example: echo "5  3 1 4 1 5" | ./gnome_sort
 */
#include <iostream>
#include <utility>
#include <vector>

std::vector<long>& gnome_sort(std::vector<long>& arr);

int main(){
	long size = 0;
	std::cin >> size;
	std::vector<long> arr(size);
	for(auto& i : arr)
		std::cin >> i;
	arr = gnome_sort(arr);
	for(auto i : arr)
		std::cout << i << std::endl;
}
std::vector<long>& gnome_sort(std::vector<long>& arr){
	long i = 1;
	long size = arr.size();
	while(i < size){
		if (i >= 1 && arr[i] < arr[i - 1]){ // check i first, so arr[-1] is never read
			std::swap(arr[i], arr[i - 1]);
			i--;
		}
		else
			i++;
	}
	return arr;
}
