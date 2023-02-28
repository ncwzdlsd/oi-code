#include <bits/stdc++.h>
using namespace std;

int n;
int pell[1000001];

int main()
{
	scanf("%d",&n);
	pell[1]=1;
	pell[2]=2;
	for(int i=3;i<=1000000;i++)
	{
		pell[i]=(2*pell[i-1]+pell[i-2])%32767;
	}
	int k;
	while(n--) //¼´n--!=0
	{
		scanf("%d",&k);
		printf("%d\n",pell[k]);
	}
	return 0;
}
