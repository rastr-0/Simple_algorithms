#include <iostream>
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
		if (arr[i] < arr[i - 1] && i >= 1){
			std::swap(arr[i], arr[i - 1]);
			i--;
		}
		else
			i++;
	}
	return arr;
}
