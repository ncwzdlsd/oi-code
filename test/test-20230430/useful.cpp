---
title: OIģ��ϼ�
date: 2023-02-04 10:16:14
tags: ģ��
categories: OI
url: OI-template
---

��ʵ����ǰ�����\*���ϵ�ģ������������ QwQ

## ͼ��

### Tarjan

#### ����

[P3387 ��ģ�塿����](https://www.luogu.com.cn/problem/P3387)

```cpp
// ����˼���ǽ�һ��ǿ��ͨ��������ת����һ���������ڲ����е�Ȩ�͵ĺ͵ĵ㣬ʵ�ֹ��̿����� Tarjan �� scc Ȼ������
// ������Ҫ�ҵ�Ȩ����·��������Ҫ�õ���������

#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int cnt,n,m,tot,vis[maxn],from[maxn],low[maxn],topoxu[maxn],a[maxn],nxt[maxn],head[maxn],to[maxn],dfscnt,dfn[maxn],top,s[maxn],suodian[maxn],ru[maxn],dis[maxn];

void add(int x,int y)
{
	to[++cnt]=y;
	from[cnt]=x;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void tarjan(int x)
{
	low[x]=dfn[x]=++dfscnt;
	s[++top]=x;vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v])
			low[x]=min(low[x],low[v]);
	}
	if(dfn[x]==low[x])
	{
		int y;
		while(y=s[top--])
		{
			suodian[y]=x;
			vis[y]=0;
			if(x==y) break;
			a[x]+=a[y];
		}
	}
}

int topo()
{
	queue<int> q;
	tot=0;
	for(int i=1;i<=n;i++)
		if(suodian[i]==i&&!ru[i])
		{
			q.push(i);
			dis[i]=a[i];
		}
	while(!q.empty())
	{
		int rr=q.front();q.pop();
		for(int i=topoxu[rr];i;i=nxt[i])
		{
			int v=to[i];
			dis[v]=max(dis[v],dis[rr]+a[v]);
			ru[v]--;
			if(ru[v]==0) q.push(v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dis[i]);
	return ans;
}

int main()
{
	int u,v;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>u>>v,add(u,v);
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		int x=suodian[from[i]],y=suodian[to[i]];
		if(x!=y)
		{
			nxt[++sum]=topoxu[x];
			to[sum]=y;
			from[sum]=x;
			topoxu[x]=sum;ru[y]++;
		}
	}
	cout<<topo();
	return 0;
}
```

```cpp
// ����Ũ����

void tarjan(int x)
{
	low[x]=dfn[x]=++dfscnt;//dfs��++
	s[++top]=x;/*����ģ��ջ������ DFS ����ջ���Ӷ���*/vis[x]=1;//��¼��ǰ�㱻����
	for(int i=head[x];i;i=nxt[i])//ö��i�ܵ���ĵ�
	{
		int v=to[i];
		if(!dfn[v])//���vû�� DFS ��û�б����ʹ�
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v])
			low[x]=min(low[x],low[v]);
	}
	if(dfn[x]==low[x])
	{
		int y;
		while(y=s[top--])//��һ����ʵ������y=s[top--]��Ȼ���ж��Ƿ����0
		{
			suodian[y]=x;
			vis[y]=0;
			if(x==y) break;
			a[x]+=a[y];
		}
	}
}
```

#### ���

[P3388 ��ģ�塿��㣨���](https://www.luogu.com.cn/problem/P3388)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int head[maxn],to[maxn],nxt[maxn],cnt,dfscnt,low[maxn],dfn[maxn];
bool cut[20005];

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;	
}

void dfs(int u,int fa)
{
	low[u]=dfn[u]=++dfscnt;
	int c=0;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);//����
			if(low[v]>=dfn[u]&&u!=fa) cut[u]=1;
			if(u==fa) c++;
		}
		else low[u]=min(low[u],dfn[v]);//����
	}
	if (c>=2&&u==fa) cut[u]=1;
}

