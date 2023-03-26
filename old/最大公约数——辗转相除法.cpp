#include <iostream>
using namespace std;

int main()
{
	int m,n,a,b;
	cout<<"先输入较大数，后输入较小数"<<endl; 
	for(;;)
	{
		cin>>m>>n;
		b=m*n;
		if(m<n)
			cout<<"错误"<<endl;
		else
		{
//			while (m%n!=0)
//			{
//				a=m%n; 
//				m=n;
//				n=a;
//			}
			do
			{
				a=m%n;
				m=n;
				n=a;
			}while(m%n!=0);
			cout<<"最大公约数为"<<n<<endl;
			cout<<"最小公倍数为"<<(b/a)<<endl;
		}
	}
	return 0;
}
