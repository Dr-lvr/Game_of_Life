#include<windows.h>
#include<iostream>

using namespace std;

int main() 
{
	int x=255;
	
	bool grid[1000][1000];
	
	for(int i = 0; i < 1000; i+=2)
    {
    	for(int j = 0; j < 1000; j+=2)
    	{
    		if(i%2==0 || j%3==0)
    		{
    			grid[i][j]=true;
			}
		}
    }
	
    //Get a console handle
    HWND myconsole = GetConsoleWindow();
    //Get a handle to device context
    HDC mydc = GetDC(myconsole);
    //Choose any color
    COLORREF COLOR= RGB(0, x, x);

    //Draw pixels
    for(int i = 0; i < 1000; i++)
    {
    	for(int j = 0; j < 1000; j++)
    	{
    		if(!grid[i][j])
    		{
    			SetPixel(mydc, i, j, COLOR);
			}
		}
    }
	cin.ignore();
    ReleaseDC(myconsole, mydc);
    cin.ignore();
    return 0;
}
