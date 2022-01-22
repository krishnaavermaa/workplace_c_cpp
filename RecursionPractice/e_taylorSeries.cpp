#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

//best approach overall
double taylor(int x, int n)
{
	double y=1;
	for( ;n>=1;n--)
		y=1+x/(double)n*y;
	return y;
}
//best approach in recursive
/*
double taylor(int x, int n)
{
	static double y=1;
	if(n==0)
		return y;
	y=1+(x/(double)n)*y;
	return taylor(x,n-1);
}
/*
//just better approach
double taylor(int x,int n)
{
	static int p=1;
	static int f=1;
	if(n==0)
		return 1;  
	double res=taylor(x,n-1);
	p=p*x;
	f=f*n;
	return res+p/(double)f;
}*/
int main()
{
    cout<<taylor(5,15);
}