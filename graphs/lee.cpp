#include <iostream>
#include <array>
#include <queue>

int const ROW = 5;
int const COL = 5;

struct Cell{
    int x;
    int y;
};

struct QueueNode{
    Cell pt;
    int dist;
};

bool Check(int row, int col){
    return ((row >= 0 && row < ROW) && (col >= 0 && col < COL));
}

int LeeAlgorithm(const std::array<std::array<int, COL>, ROW>& matrix, const Cell& initial, const Cell& dest){
    if (matrix[initial.x][initial.y] != 1 || matrix[dest.x][dest.y] != 1)
        return -1;
    std::array<int, 4> RowNum = {-1, 0, 0, 1};
    std::array<int, 4> ColNum = {0, -1, 1, 0};
    std::array<std::array<bool, COL>, ROW> visited = {{
       {false},
       {false},
       {false},
       {false},
       {false}
    }};
    visited[initial.x][initial.y] = true;
    QueueNode s = {initial, 0};
    std::queue<QueueNode> QueuePoints;
    QueuePoints.push(s);
    while (!QueuePoints.empty()){
        QueueNode curr = QueuePoints.front();
        Cell pt(curr.pt);
        
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist; // 0
        QueuePoints.pop();
    
        for (int i = 0; i < 4; ++i){
            int row = pt.x + RowNum[i];
            int col = pt.y + ColNum[i];
            if (Check(row, col) && matrix[row][col] && !visited[row][col]){
                    visited[row][col] = true;
                    QueueNode AdjCell = {{row, col}, curr.dist + 1};
                    QueuePoints.push(AdjCell);
                }
            }
        }
    return -1;
    }
int main(){
    std::array<std::array<int, COL>, ROW> matrix = {{
        { 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1 },
		{ 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1 }
    }};
    
    Cell initial = {0, 0};
    Cell dest = {2, 1};
    
    int dist = LeeAlgorithm(matrix, initial, dest);
    
    if (dist != -1)
        std::cout << "The length of the path is " << dist;
    else
        std::cout << "It's impossible to find the path";
}
