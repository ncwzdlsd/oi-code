#include <bits/stdc++.h>  
using namespace std;  

int tra[1005];  
  
int main()  
{  
    int n,A,B,flag;  
    while(cin>>n)
    {  
        stack<int> s;  
        while(1)
        {
			cin>>tra[1];
	        if(tra[1]==0) break;  
	        {
		        for(int i=2;i<=n;i++) cin>>tra[i];
		        A=B=flag=1;   
		        while(B<=n)   
		        {  
		            if(A==tra[B]) {A++,B++;}
		            else if(!s.empty()&&s.top()==tra[B]) {s.pop(),B++;}
		            else if(A<=n) {s.push(A++);}
		            else {flag=0;break;}
		        }  
		        printf("%s\n",flag?"Yes":"No");
	        }
        }  
		cout<<endl;
    }  
    return 0;
}  