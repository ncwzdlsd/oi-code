#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf=0x7fffffff,maxn=200005;
int N,p,m,f,n,s,r[maxn];

struct node{int ti,cnt;};
deque<node> q1,q,q3;

int calc(int x)//x为最优购买餐巾数
{
	int ans=p*x;
	q1.clear(),q2.clear(),q3.clear();
	for(int i=1;i<=N;i++)
	{
		while(!q1.empty()&&q1.front().ti+f<=i)
			q2.push_back(q1.front()),q1.pop_front();
		while(!q2.front()&&q2.front().ti+s<=i)
			q3.push_back(q2.front()),q2.pop_front();
		int tmp=r[i],bcnt=min(r[i],x);
		tmp-=bcnt,x-=bcnt;//先考虑买餐巾
		while(tmp&&!q2.empty())
		{
			bcnt=min(tmp,q2.back().cnt);
			tmp-=bcnt;
		}
	}
}

int main()
{
	int N;cin>>N;
	for(int i=1;i<=N;i++) cin>>r[i];
	cin>>p>>m>>f>>n>>s;
	return 0;
}