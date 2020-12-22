/*
	CaseStudy - Game of Life
	
	Autore: Davide Riva
*/
#include <iostream>
#include "Sample.h"

using namespace std;
static const int DATA_CONST = 300;

inline bool insert(int sel, int y, int x, string s1, bool cell[DATA_CONST][DATA_CONST])
{//
	int z=0;
	int a, b;
	switch(sel)
	{
		case 0:
			//parse glider
			s1=glider();
			//sety coordinatez
			a=3;
			b=3;
			break;
		case 1:
			//parse lwss
			s1=lwss();
			a=4;
			b=5;
			break;
		case 2:
			//parse clover leaf
			s1=cloverleaf();
			a=11;
			b=9;
			break;
		case 3:
			//parse Gosper's cannon
			s1=gosperCannon();
			a=9;
			b=36;
			break;
		case 4:
		default:
			//parse space rake
			s1=spaceRake();
			a=19;
			b=22;
			break;
	}
	for(int i=y; i<y+a; i++)
	{
		for(int j=x; j<x+b; j++)
		{//parse sample by the string
			if(s1.at(z)=='1')
			{
				cell[i][j]=true;
			}
			else
			{
				cell[i][j]=false;
			}
				z++;
		}
	}
	return cell;
}
