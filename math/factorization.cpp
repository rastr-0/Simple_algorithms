#include <iostream>
#include <vector>
#include <algorithm>
inline bool is_prime_number(long long);
std::vector<long> factorization(long long);
int main(){
	std::vector<long long> prime_numbers;
	long long number;
	std::cin >> number;
	std::vector<long> result = factorization(number);
	auto iter = result.begin();
	while(iter != result.end()){
		std::cout << *iter << std::endl;
		iter++;
	}
	return 0;
}
inline bool is_prime_number(long long num){
	if (num == 1 || num == 0)
		return false;
	for(long long i = 2; i * i <= num; i++){
		if (num % i == 0)
			return false;
	}
	return true;
}
std::vector<long>factorization(long long num){
	std::vector<long>factorization_vec;
	if(is_prime_number(num)){
		factorization_vec.push_back(num);
		return factorization_vec;
	}
	long i = 2;
	while(!is_prime_number(num)){
		if (num % i == 0){
			factorization_vec.push_back(i);
			num /= i;
			i = 1;
		}
		i++;
	}
	factorization_vec.push_back(num);
	return factorization_vec;
}
