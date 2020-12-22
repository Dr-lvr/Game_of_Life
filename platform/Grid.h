#include <iostream>
#include <vector>

using namespace std;

class Grid {
	
	std::vector<std::vector<bool>> grid;
	
	Grid (std::vector<std::vector<bool>>&);
	std::vector<std::vector<bool>> refresh (std::vector<std::vector<bool>>&);
};

Grid::Grid(std::vector<std::vector<bool>> &grid){
	
	for(auto n:grid){
		grid.emplaceBack(false);
		for(auto n[grid.size()] : grid){
			
		}
	}
}; 

std::vector<std::vector<bool>> refresh(std::vector<std::vector<bool>> &grid){
	
	
};
