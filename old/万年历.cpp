#include <iostream>
using namespace std;

int main()
{	
	int a,b,c,m,n,x,x1,x2,y1,y2,z,z1,z2,z3;
	//�����գ�a��b��c 
	for(;;)
	{	
		cin>>a>>b>>c;
		
		x1=1949/400+1949/4-1949/100;
//		x2=(a-a%400)/400+(a-a%4)/4-(a-a%100)/100;
		x2=a/400+a/4-a/100;
		
		//1949.10.1����
//		y1=(x1)*366+(1949-(x1))*365+31+28+31+30+31+30+31+31+30+1;
		y1=(1949-1)*365+x1+31+28+31+30+31+30+31+31+30+1; 
		//a.b.c����
//		y2=(x2)*366+(a-(x2))*365+(z1);
	
		if((a%4==0&&a%100!=0)||(a%400==0))
		{
			switch(b)
			{
				case 1:z1=c;break;
				case 2:z1=31+c;break;
				case 3:z1=31+29+c;break;
				case 4:z1=31+29+31+c;break;
				case 5:z1=31+29+31+30+c;break;
				case 6:z1=31+29+31+30+31+c;break;
				case 7:z1=31+29+31+30+31+30+c;break;
				case 8:z1=31+29+31+30+31+30+31+c;break;
				case 9:z1=31+29+31+30+31+30+31+31+c;break;
				case 10:z1=31+29+31+30+31+30+31+31+30+c;break;
				case 11:z1=31+29+31+30+31+30+31+31+30+31+c;break;
				case 12:z1=31+29+31+30+31+30+31+31+30+31+30+c;break;
				default:cout<<"����"<<endl;
			}
		}
		else
		{
			switch(b)
			{
				case 1:z1=c;break;
				case 2:z1=31+c;break;
				case 3:z1=31+28+c;break;
				case 4:z1=31+28+31+c;break;
				case 5:z1=31+28+31+30+c;break;
				case 6:z1=31+28+31+30+31+c;break;
				case 7:z1=31+28+31+30+31+30+c;break;
				case 8:z1=31+28+31+30+31+30+31+c;break;
				case 9:z1=31+28+31+30+31+30+31+31+c;break;
				case 10:z1=31+28+31+30+31+30+31+31+30+c;break;
				case 11:z1=31+28+31+30+31+30+31+31+30+31+c;break;
				case 12:z1=31+28+31+30+31+30+31+31+30+31+30+c;break;
				default:cout<<"����"<<endl; 
			}
		}

		y2=(a-1)*365+x2+z1;
		
		if(y1<y2)
		{
			//������
			z=(y2)-(y1);
			switch(z%7)
			{
				case 0:cout<<"������"<<endl;break;
				case 1:cout<<"������"<<endl;break; 
				case 2:cout<<"����һ"<<endl;break;
				case 3:cout<<"���ڶ�"<<endl;break;
				case 4:cout<<"������"<<endl;break;
				case 5:cout<<"������"<<endl;break; 
				case 6:cout<<"������"<<endl;break;
				default:cout<<"����"<<endl;break;
			}
		}
		else
		{
			//������
			z=y1-y2;
			switch(z%7)
			{
				case 0:cout<<"������"<<endl;break;
				case 1:cout<<"������"<<endl;break; 
				case 2:cout<<"������"<<endl;break;
				case 3:cout<<"������"<<endl;break;
				case 4:cout<<"���ڶ�"<<endl;break;
				case 5:cout<<"����һ"<<endl;break; 
				case 6:cout<<"������"<<endl;break;
				default:cout<<"����"<<endl;break;
			}	
		}	
	}
	return 0;
}
