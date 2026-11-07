#include <iostream>
#include <cstring>
void eratosthenes_sieve(long end){
	bool arr[end + 1];
	memset(arr, true, end);
	if (end >= 2){
		arr[0] = false;
		arr[1] = false;
	}
	for(int i = 2; i * i <= end; i++){
		if (arr[i] == true){
			for(int j = i * i; j <= end; j += i){
				arr[j] = false;
			}
		}
	}
	for(int i = 0; i <= end; i++){
		if (arr[i])
			std::cout << i << " ";
	}
}
int main(){
	long n;
	std::cin >> n;
	eratosthenes_sieve(n);
}
