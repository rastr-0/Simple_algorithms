#include <iostream>
#include <vector>
void eratosthenes_sieve(long end){
	if (end < 2)
		return; // there are no primes below 2
	// heap-allocated, so big `end` values don't overflow the stack
	std::vector<bool> arr(end + 1, true);
	arr[0] = false;
	arr[1] = false;
	for(long i = 2; i * i <= end; i++){
		if (arr[i] == true){
			for(long j = i * i; j <= end; j += i){
				arr[j] = false;
			}
		}
	}
	for(long i = 0; i <= end; i++){
		if (arr[i])
			std::cout << i << " ";
	}
}
int main(){
	long n;
	std::cin >> n;
	eratosthenes_sieve(n);
	std::cout << std::endl;
}
