#include<bits/stdc++.h>
using namespace std;
inline long long find(long long x)
{
	long long a=x;
	long long sum=0;
	while(a)
		sum+=a%10,a/=10;
	return sum;
}
bool check(int x)
{
	if(find(x*x)==find(x)*find(x)) return 1;
	else return 0;
}
signed main()
{
	long long l,r,ans=0;cin>>l>>r;
	for(int a1=0;a1<=3;a1++)
		for(int a2=0;a2<=3;a2++)
			for(int a3=0;a3<=3;a3++)
				for(int a4=0;a4<=3;a4++)
					for(int a5=0;a5<=3;a5++)
						for(int a6=0;a6<=3;a6++)
							for(int a7=0;a7<=3;a7++)
								for(int a8=0;a8<=3;a8++)
									for(int a9=0;a9<=3;a9++)
										for(int a10=0;a10<=3;a10++)
										{
											long long num=a1+a2*1e1+a3*1e2+a4*1e3+a5*1e4+a6*1e5+a7*1e6+a8*1e7+a9*1e8+a10*1e9;
											if(num>=l&&num<=r)
												if(check(num)) ans++;
										}
	printf("%lld",ans);
	return 0;
}