#include <iostream>
using namespace std;

int main()
{
	int m,n,a,b;
	cout<<"������ϴ������������С��"<<endl; 
	for(;;)
	{
		cin>>m>>n;
		b=m*n;
		if(m<n)
			cout<<"����"<<endl;
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
			cout<<"���Լ��Ϊ"<<n<<endl;
			cout<<"��С������Ϊ"<<(b/a)<<endl;
		}
	}
	return 0;
}
