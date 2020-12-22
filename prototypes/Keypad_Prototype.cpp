#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

const int KB_UP = 80;
const int KB_DOWN = 72;
const int KB_LEFT = 75;
const int KB_RIGHT = 77;
const int KB_ESCAPE = 27;

const bool SIGNAL_T=true;
const bool SIGNAL_F=false;

const int DEF_T=200;

inline void autoClear()
{
	int system (const char *clear);
		#ifdef linux
        	system("clear");
		#elif _WIN32
            system("CLS");
        #endif
}
inline void printGrid(bool grid[DEF_T][DEF_T])
{
	for(int i=0; i<DEF_T; i++)
	{
		for(int j=0; j<DEF_T; j++)
		{
			if(grid[i][j])
			{
				cout<<'*';
			}
			else
			{
				cout<<' ';
			}
		}
		cout<<endl;
	}	
}
inline bool controlGrid(int y, int x, bool grid[DEF_T][DEF_T])
{
	int a, b;
	
	for(int i=0; i<DEF_T; i++)
	{
		for(int j=0; j<DEF_T; j++)
		{
			if(grid[i][j])
			{
				a=i, b=j;
				grid[i][j]=false;
			}
		}
	}
	y=y+a;
	x=x+b;
	grid[y][x]=true;
	return grid;	
}
int main()
{
	int KB_code=0;
	
	bool grid[DEF_T][DEF_T];
	
	for(int i=0; i<DEF_T; i++)
	{
		for(int j=0; j<DEF_T; j++)
		{
			grid[i][j]=false;
		}
	}
	HWND myconsole = GetConsoleWindow();
	//alloc console space
    HDC mydc = GetDC(myconsole);
	//set colors
    COLORREF COLOR= RGB(0, 255, 255);
	COLORREF DELETE_COLOR= RGB(12, 12, 12);
	
	while(KB_code != KB_ESCAPE)
	{
		if (kbhit())
		{
			KB_code=getch();
			switch(KB_code)
			{
				case KB_RIGHT:
					for(int i=0; i<DEF_T; i++)
					{
						for(int j=0; j<DEF_T; j++)
						{//reset pixels -> background colors
							if(printGrid[i][j])
							{
								SetPixel(mydc, j, i, DELETE_COLOR);
							}
						}
					}
					controlGrid(0, 1, grid);
					for(int i=0; i<DEF_T; i++)
					{
						for(int j=0; j<DEF_T; j++)
						{//print grid on screen
							if(grid[i][j])
							{
								SetPixel(mydc, j, i, COLOR);
							}
						}
					}
					break;
				case KB_LEFT:
					for(int i=0; i<DEF_T; i++)
					{
						for(int j=0; j<DEF_T; j++)
						{//reset pixels -> background colors
							if(printGrid[i][j])
							{
								SetPixel(mydc, j, i, DELETE_COLOR);
							}
						}
					}
					controlGrid(0, -1, grid);
					for(int i=0; i<DEF_T; i++)
					{
						for(int j=0; j<DEF_T; j++)
						{//print grid on screen
							if(grid[i][j])
							{
								SetPixel(mydc, j, i, COLOR);
							}
						}
					}
					break;
				case KB_DOWN:
					for(int i=0; i<DEF_T; i++)
					{
						for(int j=0; j<DEF_T; j++)
						{//reset pixels -> background colors
							if(printGrid[i][j])
							{
								SetPixel(mydc, j, i, DELETE_COLOR);
							}
						}
					}
					controlGrid(-1, 0, grid);
					for(int i=0; i<DEF_T; i++)
					{
						for(int j=0; j<DEF_T; j++)
						{//print grid on screen
							if(grid[i][j])
							{
								SetPixel(mydc, j, i, COLOR);
							}
						}
					}
					break;
				case KB_UP:
					for(int i=0; i<DEF_T; i++)
					{
						for(int j=0; j<DEF_T; j++)
						{//reset pixels -> background colors
							if(printGrid[i][j])
							{
								SetPixel(mydc, j, i, DELETE_COLOR);
							}
						}
					}
					controlGrid(1, 0, grid);
					for(int i=0; i<DEF_T; i++)
					{
						for(int j=0; j<DEF_T; j++)
						{//print grid on screen
							if(grid[i][j])
							{
								SetPixel(mydc, j, i, COLOR);
							}
						}
					}
					break;
				default:
					break;
			}
		}
	}
}
