#include <bits/stdc++.h>
using namespace std;

int a[1005][1005];

int main()
{
	int M;cin>>M;
	int N=pow(2,M);
	a[1][1]=1;
	for(int k=2;k<=N;k*=2)
	{
		int mid=k/2;
        for(int i=1;i<=mid;i++)
            for(int j=1;j<=mid;j++)
                a[i+mid][j+mid]=a[i][j],//填充右下部
                a[i][j+mid]=a[i+mid][j]=a[i][j]+mid;//填充右上部与左下部 
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++) cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}