int main()
{
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=m;i++) {int y,x;cin>>x>>y,add(x,y),add(y,x);}
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i,i);
	for(int i=1;i<=n;i++) if(cut[i]) ans++;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) if(cut[i]) cout<<i<<' ';
	return 0;
}
```

#### 2-SAT

[P4782 ��ģ�塿2-SAT ����](https://www.luogu.com.cn/problem/P4782)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e6+5;
int head[maxn],to[maxn],nxt[maxn],cnt;
int dfn[maxn],sta[maxn]/*ջ*/,low[maxn],dfncnt,vis[maxn],top/*��¼ջ��Ԫ�ر��*/,sccnum/*��¼ǿ��ͨ�������*/,scc[maxn]/*���Ϊi�ĵ����ڵ�ǿ��ͨ�������*/;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;	
}

void tarjan(int u)
{
	low[u]=dfn[u]=++dfncnt;
	sta[++top]=u;vis[u]=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v]) tarjan(v)/*����������*/,low[u]=min(low[u],low[v]);
		else if(vis[v]) low[u]=min(low[u],dfn[v]);	
	}
	if(dfn[u]==low[u])
	{
		++sccnum;
		while(sta[top]!=u)//������������Ķ�����
			scc[sta[top]]=sccnum,vis[sta[top]]=0,top--;//����ģ�ⵯջ
		//�������Լ�
		scc[sta[top]]=sccnum;
		vis[sta[top]]=0;
		top--;
	}
}

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int ii,a,jj,b;cin>>ii>>a>>jj>>b;
		//ʵ�ֽ������㣬����һ����k��k+n��true�㣬k��false��	
		add(ii+!a*n,jj+b*n);
		add(jj+!b*n,ii+a*n);
	}
	for(int i=1;i<=2*n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++)
		if(scc[i]==scc[i+n]) puts("IMPOSSIBLE"),exit(0);
	puts("POSSIBLE");
	for(int i=1;i<=n;i++)
	{
		if(scc[i]>scc[i+n]) cout<<1<<' ';
		else cout<<0<<' ';
	}
	return 0;
}
```

#### ��˫

[P8436 ��ģ�塿��˫��ͨ����](https://www.luogu.com.cn/problem/P8436)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=4e6+5;
int head[maxn],to[maxn],nxt[maxn],cnt=1,low[maxn],dfn[maxn],scc[maxn],dfscnt,scccnt;//cnt��1��ʼ������ŵ�ʱ��ɶԱ�� 
bool bridge[maxn],vis[maxn];
vector<int> ans[maxn];

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void tarjan(int u,int fa)
{
	low[u]=dfn[u]=++dfscnt;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]) bridge[i]=bridge[i^1]=1;
		}
		else if(i!=(fa^1)) low[u]=min(low[u],dfn[v]);
	}
}

void dfs(int x)
{
	scc[x]=scccnt;
	if(x) ans[scccnt].push_back(x);
	for(int i=head[x];i;i=nxt[i])
	{
		if(scc[to[i]]||bridge[i]) continue;
		dfs(to[i]); 
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;cin>>u>>v;
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i,0);
	for(int i=1;i<=n;i++)
		if(!scc[i]) ++scccnt,dfs(i);
	cout<<scccnt<<endl;
	for(int i=1;i<=scccnt;i++)
	{
		cout<<ans[i].size()<<' ';
		for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<' ';
		cout<<endl;
	}
	return 0;
} 
```

### ��С������

[P3366 ��ģ�塿��С������](https://www.luogu.com.cn/problem/P3366)

```cpp
// ���鼯ά���Ƿ���һ��ǿ��ͨ������

#include <bits/stdc++.h>
using namespace std;

int to[500000],v[500000],father[500000],nxt[500000],cnt,head[500000],uu,vv,ans,M,N;

int find(int x)
{
	if(father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

struct node
{
	int to,from,v;
}gg[500000];

bool cmp(node a,node b)
{
	return a.v<b.v;
}

int main()
{
	cin>>N>>M;
	int sum;
	for(int i=1;i<=N;i++) father[i]=i;
	for(int i=1;i<=M;i++) cin>>gg[i].from>>gg[i].to>>gg[i].v;
	sort(gg+1,gg+1+M,cmp);
	for(int i=1;i<=N;i++) father[i]=i;
	for(int i=1;i<=M&&cnt<N-1;i++)
	{
		int uu=find(gg[i].from),vv=find(gg[i].to);
		if(uu!=vv)
		{
			sum+=gg[i].v;
			father[uu]=vv;
			cnt++;
		}
	}
	if(cnt!=N-1)
		cout<<"orz";
	else
		cout<<sum;
	return 0;
}
```

### LCA

[P3379 ��ģ�塿����������ȣ�LCA��](https://www.luogu.com.cn/problem/P3379)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=5*1e6+5;
int f[maxn][25],dep[maxn],head[maxn],nxt[maxn],to[maxn],cnt,N;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}

void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs(to[i],x);
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int M,S,x,y;cin>>N>>M>>S;
	for(int i=1;i<N;i++) cin>>x>>y,add(x,y),add(y,x);
	dfs(S,0);int a,b;
    for(int j=1;j<=20;j++) for(int i=1;i<=N;i++) f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1;i<=M;i++) cin>>a>>b,cout<<lca(a,b)<<endl;
	return 0;
}
```

### ���·

#### Dijkstra

[P4779 ��ģ�塿��Դ���·������׼�棩](https://www.luogu.com.cn/problem/P4779)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+5;
int head[maxn],nxt[maxn],to[maxn],w[maxn],cnt,dis[maxn],vis[maxn];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

struct node
{
	int id,dis;
	friend bool operator < (node a,node b)
	{
		return a.dis>b.dis;//С���ѣ�
	}
};

priority_queue<node> q;

void dij(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;q.push(node{s,0});
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i])
			if(dis[to[i]]>dis[u]+w[i])
				dis[to[i]]=dis[u]+w[i],q.push(node{to[i],dis[to[i]]});
	}
}

