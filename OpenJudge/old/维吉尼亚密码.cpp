#include <bits/stdc++.h>
using namespace std;

char key[10001],s[10001]; 

//1.ָ�루���ߵ�ַ�������ڵ�ַ�����㣩 
void daxie(char *x)
{
//	char r;
//	cout<<"input:"<<*x; 
	
	if(('z'>=*x)&&('a'<=*x))
	{
		*x=*x-('a'-'A');
	}
	
//	return r;
}
/*
2.��ַ���ã��β�ֱ��ָ��ʵ�Σ����βμ�����ֵ���ݸ�ʵ�Σ� 
void daxie(char &x) 
{
	if(('z'>=x)&&('a'<=x))
	{
		x=x-('a'-'A');
	}
}
3.��ֵ���ã�����ֵ���ݣ�ʵ�δ��ݸ��βΣ�
void daxie(char x) 
{
	if(('z'>=x)&&('a'<=x))
	{
		x=x-('a'-'A');
	}
}
*/ 



int main()
{	for(;;)
	{
		gets(key);
		gets(s);
		int lenkey=strlen(key);
		int lens=strlen(s);
		
		for(int i=0;i<lenkey;i=i+1)
		{
	//		1�� 
			daxie(&key[i]);		
	//		cout<<",output:"<<key[i]<<endl;
	/*		2.
			daxie(key[i])
			3.(���βε�ֵ������ʵ�Σ� 
			key[i]=daxie(key[i])
	*/		
		}
		
		int j=0;
		
		for(int i=0;i<lens;i=i+1)
		{
			if((s[i]<='Z')&&(s[i]>='A'))
			{
				s[i]=s[i]-(key[j]-'A');
				j=j+1;
				if(s[i]<'A')
				{
					s[i]='Z'-('A'-s[i])+1;
				}
			}
			else if((s[i]<='z')&&(s[i]>='a'))
			{
				s[i]=s[i]-(key[j]-'A');
				j=j+1;
				if(s[i]<'a')
				{
					s[i]='z'-('a'-s[i])+1;			
				}
			}
			else
			{
			}
			
			if(j>lenkey-1)
			{
				j=0;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
