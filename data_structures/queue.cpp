#include <iostream>
#include <string>
template<typename T>
struct Node {
	T item;
	Node<T>* next;
};
template<typename T>
class queue {
private:
	Node<T>* front;
	Node<T>* rear;
	long size;
public:
	queue() {
		front = rear = nullptr;
		size = 0;
	}
	void push(T item) {
		Node<T>* temp;
		temp = new Node<T>;
		temp->item = item;
		temp->next = nullptr;
		if (front == nullptr && rear == nullptr) {
			front = rear = temp;
		}
		else {
			rear->next = temp;
			rear = temp;
		}
		size++;
	}
	T pop() {
		if (front != nullptr) {
			Node<T>* temp;
			T item;
			temp = front;
			item = temp->item;
			front = front->next;
			delete temp;
			size--;
			return item;
		}
		return static_cast<int>(-1); // smth goes wrong
	}
	void count() {
		if (front == nullptr && rear == nullptr)
			std::cout << "-1"; // smth goes wrong
		else {
			Node<T>* temp;
			temp = front;
			while (temp) {
				std::cout << temp->item << std::endl;
				temp = temp->next;
			}
		}
	}
	long get_size() {
		return size;
	}
};
int main() {
	queue<long> first;
	std::string str;
	while (str != "0") {
		std::cin >> str;
		if (str == "push") {
			long num;
			std::cin >> num;
			first.push(num);
			std::cin.clear();
		}
		else if (str == "pop") {
			std::cout << first.pop() << std::endl;
		}
		else if (str == "count") {
			first.count();
		}
		else if (str == "size")
			std::cout << first.get_size() << std::endl;
	}
}
