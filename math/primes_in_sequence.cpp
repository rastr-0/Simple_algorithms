#include <iostream>
#include <vector>
bool is_prime_number(long long a)
{
	if (a < 2) // 0, 1 and negative numbers are not prime
		return false;
	for (long long i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}
int main()
{
	std::vector<long long> prime_numbers;
	long long number;
	// read numbers until 0 (or until the input ends)
	while (std::cin >> number && number != 0)
	{
		if (is_prime_number(number))
			prime_numbers.push_back(number);
	}
	auto iter = prime_numbers.begin();
	while(iter != prime_numbers.end()){
		std::cout << *iter << std::endl;
		iter++;
	}
	return 0;
}
