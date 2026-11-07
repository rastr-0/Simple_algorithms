#include <iostream>
inline long gcd(long long first, long long second){
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
	std::cout << gcd(num , num_1);
	return 0;
}
