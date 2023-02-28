#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int n,m,seed,vmax,a[100005];

struct node
{
    int l,r;//左右端点
    mutable int v;//区间值
    friend bool operator < (node a,node b)
    {
        return a.l<b.l;//按左端点排序
    }
    node(int l,int r=0,int v=0):l(l),r(r),v(v){}//为什么要这么初始化，因为node(pos)压入的位置只看l
};

set<node> s;

set<node>::iterator split(int pos)
{
    set<node>::iterator it=s.lower_bound(node(pos));
    if(it!=s.end()&&it->l==pos) return it;
    it--;
    if(it->r<pos) return s.end();
    int l=it->l,r=it->r,v=it->v;
    s.erase(it);//清空当前set准备分裂
    s.insert(node(l,pos-1,v));
    return s.insert(node(pos,r,v)).first;
}

int quickpow(int a,int b,int p)
{
    int t=1,aa=a%p;
    while(b)
    {
        if(b%2==1) t=t*aa%p;
        aa=aa*aa%p;
        b/=2;
    }
    return t;
}

void assign(int l,int r,int x)
{
    set<node>::iterator itr=split(r+1),itl=split(l);
    s.erase(itl,itr);
    s.insert(node(l,r,x));
}

struct nodee
{
    int id,cnt;
    bool friend operator < (nodee a,nodee b)
    {
        return a.id<b.id;
    }
    nodee(int id,int cnt):id(id),cnt(cnt){}
};

int rankk(int l,int r,int x)
{
    set<node>::iterator itr=split(r+1),itl=split(l);
    vector<nodee> vv;
    for(set<node>::iterator it1=itl;it1!=itr;it1++) vv.push_back(nodee(it1->v,it1->r-it1->l+1));
    sort(vv.begin(),vv.end());
    int i;
    for(i=0;i<vv.size();i++)
    {
        if(vv[i].cnt<x) x-=vv[i].cnt;
        else break;
    }
    return vv[i].id;
}


void add(int l,int r,int x)
{
    set<node>::iterator itr=split(r+1),itl=split(l);
    for(set<node>::iterator it3=itl;it3!=itr;it3++) it3->v+=x;
}

int rnd()
{
    int ret=seed;
    seed=(seed*7+13)%1000000007;
    return ret;
}

int cal(int l,int r,int x,int y)
{
    set<node>::iterator itr=split(r+1),itl=split(l);
    int ans=0;
    for(set<node>::iterator it2=itl;it2!=itr;it2++) 
    	ans=(ans+quickpow(it2->v,x,y)*(it2->r-it2->l+1)%y)%y;
    return ans;
}

signed main()
{
    cin>>n>>m>>seed>>vmax;
    for(int i=1;i<=n;++i)
        a[i]=(rnd()%vmax)+1,s.insert(node(i,i,a[i]));
    for(int i=1;i<=m;i++)
    {
        int op,l,r,x,y;
        op=(rnd()%4)+1,l=(rnd()%n)+1,r=(rnd()%n)+1;
        if(l>r) swap(l,r);
        if(op==3) 
        {
            x=(rnd()%(r-l+1))+1;
        } 
        else 
        {
            x=(rnd()%vmax)+1;
        }
        if(op == 4) 
        {
            y=(rnd()%vmax)+1;
        }
        if(op==1) 
        {
            add(l,r,x);
        } 
        else if(op==2) 
        {
            assign(l,r,x);
        } 
        else if(op == 3) 
        {
            cout<<rankk(l,r,x)<<endl;
        } 
        else 
        {
            cout<<cal(l,r,x,y)<<endl;
        }
    }
    return 0;
}