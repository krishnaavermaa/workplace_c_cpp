#include<stdlib.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int *A;
char *R;
void permutation(char str[],int k,int len);
int main()
{
	string s;
	cin>>s;
	int len=s.length();
	A=new int(len+1);
	R=new char(len+1);
	for(int i=0;i<len;i++)
		A[i]=0;
	char str[len+1];
	s.copy(str,len,0);
	permutation(str,0,len);
}
void permutation(char str[], int k,int len)
{
	if(str[k]=='\0')
	{
		R[k]='\0';
		cout<<R<<endl;
	}
	for(int i=0;i<len;i++)
	{
		if(A[i]==0)
		{
			A[i]=1;
			R[k]=str[i];
			permutation(str,k+1,len);
			A[i]=0;
		}
	}
}