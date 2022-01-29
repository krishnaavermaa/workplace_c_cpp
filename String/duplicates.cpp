#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string A;
	getline(cin,A);
	//cout<<A;
	int x=0,X=0,x2=0,X2=0,len=A.length();
	char str[len+1];
	A.copy(str,len,0);
	//cout<<sizeof(int)<<endl;
	for(int i=0;i<len;i++)
	{
		//cout<<"#";
		int y=1;
		if(str[i]>=97 && str[i]<=122)
		{
			//cout<<"#1";
			y=y<<(str[i]-97);
			//cout<<y;
			if((y&x)==0)
				x=y|x;
			else if((y&x)>0 && (y&x2)==0)
			{
				x2=x2|y;
				cout<<str[i]<<endl;
			}
		}
		else if(str[i]>=65 && str[i]<=90)
		{
			//cout<<"#2";
			y=y<<(str[i]-65);
			if((y&X)==0)
				X=y|X;
			else if((y&X)>0 && (y&X2)==0)
			{
				X2=X2|y;
				cout<<str[i]<<endl;
			}
		}
	}
	return 0;
}
