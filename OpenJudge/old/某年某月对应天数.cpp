#include <iostream>
using namespace std; 

int main()
{
	int y,m;
	for(;;)
	{
		cin>>y>>m;
		switch(m)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:cout<<"����Ϊ"<<31<<endl;
		continue;
		case 2:if((y%4==0&&y%100!=0)||(y%400==0))
					cout<<"����Ϊ"<<29<<endl;
				else
					cout<<"����Ϊ"<<28<<endl;
		continue; 
		case 4:
		case 6:
		case 9:
		case 11:cout<<"����Ϊ"<<30<<endl;
		continue; 
		}
	}
}
