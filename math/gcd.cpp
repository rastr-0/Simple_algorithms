#include <iostream>
#include <cstdlib>
long long gcd(long long first, long long second){
	if(first == 0)
		return second;
	else if (second == 0)
		return first;
	else
		return gcd(second, first % second);
}
int main(){
	long long num, num_1;
	std::cin >> num >> num_1;
	// gcd is defined as non-negative, so work with absolute values
	std::cout << gcd(std::llabs(num), std::llabs(num_1)) << std::endl;
	return 0;
}
