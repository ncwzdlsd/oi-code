#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> t;

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int op,x;cin>>op>>x;
        if(op==1) t.insert({x,i});
        if(op==2) t.erase(t.upper_bound({x,0}));
        if(op==3) cout<<t.order_of_key({x,0})+1<<endl;
        if(op==4)
        {
            auto it=t.find_by_order(x-1);
            cout<<(*it).first<<endl;
        }
        if(op==5)
        {
            auto it=prev(t.lower_bound({x,0}));
            cout<<(*it).first<<endl;
        }
        if(op==6)
        {
            auto it=t.upper_bound({x,INT_MAX});
            cout<<(*it).first<<endl;
        }
    }
    return 0;
}