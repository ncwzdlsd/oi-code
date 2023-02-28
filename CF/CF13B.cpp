#include<bits/stdc++.h>
using namespace std;
int i,j,k,i1,i2,i3,t;
bool pd;
double X1[4],Y1[4],X2[4],Y2[4];
bool ans(bool a,bool b)
{
    if(a)return a;else return b;
}
double sqr(double a)
{
    return a*a;
}
double far(double X1,double Y1,double X2,double Y2)
{
    return sqrt(sqr(X1-X2)+sqr(Y1-Y2));
}

bool yes(double X1,double Y1,double X2,double Y2,double X3,double Y3)
{
    double a,b;
    if(X3>max(X1,X2)||X3<min(X1,X2))return false;
    if(Y3>max(Y1,Y2)||Y3<min(Y1,Y2))return false;
    if(X1==X2)return X1==X3;
    if(Y1==Y2)return Y1==Y3;
    a=(Y1-Y2)/(X1-X2);
    b=Y1-X1*a;
    return abs(a*X3+b-Y3)<=0.001;
}
bool solve(int a,int b,int c)
{
    double dx,dy,long1,long2,long3;
    bool pd=false;
    if((X1[a]==X1[b])&&(Y1[a]==Y1[b]))
    {dx=X1[a];dy=Y1[b];pd=!(pd);long3=far(X2[a],Y2[a],X2[b],Y2[b]);}
    if((X1[a]==X2[b])&&(Y1[a]==Y2[b]))
    {dx=X1[a];dy=Y2[b];pd=!(pd);long3=far(X2[a],Y2[a],X1[b],Y1[b]);}
    if((X2[a]==X1[b])&&(Y2[a]==Y1[b]))
    {dx=X2[a];dy=Y1[b];pd=!(pd);long3=far(X1[a],Y1[a],X2[b],Y2[b]);}
    if((X2[a]==X2[b])&&(Y2[a]==Y2[b]))
    {dx=X2[a];dy=Y2[b];pd=!(pd);long3=far(X1[a],Y1[a],X1[b],Y1[b]);}
    if(!(pd))return 0;else pd=0;
    long1=far(X1[a],Y1[a],X2[a],Y2[a]);
    long2=far(X1[b],Y1[b],X2[b],Y2[b]);
    if(sqr(long3)>sqr(long1)+sqr(long2))return 0;
    if(yes(X1[a],Y1[a],X2[a],Y2[a],X1[c],Y1[c])&&yes(X1[b],Y1[b],X2[b],Y2[b],X2[c],Y2[c]))
    {
        pd=!(pd);
        long1=far(X1[a],Y1[a],X1[c],Y1[c]);
        long2=far(X2[a],Y2[a],X1[c],Y1[c]);
        if(long1<=0)return 0;
        if(long2<=0)return 0;
        if(min(long1,long2)*4<max(long1,long2))return false;
        long1=far(X1[b],Y1[b],X2[c],Y2[c]);
        long2=far(X2[b],Y2[b],X2[c],Y2[c]);
        if(long1<=0)return 0;
        if(long2<=0)return 0;
        if(min(long1,long2)*4<max(long1,long2))return false;
    }
    if(yes(X1[a],Y1[a],X2[a],Y2[a],X2[c],Y2[c])
    &&yes(X1[b],Y1[b],X2[b],Y2[b],X1[c],Y1[c]))
    {
        pd=!(pd);
        long1=far(X1[a],Y1[a],X2[c],Y2[c]);
        long2=far(X2[a],Y2[a],X2[c],Y2[c]);
        if(long1<=0)return 0;
        if(long2<=0)return 0;
        if(min(long1,long2)*4<max(long1,long2))return false;
        long1=far(X1[b],Y1[b],X1[c],Y1[c]);
        long2=far(X2[b],Y2[b],X1[c],Y1[c]);
        if(long1<=0)return 0;
        if(long2<=0)return 0;
        if(min(long1,long2)*4<max(long1,long2))return false;
    }
    return pd;
}
int main()
{
    cin>>t;
    for(i=1;i<=t;i++)
    {
        pd=false;
        for(j=1;j<=3;j++)
            cin>>X1[j]>>Y1[j]>>X2[j]>>Y2[j];
        if(!(pd))
        {
            for(i1=1;i1<=2;i1++)
                for(i2=i1+1;i2<=3;i2++)
                    pd=ans(pd,solve(i1,i2,6-i1-i2));
        }
        else
            pd=false;
        if(pd) cout<<"YES"<<endl;else cout<<"NO"<<endl;
    }
    return 0;
}