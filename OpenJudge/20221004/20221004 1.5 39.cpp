#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int sum=0,result;
	for(int i=1;i<=n;i++)
	{
		if(i%7!=0&&i%10!=7&&i/10%10!=7)
		{
			result=i*i;
			sum+=result;
		}
	}
	cout<<sum<<endl;
}
