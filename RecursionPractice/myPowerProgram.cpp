//something wrong with this!!!!!!
//power function i.e. n to power m
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int pow(int n,int m)
{
	if(m==0) return 1;
	if(m%2==0)
		return pow(n*n,m/2);
	return n*pow(n*n,(m-1)/2);
}
int factor(int n, int m)
{
	int res=1;
	int i=1;
	int count=0;
	while(m!=1)
	{
		if(m%i==0)
		{
			count++;
			m=m/i;
			continue;
		}
		if(count!=0) res=res*pow(n,count);
		i++;
		count=0;
	}
	return res;
}
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<factor(n,m);
	return 0;
}