#include <iostream>
#include <stack>
#include <vector>
bool dfs(const std::vector<std::vector<int>>& matrix, int start_point, int end_point) {
	if (start_point == end_point)
		return true;
	std::stack<int> st;
	std::vector<bool> visited(matrix.size());
	for (auto i : visited)
		i = false;
	st.push(start_point);
	while (!st.empty()) {
		int current = st.top();
		if (current == end_point)
			return true;
		visited[current] = true;
		st.pop();
		for (int i = 0; i < matrix.size(); i++)
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
