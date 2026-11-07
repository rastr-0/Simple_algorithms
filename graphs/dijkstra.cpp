/*
 * Dijkstra's algorithm
 *
 * Shortest paths from one vertex to all the others in a graph with
 * non-negative edge weights: repeatedly take the closest unvisited vertex
 * and relax all its outgoing edges.
 *
 * Time:   O(V^2 + V * E) (simple version without a priority queue)
 * Memory: O(V)
 *
 * Input:  N S M, then M directed edges "from to weight"; vertices are 0-based
 * Output: "S i = distance" for every vertex i (or "unreachable")
 *
 * Example: printf "3 0 3\n0 1 4\n0 2 1\n2 1 2\n" | ./dijkstra
 */
#include <iostream>
#include <climits>
#include <vector>
using std::vector;
int find_vertex_with_min_weight(const vector<long>& weight_of_vertices, const vector<bool>& visited) {
	long min = LONG_MAX;
	int result = -1; // -1 means no reachable unvisited vertex is left
	for (int i = 0; i < static_cast<int>(weight_of_vertices.size()); i++) {
		if (visited[i] == false && weight_of_vertices[i] < min) {
			min = weight_of_vertices[i];
			result = i;
		}
	}
	return result;
}
vector<long> dijkstra_algorithm(vector<vector<long>>& list_of_ribs, const long start_point, const long size) {
	long current = start_point;
	vector<bool> visited(size, false);
	vector<long> weight_of_vertices(size, LONG_MAX);
	weight_of_vertices[current] = 0;
	long sum = 0;
	while (current != -1) {
		for (size_t i = 0; i < list_of_ribs.size(); i++) {
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
	long N; // number of vertices
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
	for (int i = 0; i < N; i++) {
		std::cout << S << " " << i << " = ";
		if (result[i] == LONG_MAX)
			std::cout << "unreachable" << std::endl;
		else
			std::cout << result[i] << std::endl;
	}
}
