/*
 * Primes in a sequence
 *
 * Reads numbers and keeps the prime ones, testing each by trial division up
 * to its square root. Better than the sieve when the numbers are few but big.
 *
 * Time:   O(sqrt(x)) per number
 * Memory: O(count of primes)
 *
 * Input:  integers, finished with 0
 * Output: the prime ones, one per line
 *
 * Example: echo "2 4 7 9 11 0" | ./primes_in_sequence
 */
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
