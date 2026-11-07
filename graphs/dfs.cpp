/*
 * Depth-first search (DFS) - reachability
 *
 * Goes as deep as possible along each branch (using an explicit stack)
 * before backtracking, and answers whether F can be reached from S.
 *
 * Time:   O(V^2) with an adjacency matrix
 * Memory: O(V^2) stack in the worst case
 *
 * Input:  N S F, then an N x N adjacency matrix (1 = edge); vertices are 1-based here
 * Output: Yes or No
 *
 * Example: printf "3 1 3\n0 1 0\n1 0 1\n0 1 0\n" | ./dfs
 */
#include <iostream>
#include <stack>
#include <vector>
bool dfs(const std::vector<std::vector<int>>& matrix, int start_point, int end_point) {
	if (start_point == end_point)
		return true;
	std::stack<int> st;
	std::vector<bool> visited(matrix.size(), false);
	st.push(start_point);
	while (!st.empty()) {
		int current = st.top();
		if (current == end_point)
			return true;
		st.pop();
		if (visited[current])
			continue; // already expanded via another path
		visited[current] = true;
		for (int i = 0; i < static_cast<int>(matrix.size()); i++)
			if (matrix[current][i] == 1 && visited[i] == false)
				st.push(i);
	}
	return false;
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
	(dfs(matrix, S - 1, F - 1) == 1) ? std::cout << ("Yes") : std::cout << ("No");
}