int main()
{
	int n,m,s,u,v,w;cin>>n>>m>>s;
	for(int i=1;i<=m;i++) cin>>u>>v>>w,add(u,v,w);
	dij(s);
	for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
	return 0;
}
```

#### SPFA �и���

[P3385 ��ģ�塿����](https://www.luogu.com.cn/problem/P3385)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=40005;
int nxt[maxn],to[maxn],head[maxn],val[maxn],dis[maxn],vis[maxn],rec[maxn],cnt,n,m;
queue<int> q;

void add(int x,int y,int z)
{
	to[++cnt]=y;
	val[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

bool spfa()
{
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(rec,0,sizeof(rec));
    while(!q.empty) q.pop();
	q.push(1);
	dis[1]=0,vis[1]=1,rec[1]++;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=0;//�����ѳ���
		for(int i=head[u];i;i=nxt[i])
		{
			if(dis[to[i]]>dis[u]+val[i])
			{
				dis[to[i]]=dis[u]+val[i];
				//�����ж��Ƿ��и�����������rec��¼�����Ӵ����������Ӵ���>n����֤�������˸�������û�����·
				if(!vis[to[i]]) vis[to[i]]=true,rec[to[i]]++,q.push(to[i]);//�ܸ��£�ѹ�����
				if(rec[to[i]]>=n) return true;
			}
		}	
	}
	return false;
}

int main()
{
	int T,u,v,w;cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(head,0,sizeof(head));
		cnt=0;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			add(u,v,w);
			if(w>=0) add(v,u,w);
		}
		if(spfa()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
```

#### Johnson ȫԴ���·

[P5905 ��ģ�塿Johnson ȫԴ���·](https://www.luogu.com.cn/problem/P5905)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=9005,maxx=1e9;//ע��ԭ��m����+�½�0�ڵ�n���ߣ�����С�˻�ը
int nxt[maxn],head[maxn],cnt,to[maxn],w[maxn],h[maxn],vis[3005],tim[3005],m,n,u,v,ww,dis[3005];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

bool spfa()//SPFA�и���
{
	queue<int> q;
	memset(h,127/3,sizeof(h));
	h[0]=0,vis[0]=1;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(h[v]>h[u]+w[i]) 
			{
				h[v]=h[u]+w[i];
				if(!vis[v]) 
				{
					q.push(v),vis[v]=1,tim[v]++;
					if(tim[v]>n) return true;
				}
			}
		}
	}
	return false;
}

struct node
{
	int id,dis;
	bool friend operator < (node a,node b)
	{
		return a.dis>b.dis;
	}
};

