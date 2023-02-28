#include <iostream>
using namespace std; 

int main()
{
double x;

for(;;)
	{
		cin>>x;
		if(x>100||x<0)
			cout<<"´íÎó"<<endl;
		else if(x>90)
			cout<<"A"<<endl;
		else if(x>80)
			cout<<"B"<<endl;
		else if(x>70)
			cout<<"C"<<endl;
		else if(x>60)
			cout<<"D"<<endl;
		else 
			cout<<"E"<<endl;	
	} 
}
