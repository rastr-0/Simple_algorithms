#include <iostream>
long binpow(long a, long n){
	if (n == 0)
		return 1;
	if (n % 2 == 0){
		long temp = binpow(a, n / 2);
		return temp * temp;
	}
	else
		return a * binpow(a, n - 1);
}
int main(){
	long a, n;
	std::cin >> a >> n;
	std::cout << binpow(a, n);
}
