#include<algorithm>
using namespace std;
int n,p,s;
int dp[1005];//dp[i]表示装i体积的东西能够得到的价值 
struct node
{
    int v,w;
}a[1005];//在这里定义一个结构体，因为后面要用到排序 
int cmp(node a,node b)
{
    return a.v<b.v;//简单的排序 
 } 
int main()
{
    scanf("%d%d%d",&n,&p,&s);//输入对应的文件总数，希望最小价值p和硬盘大小s 
    for(int i=1;i<=n;i++)
    scanf("%d%d",&a[i].v,&a[i].w);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        for(int j=s;j>=a[i].v;j--) 
        {
            dp[j]=max(dp[j],dp[j-a[i].v]+a[i].w);
            if(dp[s]>=p) 
            {
                printf("%d",a[i].v);//直接输出，结束程序 
                return 0;
            }
        }
    printf("No Solution!");    //输出不满足条件的情况 
}