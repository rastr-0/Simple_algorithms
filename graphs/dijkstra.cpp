#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using std::vector;
int find_vertex_with_min_weight(const vector<long>& weight_of_vertices, const vector<bool>& visited) {
	long min = LONG_MAX;
	int result = 0;
	for (int i = 0; i < weight_of_vertices.size(); i++) {
		if (visited[i] == false && weight_of_vertices[i] < min) {
			min = weight_of_vertices[i];
			result = i;
		}
	}
	return result;
}
bool is_there_false(bool item) {
	return item == false;
}
vector<long> dijkstra_algorithm(vector<vector<long>>& list_of_ribs, const long start_point, const long size) {
	long current = start_point;
	vector<bool> visited(size);
	for (auto i : visited)
		i = false;
	vector<long> weight_of_vertices(size);
	for (auto& i : weight_of_vertices)
		i = LONG_MAX;
	weight_of_vertices[current] = 0;
	long sum = 0;
	while (std::any_of(visited.begin(), visited.end(), is_there_false)) {
		for (int i = 0; i < size; i++) {
			if (list_of_ribs[i][0] == current) {
				sum = 0;
				sum = list_of_ribs[i][2] + weight_of_vertices[current];
				if (sum < weight_of_vertices[list_of_ribs[i][1]])
					weight_of_vertices[list_of_ribs[i][1]] = sum;
			}
		}
		visited[current] = true;
		current = find_vertex_with_min_weight(weight_of_vertices, visited);
	}
	return weight_of_vertices;
}
int main()
{
	/* I`m using list of ribs for input*/
	long N; // number ribs
	long S; // start_point
	long number_of_pairs; // how many edges are in graph(for example, 1 2 and 2 1 - two different pairs)
	std::cin >> N >> S >> number_of_pairs;
	vector<vector<long>> list_of_ribs(number_of_pairs);
	for (int i = 0; i < number_of_pairs; i++) {
		list_of_ribs[i].resize(3);
		for (int j = 0; j < 3; j++) {
			std::cin >> list_of_ribs[i][j];
		}
	}
	vector<long> result = dijkstra_algorithm(list_of_ribs, S, N);
	for (int i = 1; i < N; i++) {
		std::cout << S << " " << i << " = " << result[i] << std::endl;
	}
}
