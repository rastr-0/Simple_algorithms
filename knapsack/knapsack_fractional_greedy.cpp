/*
 * Fractional knapsack (greedy)
 *
 * Items can be cut, so greedily take the items with the best value/weight
 * ratio first, and a fraction of the first one that doesn't fit.
 *
 * Time:   O(n log n)
 * Memory: O(n)
 *
 * Input:  none - items and capacity W are in main()
 * Output: the maximum total value
 *
 * Example: ./knapsack_fractional_greedy
 */
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
struct Item{
	int weight;
	int value;
	Item(int value, int weight){
		this->weight = weight;
		this->value = value;
	}
};

// sort by value/weight ratio, best first.
// a.value / a.weight > b.value / b.weight is compared by cross-multiplying,
// so an item with weight 0 doesn't cause a division by zero.
bool comp(const Item& a, const Item& b){
	return static_cast<long long>(a.value) * b.weight > static_cast<long long>(b.value) * a.weight;
}

float knapsack(std::vector<Item> arr, const int W){
	std::sort(arr.begin(), arr.end(), comp);
	int current_weight = 0;
	float final_value = 0.0;
	
	for(size_t i = 0; i < arr.size(); ++i){
		if (current_weight + arr[i].weight <= W){
			current_weight += arr[i].weight;
			final_value += arr[i].value;
		}
		else{
			int part = W - current_weight;
			final_value += arr[i].value * (static_cast<float>(part) / static_cast<float>(arr[i].weight));
			break;
		}
	}
	return final_value;
}

int main(){
	// {value, weight}
	std::vector<Item> arr = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	std::cout << knapsack(arr, 50) << std::endl;
	
}