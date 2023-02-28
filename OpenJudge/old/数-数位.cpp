#include <iostream>
using namespace std;

int main()
{	
	int a,b,c,d,n;
	cout<<"最大只能输入四位正整数"<<endl;
	for(;;)
	{
		cin>>n;
		if(n<0)
			cout<<"错误"<<endl;
			else if(n<10)
				cout<<n<<endl;
				else if(n<100)
					cout<<((n-n%10)/10)<<' '<<n%10<<endl;
					else if(n<1000)
						{
							b=(n-n%100)/100;
							c=(n%100-n%10)/10;
							d=n%10;
							cout<<(b)<<' '<<(c)<<' '<<(d)<<endl;
						}
					else if(n<10000)
						{
							a=(n-n%1000)/1000;
							b=(n-1000*a-10*c-d)/100;
							c=(n%100-n%10)/10;
							d=n%10;
							cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<endl;
						}
							else
								cout<<"错误"<<endl;
	}
	return 0;
} 
