#include <iostream>
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
	long left = 0, right = size - 1;
	long mid = arr[size / 3];
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
		quick_sort(arr, right);
	if (size > left)
		quick_sort(arr + left, size - left);
}
