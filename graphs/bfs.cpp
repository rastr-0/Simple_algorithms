/*
 * Breadth-first search (BFS) - shortest distance
 *
 * Explores the graph level by level from the start vertex, so the first time
 * a vertex is reached it's by the fewest possible edges.
 *
 * Time:   O(V^2) with an adjacency matrix
 * Memory: O(V)
 *
 * Input:  N S F, then an N x N adjacency matrix (1 = edge); vertices are 0-based
 * Output: number of edges on the shortest path from S to F, -1 if unreachable
 *
 * Example: printf "3 0 2\n0 1 0\n1 0 1\n0 1 0\n" | ./bfs
 */
#include <iostream>
#include <queue>
#include <vector>
int bfs(const std::vector<std::vector<int>>& matrix, int start_point, int end_point) {
	if (start_point == end_point)
		return 0;
	std::vector<int> dist(matrix.size());
	for (auto& i : dist)
		i = -1;
	dist[start_point] = 0;
	std::queue<int> q;
	q.push(start_point); 
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
			if (dist[i] == -1 && matrix[current][i] == 1) {
				q.push(i);
				dist[i] = dist[current] + 1;
			}
		}
		if (current == end_point)
			return dist[current];
	}
	return -1; // end point is unreachable
}
int main()
{
	// I'm using adjacency matrix for input 
	int N, S, F;
	/* N - number vertices,
	S - start point of search,
	F - end point of search */
	std::cin >> N >> S >> F;
	std::vector<std::vector<int>> matrix(N);
	for (auto& i : matrix) {
		i.resize(N);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			std::cin >> matrix[i][j];
	std::cout << bfs(matrix, S, F);
}