void dij(int s)
{
	priority_queue<node> q;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[i]=maxx;
	dis[s]=0;q.push(node{s,0});
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i])
			if(dis[to[i]]>dis[u]+w[i])
				dis[to[i]]=dis[u]+w[i],q.push(node{to[i],dis[to[i]]});
	}
}

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>u>>v>>ww,add(u,v,ww);
	for(int i=1;i<=n;i++) add(0,i,0);
	if(spfa()) cout<<-1,exit(0);
	for(int u=1;u<=n;u++) for(int i=head[u];i;i=nxt[i]) w[i]+=h[u]-h[to[i]];
	for(int i=1;i<=n;i++)
	{
		dij(i);
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(dis[j]==maxx) ans+=j*maxx;
			else ans+=j*(dis[j]+h[j]-h[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
```

### ����ͼ���ƥ��

[P3386 ��ģ�塿����ͼ���ƥ��](https://www.luogu.com.cn/problem/P3386)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=5e4+5;
int head[maxn],nxt[maxn],to[maxn],vis[maxn],cnt,match[505]/*��ʾ�ұߵ��Ӧ��ߵ�cp*/,m,n,e;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

bool dfs(int now)//�Ҷ���
{
	for(int i=head[now];i;i=nxt[i])
	{
		if(vis[to[i]]) continue;
		vis[to[i]]=1;
		if(!match[to[i]]||dfs(match[to[i]]))//���ҵĶ���û�������ѻ������ҵĶ����б��ѡ��
		{
			match[to[i]]=now;//�Ҳ�Ԫ���ҵ����µ�ƥ��
			return 1;
		}
	}
	return 0;
}

void gett()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	cout<<ans;
}

int main()
{
	cin>>n>>m>>e;
	for(int i=1;i<=e;i++) 
	{
		int u,v;cin>>u>>v;
		add(u,v);
	}
	gett();
	return 0;
}
```

## ��ѧ

### ������

[P4549 ��ģ�塿������](https://www.luogu.com.cn/problem/P4549)

```cpp
#include <bits/stdc++.h>
using namespace std;

int n,a,ans;

int gcd(int x,int y) 
{
    return !y?x:gcd(y,x%y);
}

int main() 
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a,a=a>0?a:-a,ans=gcd(ans,a);
    cout<<ans;
    return 0;
}
```

### �˷���Ԫ

[P3811 ��ģ�塿�˷���Ԫ](https://www.luogu.com.cn/problem/P3811)

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,p,a[5000005];

signed main()
{
	cin>>n>>p;
	a[1]=1;
	printf("1\n");
	for(int i=2;i<=n;i++)
		a[i]=(p-p/i)*a[p%i]%p,cout<<a[i]<<endl;
	return 0;
}
```



### ��չŷ������㷨

[P5656 ��ģ�塿��Ԫһ�β������� (exgcd)](https://www.luogu.com.cn/problem/P5656)

�����ṩ��д����$g$��ʾ����$\gcd(a,b)$��

```cpp
//д���� ToT
```

### ����ɸ

[P3383 ��ģ�塿����ɸ����](https://www.luogu.com.cn/problem/P3383)

������õ����ҹ��õ�д����

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e8+5;
int v[maxn],prime[maxn];

void primes(int n)
{
    memset(v,0,sizeof(v));//�洢��С������
    int m=0;//��������
    for(int i=2;i<=n;i++)
    {
        if(v[i]==0)
        {
            v[i]=i;
            prime[++m]=i;
        }
        for(int j=1;j<=m;j++)
        {
            //i�б�prime[j]��С�������ӻ��߳���n�ķ�Χ
            if(prime[j]>v[i]||prime[j]*i>n) break;
            v[i*prime[j]]=prime[j];
        }
    }
}

int main()
{
	int n,q;cin>>n>>q;
	primes(n);
	for(int i=1;i<=q;i++)
	{
		int k;cin>>k;
		cout<<prime[k]<<endl;
	}
	return 0;
}
```

### ������

[P1226 ��ģ�塿������||ȡ������](https://www.luogu.com.cn/problem/P1226)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

int quickpow(int a,int b,int n)
{
    if(b==1) return a;
    if(b%2==0)
    {
        int t=quickpow(a,b/2,n);
        return t*t%n;
    }
    else
    {
        int t=quickpow(a,b/2,n);
        t=t*t%n;
        t=t*a%n;
        return t;
    }
}

signed main()
{
    int a,b,p;
    cin>>a>>b>>p;
    printf("%lld^%lld mod %lld=%lld",a,b,p,quickpow(a,b,p));
}
```

## �������ݽṹ

### ����ջ

[P5788 ��ģ�塿����ջ](https://www.luogu.com.cn/problem/P5788)

```cpp
#include <bits/stdc++.h>
using namespace std;

int a[3000005],f[3000005];
stack<int> s;

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		while(!s.empty()&&a[s.top()]<=a[i]) s.pop();
		f[i]=s.empty()?0:s.top();
		s.push(i);
	}
	for(int i=1;i<=n;i++) cout<<f[i]<<' ';
	return 0;
}
```

### ��������

[P1886 �������� /��ģ�塿��������](https://www.luogu.com.cn/problem/P1886)

```cpp
#include<bits/stdc++.h>
using namespace std;

int n,m;
int q1[1000001],q2[1000001];
int a[1000001];

int min_deque()
{
    int h=1,t=0;
    for(int i=1;i<=n;i++)
    {
        while(h<=t&&q1[h]+m<=i) 
            h++;
        while(h<=t&&a[i]<a[q1[t]]) 
            t--;
        q1[++t]=i;
        if(i>=m) 
            printf("%d ",a[q1[h]]);
    }
    cout<<endl;
}

int max_deque()
{
    int h=1,t=0;
    for(int i=1;i<=n;i++)
    {
        while(h<=t&&q2[h]+m<=i) 
            h++;
        while(h<=t&&a[i]>a[q2[t]]) 
            t--;
        q2[++t]=i;
        if(i>=m) 
            printf("%d ",a[q2[h]]);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]);
    min_deque();
    max_deque();
    return 0;
}
```

## �������ݽṹ

### ST ��

[P3865 ��ģ�塿ST ��](https://www.luogu.com.cn/problem/P3865)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5,loggn=20;
int logg[maxn],f[maxn][loggn+5];
int n,m,x,y;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        f[i][0]=read();
    }
    logg[0]=-1;
    for(int i=1;i<=n;++i)
        logg[i]=logg[i/2]+1;
    for(int j=1;j<=loggn;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
    		//ע��Ӽ��˳�����������ȼ�����λ�������
    while(m--)
    {
        x=read(),y=read();
        int s=logg[y-x+1];
        printf("%d\n",max(f[x][s],f[y-(1<<s)+1][s]));
    }
    return 0;
}
```

## �������ݽṹ

### ���鼯

[P3367 ��ģ�塿���鼯](https://www.luogu.com.cn/problem/P3367)

```cpp
#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,ans,f[10005],z,x,y;

int find(int k)
{
    if(f[k]==k) return k;
    return f[k]=find(f[k]);
}

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        f[i]=i;
    for(i=1;i<=m;i++)
    {
        cin>>z>>x>>y;
        if(z==1)
            f[find(x)]=find(y);
        else if(find(x)==find(y))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
```

### ��״����

[P3374 ��ģ�塿��״���� 1](https://www.luogu.com.cn/problem/P3374)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=5*1e5+5;
int c[maxn],a[maxn],n;

int lowbit(int x)
{
	return x&(-x);
}

int ask(int x)//��ѯx��ǰ׺��
{
	int res=0;
	while(x) res+=c[x],x-=lowbit(x);
	return res;
}

void add(int x,int v)//�ѵ�x����v
{
	while(x<=n) c[x]+=v,x+=lowbit(x);
}

int main()
{
	int qwq,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>qwq,add(i,qwq);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y,k;
		cin>>opt;
		if(opt==1)
			cin>>x>>k,add(x,k);
		else
			cin>>x>>y,cout<<(ask(y)-ask(x-1))<<endl;
			//����xҪ-1�����Կ���һ�������Ҫ��[1,2]������ͣ�Ӧ����1��2������ͼ�ȥask(0)��0
	}
	return 0;
}
```

[P3368 ��ģ�塿��״���� 2](https://www.luogu.com.cn/problem/P3368)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=5*1e5+5;
int c[maxn],N;

int lowbit(int x)
{
	return x&(-x);
}

int ask(int x)//��ѯx��ǰ׺��
{
	int res=0;
	while(x) res+=c[x],x-=lowbit(x);
	return res;
}

void add(int x,int v)//�ѵ�x����v
{
	while(x<=N) c[x]+=v,x+=lowbit(x);
}

int main()
{
	int M,now,last;cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>now,add(i,now-last),last=now;
	for(int i=1;i<=M;i++)
	{
		int opt,x,y,k;cin>>opt;
		if(opt==1) cin>>x>>y>>k,add(x,k),add(y+1,-k);//���
		else cin>>x,cout<<ask(x)<<endl;
	}
	return 0;
}
```

### �߶���

[P3372 ��ģ�塿�߶��� 1](https://www.luogu.com.cn/problem/P3372)

[P3373 ��ģ�塿�߶��� 2](https://www.luogu.com.cn/problem/P3373)

### �ɳ־û�

#### �ɳ־û��߶���

[P3919 ��ģ�塿�ɳ־û��߶��� 1���ɳ־û����飩](https://www.luogu.com.cn/problem/P3919)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=4e7+5;
int N,M,a[maxn],cnt,rr[maxn]/*�洢�汾i�ĸ��ڵ��Ŵ�0��ʼ*/;

struct node
{
	int ls,rs,v;
}t[maxn];

int build(int l,int r)
{
	int id=++cnt;
	if(l==r) t[id].v=a[l];
	else
	{
		int mid=(l+r)/2;
		t[id].ls=build(l,mid);
		t[id].rs=build(mid+1,r);
	}
	return id;
}//��¼���Ҷ��ӱ�� 

int neww(int x)
{
	cnt++,t[cnt]=t[x];
	return cnt;
}//�½��ڵ� 

int update(int now,int l,int r,int k,int v) 
{
	now=neww(now);
	if(l==r) t[now].v=v;
	else
	{
		int mid=(l+r)/2;
		if(k<=mid) t[now].ls=update(t[now].ls,l,mid,k,v);
		else t[now].rs=update(t[now].rs,mid+1,r,k,v);
	}
	return now;
}

int query(int now,int k,int l,int r)
{
	if(l==r) return t[now].v;
	else
	{
		int mid=(l+r)/2;
		if(k<=mid) return query(t[now].ls,k,l,mid);
		else return query(t[now].rs,k,mid+1,r);
	}
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>a[i];
	rr[0]=build(1,N);
	for(int i=1;i<=M;i++)
	{
		int opt,v,loc,value;
		cin>>v>>opt>>loc;
		if(opt==1) cin>>value,rr[i]=update(rr[v],1,N,loc,value);
		else cout<<query(rr[v],loc,1,N)<<endl,rr[i]=rr[v];
	}
	return 0;
}
```

[P3834 ��ģ�塿�ɳ־û��߶��� 2](https://www.luogu.com.cn/problem/P3834)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=6e6+5;
int n,m,rr[maxn],s[maxn],cnt,a[maxn],b[maxn];

struct node
{
	int ls,rs;
}t[maxn];

int build(int l,int r)
{
	int id=++cnt;
	s[id]=0;
	if(l==r) return id;
	int mid=(l+r)/2;
	t[id].ls=build(l,mid);
	t[id].rs=build(mid+1,r);
	return id;
}//��¼���Ҷ��ӱ�� 

int update(int now,int l,int r,int k) 
{
	int rt=++cnt;
	t[rt].ls=t[now].ls,t[rt].rs=t[now].rs;
	s[rt]=s[now]+1;
	if(l<r)
	{
		int mid=(l+r)/2;
		if(k<=mid) t[rt].ls=update(t[now].ls,l,mid,k);
		else t[rt].rs=update(t[now].rs,mid+1,r,k);
	}
	return rt;
}

int query(int u,int v,int k,int l,int r)
{
	if(l>=r) return l;
	else
	{
		int mid=(l+r)/2,x=s[t[v].ls]-s[t[u].ls];
		if(x>=k) return query(t[u].ls,t[v].ls,k,l,mid);
		else return query(t[u].rs,t[v].rs,k-x,mid+1,r);
	}
}

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	int mm=unique(b+1,b+n+1)-b-1;
	rr[0]=build(1,mm);
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+mm+1,a[i])-b,rr[i]=update(rr[i-1],1,mm,a[i]);
	for(int i=1;i<=m;i++)
	{
		int l,r,k;cin>>l>>r>>k;
		int ans=query(rr[l-1],rr[r],k,1,mm);
		cout<<b[ans]<<endl;
	} 
	return 0;
}
```

### �ֵ���

[P8306 ��ģ�塿�ֵ���](https://www.luogu.com.cn/problem/P8306)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=2e6+5;
int t[maxn][65],cnt[maxn],tot;
char s[maxn];

int getn(char x)
{
    if(x<='Z'&&x>='A') return x-'A';
    else if(x<='z'&&x>='a') return x-'a'+26;
    else return x-'0'+52;
}

void insert(char s[])
{
    int p=0,len=strlen(s);//���ڵ�Ϊ0
    for(int i=0;i<len;i++)
    {
        int u=getn(s[i]);//��ǰ��ĸ�ӽڵ�
        if(!t[p][u]) t[p][u]=++tot;//�����ǰ�ӽڵ㲻���ھʹ���һ�������洢�ӽڵ�
        p=t[p][u];//��p�ߵ��ӽڵ��λ��
        cnt[p]++;//��β��p���ַ�����������
    }
}

int ask(char s[])
{
    int p=0,len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int u=getn(s[i]);
        if(!t[p][u]) return 0;
        p=t[p][u];
    }
    return cnt[p];
}

int main()
{
    int T;cin>>T;
    while(T--)
    {
        for(int i=0;i<tot;i++)
            for(int j=0;j<65;j++) t[i][j]=0;
        for(int i=0;i<tot;i++) cnt[i]=0;
        tot=0;
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>s,insert(s);
        for(int i=1;i<=q;i++)
            cin>>s,cout<<ask(s)<<endl;
    }
    return 0;
}
```

### ��άƫ��

[P3810 ��ģ�塿��άƫ��İ�ϻ�����](https://www.luogu.com.cn/problem/P3810)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+5;
int c[maxn],qwq[maxn],n,k;

int lowbit(int x){return x&(-x);}

struct node
{
    int a,b,c,cnt,ans;
}p1[maxn],p2[maxn];

//---OK---
bool cmp1(node aa,node bb)
{
    if(aa.a!=bb.a) return aa.a<bb.a;
    else if(aa.b!=bb.b) return aa.b<bb.b;
    return aa.c<bb.c;
}

bool cmp2(node aa,node bb)
{
    if(aa.b!=bb.b) return aa.b<bb.b;
    return aa.c<bb.c;
}
//---------

void add(int x,int v)
{
    while(x<=k) c[x]+=v,x+=lowbit(x);
    return;
}

int ask(int x)
{
    int res=0;
    while(x) res+=c[x],x-=lowbit(x);
    return res;
}

void cdq(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    cdq(l,mid);cdq(mid+1,r);
    sort(p2+l,p2+mid+1,cmp2);sort(p2+mid+1,p2+r+1,cmp2);
    int j=l;
    for(int i=mid+1;i<=r;i++)
    {
        while(p2[i].b>=p2[j].b&&j<=mid) add(p2[j].c,p2[j].cnt),j++;
        p2[i].ans+=ask(p2[i].c);
    }
    for(int i=l;i<j;i++) add(p2[i].c,-p2[i].cnt);
}

signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>p1[i].a>>p1[i].b>>p1[i].c;
    sort(p1+1,p1+n+1,cmp1);
    int cntt=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        cntt++;
        if(p1[i].a!=p1[i+1].a||p1[i].b!=p1[i+1].b||p1[i].c!=p1[i+1].c) 
            sum++,p2[sum].a=p1[i].a,p2[sum].b=p1[i].b,p2[sum].c=p1[i].c,p2[sum].cnt=cntt,cntt=0;
    }
    cdq(1,sum);
    // for(int i=1;i<=sum;i++) cout<<p2[i].ans<<p2[i].a<<p2[i].b<<p2[i].c<<endl;
    for(int i=1;i<=sum;i++) qwq[p2[i].ans+p2[i].cnt-1]+=p2[i].cnt;
    for(int i=0;i<n;i++) cout<<qwq[i]<<endl;
    return 0;
}
```

## �ַ���

### Hash

�ַ�����ϣ���������̺ܼ򵥣�������ѡ���������ʵĳ���$b$��base����$h$����$b$�������������ַ�������$b$��������

[P3370 ��ģ�塿�ַ�����ϣ](https://www.luogu.com.cn/problem/P3370)

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int mmax=1505,maxn=10005;
ull base=131,prime=23317,mod=212370440130137957;
int N,a[maxn],ans=1;
char s[mmax];
ull hash[maxn],power[maxn];//��Ȼ���

ull hashh(char s[])//�ȹ����ϣ�������������
{
	int len=strlen(s);
	ull ans=0;
	for(int i=0;i<len;i++)
		ans=(ans*base+(ull)s[i])%mod+prime;
	return ans;
}

int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
		scanf("%s",s),a[i]=hashh(s);
    //һ��С���ɣ�ͳ��һ�����в�ͬ���ĸ���������������Ȼ��ͳ��ǰһ�����ͺ�һ�����Ƿ���ȣ��������ans++
	sort(a+1,a+N+1);
	for(int i=1;i<N;i++)
		if(a[i]!=a[i+1]) ans++;
	cout<<ans;
	return 0;
}
```

### �ֵ���

[P8306 ��ģ�塿�ֵ���](https://www.luogu.com.cn/problem/P8306)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=2e6+5;
int t[maxn][65],cnt[maxn],tot;
char s[maxn];

int getn(char x)
{
    if(x<='Z'&&x>='A') return x-'A';
    else if(x<='z'&&x>='a') return x-'a'+26;
    else return x-'0'+52;
}

void insert(char s[])
{
    int p=0,len=strlen(s);//���ڵ�Ϊ0
    for(int i=0;i<len;i++)
    {
        int u=getn(s[i]);//��ǰ��ĸ�ӽڵ�
        if(!t[p][u]) t[p][u]=++tot;//�����ǰ�ӽڵ㲻���ھʹ���һ�������洢�ӽڵ�
        p=t[p][u];//��p�ߵ��ӽڵ��λ��
        cnt[p]++;//��β��p���ַ�����������
    }
}

int ask(char s[])
{
    int p=0,len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int u=getn(s[i]);
        if(!t[p][u]) return 0;
        p=t[p][u];
    }
    return cnt[p];
}

int main()
{
    int T;cin>>T;
    while(T--)
    {
        for(int i=0;i<tot;i++)
            for(int j=0;j<65;j++) t[i][j]=0;
        for(int i=0;i<tot;i++) cnt[i]=0;
        tot=0;
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>s,insert(s);
        while(q--)
            cin>>s,cout<<ask(s)<<endl;
    }
    return 0;
}
```

### KMP

[P3375 ��ģ�塿KMP�ַ���ƥ��](https://www.luogu.com.cn/problem/P3375)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
char a[maxn],b[maxn];
int nxt[maxn],n,m;

int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1);
	for(int i=1,j=0;i<=m;i++)
	{
		while(j&&b[i+1]!=b[j+1]) j=nxt[j];
		if(b[i+1]==b[j+1]) j++;
		nxt[i+1]=j;
	}
	for(int i=0,j=0;i<=n;i++)
	{
		while(j&&a[i+1]!=b[j+1]) j=nxt[j];
		if(a[i+1]==b[j+1]) j++;//�����ǰλ��ƥ��
		if(j==m) cout<<(i+2-m)<<endl;
	}
	for(int i=1;i<=m;i++) cout<<nxt[i]<<" ";
	return 0;
}
```

### Z ����

[P5410 ��ģ�塿��չ KMP��Z ������](https://www.luogu.com.cn/problem/P5410)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e7+5;
char a[maxn],b[maxn];
long long za[maxn],zb[maxn];

int main()
{
	scanf("%s%s",a,b);
	int la=strlen(a),lb=strlen(b);
	zb[0]=lb;
	for(int i=1,l=0,r=0;i<lb;++i)
	{
		if(i<=r&&zb[i-l]<r-i+1) zb[i]=zb[i-l];//��Ϊ��ȷ����һλ�Ƿ���ȣ�����ֱ�Ӽ̳�z[i-l]
		else
		{
			zb[i]=max(0,r-i+1);//0˵��i>r��r-i+1˵������ƥ������
			while(i+zb[i]<lb&&b[zb[i]]==b[i+zb[i]]) ++zb[i];
		}
		if(i+zb[i]-1>r) l=i,r=i+zb[i]-1;
	}
	for(int i=0;i<la;++i)//��a����ģ�崮b��z[0]
	{
		if(b[i]==a[i]) ++za[0];
		else break;
	}
	for(int i=1,l=0,r=0;i<la;++i)
	{
		if(i<=r&&zb[i-l]<r-i+1) za[i]=zb[i-l];
		else
		{
			za[i]=max(0,r-i+1);
			while(i+za[i]<la&&b[za[i]]==a[i+za[i]]) ++za[i];
		}
		if(i+za[i]-1>r) l=i,r=i+za[i]-1;
	}
	long long ans=0,bp=0;
	for(int i=0;i<la;i++) ans^=(i+1)*(za[i]+1);
	for(int i=0;i<lb;i++) bp^=(i+1)*(zb[i]+1);
	cout<<bp<<endl<<ans;
	return 0;
}
```

### Manacher �㷨

[P3805 ��ģ�塿manacher �㷨](https://www.luogu.com.cn/problem/P3805)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=4.2*1e7+5;
char s[maxn],ss[maxn];
int p[maxn];

int init()
{
	int len=strlen(ss+1);
	int j=3;
	s[1]='#',s[2]='$';
	for(int i=1;i<=len;i++)
		s[j++]=ss[i],s[j++]='$';
	s[j]='@';
	return j;
}

int manacher()
{
	int len=init(),mid=1,mx=1,ans=1;
	for(int i=1;i<=len;i++)
	{
		if(i<mx) p[i]=min(mx-i,p[mid*2-i]);
		else p[i]=1;//ǰ���mxһ�����û�ã�ֱ�Ӹ�Ϊ1��ʼ����
		while(s[i-p[i]]==s[i+p[i]]) p[i]++;
		if(mx<i+p[i]) mid=i,mx=i+p[i];//����mid��mx
		ans=max(ans,p[i]-1);
	}
	return ans;
}

int main()
{
	scanf("%s",ss+1);
	cout<<manacher();
	return 0;
}
```

## DP

### ����

#### ���ϱ���

[P2014 ѡ��](https://www.luogu.com.cn/problem/P2014)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn=2005;
int head[maxn],M,N,nxt[maxn],val[1005],k,f[1005][1005],to[maxn],cnt;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;	
}

//ע�⣬����û�����޿εĽڵ㣬��һ������ڵ�0��Ϊ��Щ������޿�
void dfs(int x)
{
    f[x][1]=val[x];
    for(int i=head[x];i;i=nxt[i])
    {
        dfs(to[i]);
        for(int j=M+1;j;j--)
            for(int k=1;k<j;k++)
                f[x][j]=max(f[x][j],f[to[i]][k]+f[x][j-k]);
    }
}

int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;i++) 
	{
		cin>>k>>val[i];
		if(k==0) add(0,i);
		else add(k,i);
	}
	dfs(0);
	cout<<f[0][M+1];
	return 0;
}
```

#### ���鱳��

[P1757 ͨ��֮���鱳��](https://www.luogu.com.cn/problem/P1757)

```cpp
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int a,b,c;
}bb[10005];

node gg[1005][1005];//gg[i][j]�洢С��i��j����Ʒ�ı��
int id[1005],f[10005],n,m,maxx;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>bb[i].a>>bb[i].b>>bb[i].c;
		id[bb[i].c]++;//��i����Ʒ����Ʒ����
		gg[bb[i].c][id[bb[i].c]].b=bb[i].b;
		gg[bb[i].c][id[bb[i].c]].a=bb[i].a;
		maxx=max(bb[i].c,maxx);
	}
	for(int i=1;i<=maxx;i++)
		for(int j=n;j;j--)
			for(int k=1;k<=id[i];k++)
				if(j>=gg[i][k].a)
					f[j]=max(f[j],f[j-gg[i][k].a]+gg[i][k].b);
	cout<<f[n];
	return 0;
}
```

### LCS

[P1439 ��ģ�塿�����������](https://www.luogu.com.cn/problem/P1439)

```cpp
#include <bits/stdc++.h>
using namespace std;

int a[100005],b[100005],c[100005],dp[100005],mp[100005];

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],mp[a[i]]=i;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
        c[i]=mp[b[i]];
    int tmp=0,ans=-0x7fffffff;
    for(int i=1;i<=n;i++)
		{
        int j=upper_bound(dp+1,dp+tmp+1,c[i])-dp;
        if(j==tmp+1) tmp++,dp[j]=c[i];
        else dp[j]=c[i];
    }
    cout<<tmp;
}
```

> ~~˵���л���OIer д���Ͳ�д OI ģ��ϼ��������Ĵ�����������¥�Σ�˵���������ѧ����������������㣬����ⲻ���������ڵ�������ѩ�ĸ�����������ֻ�ܿ������Ĵ���������β�͸������????????????????�µľ����ںˣ��������˵Ĳ�ξͿ��������ˣ�ֻ�ܶȹ�һ�����ʧ�ܵ�����������~~

## ���Դ���

### ���Ի�

[P3812 ��ģ�塿���Ի�](https://www.luogu.com.cn/problem/P3812)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

int p[55];

void insert(int x)
{
    for(int i=50;i>=0;--i)
        if(x>>i&1)
        {
            if(!p[i]) {p[i]=x;break;}
            else x^=p[i];
        }
}

int pmax()
{
    int ans=0;
    for(int i=50;i>=0;--i)
		if((ans^p[i])>ans) ans^=p[i];
	return ans;
}

signed main()
{
	int n,x;cin>>n;
	for(int i=1;i<=n;i++) cin>>x,insert(x);
	cout<<pmax();
	return 0;
}
```

## ����

### �������

```cpp
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
```

