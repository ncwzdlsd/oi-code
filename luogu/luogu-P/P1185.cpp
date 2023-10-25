#include <bits/stdc++.h>
using namespace std;

const int maxn=12,maxm=12;
bool noo[maxm][1<<maxm];
int pos[2][1<<maxm];

int main() 
{
    int n,m;cin>>m>>n;
    pos[0][0]=(1<<m)-(1<<(m-2));
	while(n--)
	{
        int x,y;cin>>x>>y;
        noo[x-1][y-1]=true;
    }
    for(int i=1;i<m;++i)
        for(int j=0;j<(1<<i);++j)
            if(noo[i-1][j>>1])
                noo[i][j]=true;
    for(int i=1;i<pos[0][0];++i) cout<<' ';
    puts("o");
    for(int i=1;i<m;++i) 
    {
        for(int j=0;j<(1<<i);++j)
            pos[1][j]=pos[0][j>>1]+(j&1?1:-1);
        swap(pos[0],pos[1]);
        for (int k=1;k<max((1<<(m-i))-(1<<(m-i-2)),2);++k) 
        {
            for(int j=1,l=0;l<(1<<i);++j)
                if(j==pos[0][l])
                    putchar(noo[i][l]?' ':(l&1?'\\':'/')),
                    pos[0][l]+=l&1?1:-1,
                    ++l;
                else cout<<' ';
            puts("");
        }
        for(int j=1,k=0;k<(1<<i);++j)
            putchar(j==pos[0][k]&&!noo[i][k++]?'o':' ');
        puts("");
    }
    return 0;
}
