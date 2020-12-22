/*
	CaseStudy - Game of Life
	
	Autore: Davide Riva
*/
#include <cstdlib>
#include <ctime>

static const int GRID_CONST= 300;

inline bool initGrid(bool grid[GRID_CONST][GRID_CONST])
{
	for(int i=0; i<GRID_CONST; i++)
	{//init grid
		for(int j=0; j<GRID_CONST; j++)
		{
			grid[i][j]=false;
		}
	}
	return grid;
}
inline bool randomGen(bool grid[GRID_CONST][GRID_CONST])
{
	srand(time(NULL));
	
	for(int i=0; i<GRID_CONST; i++)
	{//init grid
		for(int j=0; j<GRID_CONST; j++)
		{
			grid[i][j]=(rand()%2);
		}
	}
	return grid;
}
inline bool passGrid(bool grid[GRID_CONST][GRID_CONST], bool grid2[GRID_CONST][GRID_CONST])
{
	for(int i=0; i<GRID_CONST; i++)
		{
			for(int j=0; j<GRID_CONST; j++)
			{//copy update grid on the old grid
				grid[i][j]=grid2[i][j];
			}
		}
	return grid;
}
