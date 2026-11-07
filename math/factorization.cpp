#include <iostream>
#include <vector>
std::vector<long long> factorization(long long);
int main(){
	long long number;
	std::cin >> number;
	if (number < 2){
		std::cout << "The number must be >= 2" << std::endl;
		return 1;
	}
	std::vector<long long> result = factorization(number);
	auto iter = result.begin();
	while(iter != result.end()){
		std::cout << *iter << std::endl;
		iter++;
	}
	return 0;
}
// Trial division: divide by every i while it divides the number.
// Every i that divides at this point is prime, because all of its own
// smaller prime factors were already divided out.
std::vector<long long> factorization(long long num){
	std::vector<long long> factorization_vec;
	for (long long i = 2; i * i <= num; i++){
		while (num % i == 0){
			factorization_vec.push_back(i);
			num /= i;
		}
	}
	// what is left (if anything) is a prime bigger than sqrt of the original number
	if (num > 1)
		factorization_vec.push_back(num);
	return factorization_vec;
}
