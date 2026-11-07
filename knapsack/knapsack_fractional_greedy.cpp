// It's greedy realisatin of version a knapsack where you can divide elements 
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

bool comp(struct Item a, struct Item b){
	float first = static_cast<float>(a.value) / static_cast<float>(a.weight);
	float second = static_cast<float>(b.value) / static_cast<float>(b.weight);
	return first > second;
}

float knapsack(std::vector<Item> arr, const int W){
	std::sort(arr.begin(), arr.end(), comp);
	//print arr
	for (int i = 0; i < arr.size(); ++i){
		std::cout << "arr[" << i << "].value "<< arr[i].value << " " << "arr[" << i << "].weight " << arr[i].weight << std::endl;
	}
	
	int current_weight = 0;
	float final_value = 0.0;
	
	for(int i = 0; i < arr.size(); ++i){
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
	std::vector<Item> arr = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	std::cout << knapsack(arr, 50);
	
}