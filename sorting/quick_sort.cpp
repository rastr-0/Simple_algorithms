#include <iostream>
#include <utility>
template<typename T>
void quick_sort(T* arr, long size);
int main(){
	long size;
	std::cin >> size;
	long* arr = new long[size];
	for(long i = 0; i < size; i++)
		std::cin >> arr[i];
	quick_sort(arr, size);
	for(long i = 0; i < size; i++)
		std::cout << arr[i] << std::endl;
	delete[] arr;
}
template <typename T>
void quick_sort(T* arr, long size)
{
	if (size < 2)
		return;
	long left = 0, right = size - 1;
	T mid = arr[size / 3];
	do
	{
		while (arr[left] < mid)
			left++;
		while (arr[right] > mid)
			right--;
		if (left <= right)
		{
			std::swap(arr[left], arr[right]);
			left++;
			right--;
		}
	} while (left <= right);
	if (right > 0)
		quick_sort(arr, right + 1); // [0..right] holds right + 1 elements
	if (size > left)
		quick_sort(arr + left, size - left);
}
