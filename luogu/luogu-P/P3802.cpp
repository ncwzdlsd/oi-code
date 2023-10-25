#include <bits/stdc++.h>
using namespace std;

double a[10],ans=1,s;

signed main()
{
	for(int i=1;i<=7;i++) cin>>a[i],s+=a[i];
	for(int i=1;i<=6;i++) ans=ans*a[i]/(s+1-i)*double(i);
	ans=ans*a[7]*7.0;
    printf("%.3lf\n",ans);
	return 0;
}