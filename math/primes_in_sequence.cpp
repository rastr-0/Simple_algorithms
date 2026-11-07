#include <iostream>
#include <vector>
using namespace std;
bool is_prime_number(long long a)
{
	if (a == 1 || a == 0)
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
	vector <long long> prime_numbers;
	long long number = 1;
	while (number != 0)
	{
		std::cin >> number;
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
