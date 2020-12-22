/*
	CaseStudy - Game of Life
	
	Autore: Davide Riva
*/
#include <iostream>
#include <cstdlib>

using namespace std;

inline int get()
{
	int sel;
	
	std::cin>>sel;
	return sel;
}
inline void clear()
{
	int system (const char *clear);
	std::cin.ignore();
		#ifdef linux
        	system("clear");
		#elif _WIN32
            system("CLS");
        #endif
}
inline void autoClear()
{
	int system (const char *clear);
		#ifdef linux
        	system("clear");
		#elif _WIN32
            system("CLS");
        #endif
}
inline void sampleMenu()
{
	cout<<"-0- Glider "<<endl
		<<"-1- LWSS "<<endl
		<<"-2- CloverLeaf"<<endl
		<<"-3- Gosper's Cannon"<<endl
		<<"-4- Space Rake"<<endl;
}
inline void guideMenu()
{
	cout<<"* GEN MOD:											  	"<<endl
		<<"* -> Random gen: genera una configuarazione random		"<<endl
		<<"* 											 	 	"<<endl
		<<"* -> Put sample: inserisci un modello			  	 	"<<endl
		<<"* 											  	 	"<<endl
		<<"* STEP MOD:											  		"<<endl
		<<"* -> STEP: mod step by step, 1 step = 1 generazione		"<<endl
		<<"* 											  		"<<endl
		<<"* -> AUTO: scansione automatica delle generazioni		"<<endl
		<<"* 											 		"<<endl
		<<"* Press Enter to skip "<<endl;
	clear();
}
