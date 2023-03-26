#include <bits/stdc++.h>
using namespace std;

bool isHuiwen(int x)
{
	bool flag=false;
	
	int p=0,q=x;
	while(q/10>0)
	{
		p=p*10+q%10;
		q=(q-q%10)/10;
	}
	
	p=p*10+q; 
	
	if(p==x)
	{
		flag=true;
	}	
	
	return flag;
}

int main()
{
	int i,j,count;
	int m,n;
	for(;;)
	{
		cin>>m>>n;
		if(m<2&&m<n)
		{
			cout<<"错误：请输入大于等于2的整数区间"<<endl; 
		}
		else
		{
			for(i=m;i<=n;i=i+1)
			{
				for(j=2;i%j!=0&&j<=i;j=j+1)
				{
				}
				if(j==i)
				{
					if(isHuiwen(j)==true)
					{
						cout<<j<<" ";
					}					
				}
			}
			cout<<endl;
		}
	}
}
