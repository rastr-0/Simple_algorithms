#include <cmath>
#include <chrono>
#include <queue>
#include <vector>
#include <iostream>
#include <tuple>
#include <queue>
#include <set>
#include <stack>
#include <array>

typedef std::pair<int, int> Pair;
typedef std::tuple<float, int, int> Tuple;


struct Cell{
	Pair parent;
	int h;
	float f, g;
	Cell()
		: parent(-1, -1),
		f(-1),
		g(-1),
		h(-1)
	{}
};

bool is_valid(const std::vector<std::vector<int>>& grid, const Pair& point){
	return (point.first >= 0 && point.first < grid.size())
		&& (point.second >= 0 && point.second < grid.size());
}

bool is_unblocked(const std::vector<std::vector<int>>& grid, const Pair& point){
	return is_valid(grid, point)
	&& grid[point.first][point.second] == 1;
}

bool is_destination_point(const Pair& point, const Pair& dest){
	return point == dest;
}

int calculate_heuristics(const Pair& current, const Pair& dest){
	return abs(current.first - dest.first) + abs(current.second - dest.second);
}

void trace_path(const std::vector<std::vector<Cell>>& cell_details, const Pair& end_point){
	std::cout << "The path: ";
	// create stack for printing points in the right way(start -> end)
	std::stack<Pair> path;
	int i, j;
	i = j = end_point.second;
	// next point from the start
	Pair next_point = cell_details[i][j].parent;
	do{
		path.push(next_point);
		next_point = cell_details[i][j].parent;
		i = next_point.first;
        j = next_point.second;
    } while (cell_details[i][j].parent != next_point);
 
    path.emplace(i, j);
	/* Here's kind of dirty hack, i don't know how to realize it in another way.
	If you'll find a bit more elegant decision -> create pull request*/ 
    while (path.size() != 1) {
        Pair p = path.top();
        path.pop();
		std::cout << "->" << " (" << p.first << ";" << p.second << ") ";
	}
	std::cout << "->" << " (" << end_point.first << ";" << end_point.second << ") ";
}
void A_star(const std::vector<std::vector<int>>& grid, const Pair& start_point, const Pair& end_point){
	// the initial conditions
	if (!is_valid(grid, start_point) || !is_valid(grid, end_point)){
		std::cout << "Start point and/or end point are/is invalid";
		return;
	}
	else if (!is_unblocked(grid, start_point) || !is_unblocked(grid, end_point)){
		std::cout << "Start and/or end point are/is wall(s)";
		return;
	}
	else if (is_destination_point(start_point, end_point)){
		std::cout << "The start point and the end point are in the same place";
		return;
	}
	
	// vector for points which we've already visited
	std::vector<std::vector<bool>> closed(grid.size(), std::vector<bool>(grid.size(), false));
	// vector for detaling information about each point
	
	std::vector<std::vector<Cell>> cell_details(grid.size());
	for (int i = 0; i < cell_details.size(); ++i)
		cell_details[i].resize(grid.size());
	int i = start_point.first;
	int j = start_point.second;
	cell_details[i][j].f = 0.0;
	cell_details[i][j].g = 0.0;
	cell_details[i][j].h = 0;
	cell_details[i][j].parent = {i, j};
	std::priority_queue<Tuple, std::vector<Tuple>, 
	std::greater<Tuple>> open;
	open.emplace(0.0, i, j);
	while (!open.empty()){
		/* the start point isn't the end point
			that's mean we have to mark start point
			in closed list as *visited*
		*/
		const Tuple& point = open.top();
		// syntax for unpacking Tuple
		i = std::get<1>(point);
		j = std::get<2>(point);
		
		open.pop();
		closed[i][j] = true;
		/*
		In my realisation it's possible to move
	only in 8 directions
									
	   W.N	N	N.E
		\	|	/
		 \  |  /
	W --- point --- E
		 /  |  \
		/	|	\
	   S.W	S	E.S
		
		
		N(i - 1; j)
		N.E(i - 1; j + 1)
		E(i; j + 1)
		E.S(i + 1; j + 1)
		S(i + 1; j)
		S.W(i + 1; j - 1)
		W(i; j - 1)
		W.N(i - 1; j - 1)
		*/
		for(int x_h = -1; x_h <= 1; ++x_h){
			for (int y_h = -1; y_h <= 1; ++y_h){
				Pair neighbor(i + x_h, j + y_h);
				
				// check if this point is valid
				if (is_valid(grid, neighbor)){
					if (is_destination_point(neighbor, end_point)){
						std::cout << "We found the path between start and end points!" << std::endl;
						// set coordinates for parent of end point
						cell_details[neighbor.first][neighbor.second].parent = {i, j};
						trace_path(cell_details, end_point);
						return;
					}
				/*
				if *neighbor* is already in list with *visited*
				points or it's wall or smth like this --> skip it
				*/
				else if (!closed[neighbor.first][neighbor.second]
				&& is_unblocked(grid, neighbor)){
					// calculating heuristics value 
					int new_h = calculate_heuristics(neighbor, end_point);
					/*
					the value g of the neighbor is calculating as
					(previous point + path weight)
					in my realisation all paths have weight = 1
					*/
					float new_g = cell_details[i][j].g + 1.0;
					float new_f = new_g + new_h;
					
					if (cell_details[neighbor.first][neighbor.second].f == -1
					|| cell_details[neighbor.first][neighbor.second].f > new_f){
						open.emplace(new_f, neighbor.first, neighbor.second);
						// updating the details about points
						int k = neighbor.first;
						int l = neighbor.second;
						cell_details[k][l].g = new_g;
						cell_details[k][l].h = new_h;
						cell_details[k][l].f = new_f;
						cell_details[k][l].parent = {i, j};
						}	
					}
				}
			}
		}
	} 
	/*
	if the end point isn't find and the open list is empty,
	that's mean we failed to find the end point
	*/
	std::cout << "There're any path between start and end points";
} 

int main(){
	// example of grid, just for testing
	std::vector<std::vector<int>> grid = {
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
	};
	// the same with points
	Pair start = {8, 0};
	Pair end = {0, 0};
	
	A_star(grid, start, end);
}