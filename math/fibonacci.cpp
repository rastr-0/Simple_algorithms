/*
 * Fibonacci numbers
 *
 * Prints n Fibonacci numbers iteratively, starting from 2 (1 1 are skipped):
 * 2 3 5 8 13 ... NOTE: values overflow long after the ~90th number.
 *
 * Time:   O(n)
 * Memory: O(1)
 *
 * Input:  n
 * Output: n Fibonacci numbers separated by spaces
 *
 * Example: echo "10" | ./fibonacci
 */
#include <iostream>
void fibonacci_numbers(long n){
	long prev = 1, current = 1;
	long i = 0;
	while(i < n){
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
	std::cout << std::endl;

}
