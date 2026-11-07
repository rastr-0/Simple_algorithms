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
		for (int i = 0; i < matrix.size(); i++) {
			if (dist[i] == -1 && matrix[current][i] == 1) {
				q.push(i);
				dist[i] = dist[current] + 1;
			}
		}
		if (current == end_point)
			return dist[current];
	}
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
