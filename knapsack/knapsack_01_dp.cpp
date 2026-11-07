// This's implementation for the 0-1 knapsack problem, in this programm I use dynamic programming approach
#include <vector>
#include <iostream>

struct Item{
	int weight;
	int value;
	Item(int weight, int value){
		this->weight = weight;
		this->value = value;
	}
};

int max(const int first, const int second){
	return (first > second) ? first : second;
}
int knapsack(const std::vector<Item>& arr, const int W){
	std::vector<std::vector<int>> matrix(arr.size() + 1, std::vector<int>(W + 1));
	int i, j;
	for (i = 0; i <= arr.size(); i++){
		for (j = 0; j <= W; j++){
			if (i == 0 || j == 0)
				matrix[i][j] = 0;
			else if (arr[i - 1].weight <= j)
				matrix[i][j] = max(arr[i - 1].value + matrix[i - 1][j - arr[i - 1].weight],
                                matrix[i - 1][j]);
			else
				matrix[i][j] = matrix[i - 1][j];
		}
	}
	for(int ki = 0; ki <= arr.size(); ki++){
		for (int kj = 0; kj <= W; kj++){
			std::cout << "matrix" << "[" << ki << "]" << ""<< kj<< "]" << " = " << matrix[ki][kj] << std::endl;
		}
		std::cout << std::endl << std::endl;
	}
	return matrix[i - 1][j - 1];
}
int main(){
	std::vector<Item> arr = {{10, 60}, {20, 100}, {30, 120}};
	const int W = 50;
	std::cout << knapsack(arr, W);
}