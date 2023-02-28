#include <bits/stdc++.h>
using namespace std;

int A[105];

int main()
{
	int N;cin>>N;
	double res=100;
	for(int i=1;i<=N;i++) cin>>A[i];
	for(int i=1;i<N;i++)
		if(A[i]>A[i+1]) res=res*a[i]/a[i+1];
	cout<<res;
	return 0;
}