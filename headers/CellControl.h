/*
	CaseStudy - Game of Life
	
	Autore: Davide Riva
*/
static const int AROUND = 300;

const bool LIVING=true;
const bool DEAD=false;

inline bool cellControl(int y, int x, bool cell[AROUND][AROUND])
{	
	int edix=0;
	for(int i=y-1; i<=y+1; i++)
	{//control the cell neighborhood
		for(int j=x-1; j<=x+1; j++)
		{
			if(cell[i][j])
			{//increment neighborhood index
				edix++;	
			}	
		}
	}
	if(cell[y][x])
	{//if (cell) sub the cell
		edix-=1;
		
		if(edix<2 || edix>3)
			return DEAD;
		else
			return LIVING;
	}
	else
	{
		if(edix==3)
			return LIVING;
	}
	return 0;
}
