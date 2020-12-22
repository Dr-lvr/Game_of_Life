/*
	CaseStudy - Game of Life 
	
	Autore: Davide Riva
*/
#include <iostream>
#include <windows.h>

#include "platform/Platform.h"

//subdirectory for functions
#include "headers/Headers.h"

using namespace std;
//costanti della griglia
static const int DATA= 300;
static const int DEF=0;

int main(){
	//calcolo del framerate
	clock_t start,end;
	double tempo;
	
	bool grid[DATA][DATA];
	bool printGrid[DATA][DATA];
	int sel=0;
	int x, y;
	int counter=0;
	string s1;
	
	//init grid && printGrid
	grid[DATA][DATA]=initGrid(grid);
	printGrid[DATA][DATA]=initGrid(printGrid);
	
	//print index menu on screen
	guideMenu();
	//choose mod
	cout<<" -0- Random Gen || -1- Put sample "<<endl;
	sel=get();
	autoClear();
	
	switch(sel){// mod prototype 
		case 0:
			//randomGen
			grid[DATA][DATA]=randomGen(grid);
			break;
		default:
			//put sample mod
			//print menu of available sample
			sampleMenu();
			sel=get();
			autoClear();
			//simple editor prototype
			cout<<"Insert coordinates(y, x)"<<endl;
			y=get();
			x=get();
			/////////////////////////////////////////
			if(x>=DATA || y>=DATA){
				x=1;
				y=1;
			}
			autoClear();
			/////////////////////////////////////////
			//update grid
			grid[DEF][DEF]=insert(sel, y, x, s1, grid);
			break;	
	}
	//choose mod: stepBystep gen || Autogen 
	cout<<"-0- Step || -1- Auto "<<endl;
	sel=get();
	autoClear();
	
	//handle console
    HWND myconsole = GetConsoleWindow();
	//alloc console space
    HDC mydc = GetDC(myconsole);
	//set colors
    COLORREF COLOR= RGB(0, 255, 255);
	COLORREF DELETE_COLOR= RGB(12, 12, 12);
	
	start=clock();
	for(;;){//core engine prototype(for(;;))	
		for(int i=1; i<DATA-1; i++){
			for(int j=1; j<DATA-1; j++){//gen printgrid
				printGrid[i][j]=cellControl(i, j, grid);
				if(printGrid[i][j]){//print pixel
					SetPixel(mydc, j, i, COLOR);
				}
			}
		}
		grid[DATA][DATA]=passGrid(grid, printGrid);
		if(sel==0){//step by step mode
			clear();
		} else {//clear in auto mode stack prototype
			for(int i=1; i<DATA-1; i++){
				for(int j=1; j<DATA-1; j++){
					if(printGrid[i][j]){//print pixel
						SetPixel(mydc, j, i, DELETE_COLOR);
					}
				}
			}
		}
		counter++;
		if(counter==2000){
			end=clock();
			break;
		}
	}
    ReleaseDC(myconsole, mydc);
	tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout<<(counter/(int)tempo)<<"fps in "<<tempo;
}
