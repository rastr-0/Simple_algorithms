/*
 * Stack (linked list)
 *
 * LIFO container: push and pop happen at the same end (the top).
 *
 * Time:   O(1) push/pop, O(n) count
 * Memory: O(n)
 *
 * Input:  commands: push <n>, pop, count, is_empty, empty; finish with -1
 * Output: pop prints the value (-1 if empty), count prints all items top to bottom
 *
 * Example: printf "push 1\npush 2\npop\ncount\n-1\n" | ./stack
 */
#include <iostream>
#include <string>
template<typename T>
struct Node {
	T item;
	Node<T>* next;
};
template<typename T>
class stack {
private:
	Node<T>* ptop;
public:
	stack() {
		ptop = nullptr;
	}
	~stack() {
		empty();
	}
	stack(const stack&) = delete;
	stack& operator=(const stack&) = delete;
	void push(T element) {
		Node<T>* p;
		p = new Node<T>;
		p->item = element;
		p->next = ptop;
		ptop = p;
	}
	void count() {
		if (ptop == nullptr)
			std::cout << "0" << std::endl;
		else {
			Node<T>* p;
			p = ptop;
			while (p != nullptr) {
				std::cout << p->item << std::endl;
				p = p->next;
			}
		}
	}
	T pop() {
		if (ptop == nullptr)
			return static_cast<int>(-1); // smth goes wrong
		else {
			T temp;
			Node<T>* p;
			p = ptop;
			temp = ptop->item;
			ptop = ptop->next;
			delete p;
			return temp;
		}
	}
	bool is_empty() {
		if (ptop == nullptr)
			return true;
		return false;
	}
	void empty() {
		Node<T>* p;
		Node<T>* p2;
		p = ptop;
		while (p != nullptr) {
			p2 = p;
			p = p->next;
			delete p2;
		}
		ptop = nullptr;
	}
};
int main() {
	stack<long> first;
	std::string str;
	while (std::cin >> str && str != "-1") {
		if (str == "push") {
			long num;
			std::cin >> num;
			first.push(num);
		}
		else if (str == "pop") {
			std::cout << first.pop() << std::endl;
		}
		else if (str == "count") {
			first.count();
		}
		else if (str == "is_empty") {
			std::cout << first.is_empty() << std::endl;
		}
		else if (str == "empty") {
			first.empty();
		}
	}
}
