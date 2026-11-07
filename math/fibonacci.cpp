#include <iostream>
void fibonacci_numbers(long n){
	long prev = 1, current = 1;
	int i = 0;
	while(i != n){
		i++;
		std::cout << current + prev << " ";
		long temp = current;
		current += prev;
		prev = temp;
	}
}
int main(){
	long n;
	std::cin >> n;
	fibonacci_numbers(n);

}
