/*
 * Deque (doubly linked list)
 *
 * Double-ended queue: push and pop on both ends.
 *
 * Time:   O(1) for every push/pop, O(n) count
 * Memory: O(n)
 *
 * Input:  commands: push_back <n>, push_front <n>, pop_back, pop_front, back, front,
 *                  size, count; finish with 0
 * Output: values of pop/back/front (-1 if empty), count prints rear to front
 *
 * Example: printf "push_back 1\npush_front 2\npop_back\nfront\n0\n" | ./deque
 */
#include <iostream>
#include <string>
template<typename T>
struct Node {
	T item;
	Node<T>* next;
	Node<T>* prev;
};
template<typename T>
class deque {
private:
	Node<T>* front;
	Node<T>* rear;
	long size;
public:
	deque() {
		front = nullptr;
		rear = nullptr;
		size = 0;
	}
	~deque() {
		while (size > 0)
			pop_back();
	}
	deque(const deque&) = delete;
	deque& operator=(const deque&) = delete;
	void push_back(T item) {
		Node<T>* temp;
		temp = new Node<T>;
		temp->item = item;
		temp->next = nullptr;
		temp->prev = nullptr;
		if (front == nullptr && rear == nullptr)
			front = rear = temp;
		else {
			rear->next = temp;
			temp->prev = rear;
			rear = temp;
		}
		size++;
	}
	void push_front(T item) {
		Node<T>* temp;
		temp = new Node<T>;
		temp->item = item;
		temp->next = nullptr;
		temp->prev = nullptr;
		if (front == nullptr && rear == nullptr) {
			front = rear = temp;
		}
		else {
			temp->next = front;
			front->prev = temp;
			front = temp;
		}
		size++;
	}
	T pop_back() {
		if (size > 1) {
			Node<T>* temp;
			temp = rear;
			T item = temp->item;
			rear = rear->prev;
			rear->next = nullptr;
			delete temp;
			size--;
			return item;
		}
		else if (size == 1) {
			T item = rear->item;
			delete rear;
			front = rear = nullptr; // the deque is empty again
			size--;
			return item;
		}
		return static_cast<int>(-1);
	}
	T pop_front() {
		if (size > 1) {
			Node<T>* temp;
			temp = front;
			T item = temp->item;
			front = temp->next;
			front->prev = nullptr;
			delete temp;
			size--;
			return item;
		}
		else if (size == 1) {
			T item = front->item;
			delete front;
			front = rear = nullptr; // the deque is empty again
			size--;
			return item;
		}
		return static_cast<int>(-1);
	}
	long get_size() {
		return size;
	}
	void count() {
		if (size > 0) {
			Node<T>* temp;
			temp = rear;
			while (temp != nullptr) {
				std::cout << temp->item << std::endl;
				temp = temp->prev;
			}
		}
		else {
			std::cout << "-1" << std::endl;
		}
	}
	T get_back() {
		if (size > 0)
			return rear->item;
		else
			return static_cast<int>(-1);
	}
	T get_front() {
		if (size > 0)
			return front->item;
		else
			return static_cast<int>(-1);
	}
};
int main() {
	deque<long> first;
	std::string str;
	while (std::cin >> str && str != "0") {
		if (str == "push_back") {
			long num;
			std::cin >> num;
			first.push_back(num);
			std::cin.clear();
		}
		else if (str == "push_front") {
			long num;
			std::cin >> num;
			first.push_front(num);
			std::cin.clear();
		}
		else if (str == "pop_back")
			std::cout << first.pop_back() << std::endl;
		else if (str == "pop_front")
			std::cout << first.pop_front() << std::endl;
		else if (str == "count")
			first.count();
		else if (str == "size")
			std::cout << first.get_size() << std::endl;
		else if (str == "back")
			std::cout << first.get_back() << std::endl;
		else if (str == "front")
			std::cout << first.get_front() << std::endl;
	}
}
