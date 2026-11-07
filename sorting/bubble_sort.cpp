#include <iostream>
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
	long size = arr.size() - 1;
	for(long i = 0; i < size; i++){
		for(long j = 0; j < size - i; j++){
			if (arr[j] > arr[j + 1]){
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
	return arr;
}
