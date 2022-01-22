#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;
/*a class consists of a definition(constructors) which gives meaning
to a class AND properties/characteristics(functions/mthods) which
provides class with various functionalities it can perform AND 
dependent variables(private variables) on which the definition is
based upon*/
class Array
{
private:
	int *A;
	int size;
	void swap(int *x, int *y);
public:
	int length;
	Array()
	{
		size=10;
		length=0;
		A=new int[size];
	}
	Array(int sz)
	{
		size=sz;
		length=0;
		A=new int[size];
	}
	~Array()
	{
		delete A;
	}
	void Display();
	void Append(int x);
	void Insert(int index, int x);
	void Delete(int index);
	void swap(int* x,int* y);
	int LinearSearch(int key);
	int BinarySearch(int key);
	int Get(int index);
	void Set(int index, int x);
	int Max();
	int Min();
	int Sum();
	float Avg();
	void Reverse();
	void Reverse2();
	void InsertSort(int x);
	int isSorted();
	void Rearrange();
	Array Merge(Array arr2);
	Array* Union(Array arr2);
	Array* Diff(Array arr2);
	Array* Inter(Array arr2);
};

int Array::Get(int index)
{
	if(index>=0 && index<length)
		return *(A+index);
	return -1;
}

void Array::Set(int index, int x)
{
	if(index>=0 && index<length)
		A[index]=x;
}

void Array::Display()
{
	for(int i=0;i<length;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

void Array::Append(int x)
{
	if(length<size)
	{
		A[length]=x;
		length++;
	}
}

void Array::Insert(int index, int x)
{
	if(index>=0 &&index<=length)
	{
		for(int i=length-1;i>=index;i--)
			A[i+1]=A[i];
		A[index]=x;
		length++;
	}
}

void Array::Delete(int index)
{
	if(index>=0 && index<length)
	{
		for(int i=index;i<length-1;i++)
			A[i]=A[i]+1;
		length--;
	}
}

void Array::swap(int* x,int* y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

Array Array::Merge(Array arr2)
{
	int i,j,k;
	i=j=k=0;
	Array arr3(length+arr2.length);
	while(i<length && j<arr2.length)
	{
		if(A[i]<=arr2.Get(j))
			arr3.Append(A[i++]);
		else arr3.Append(arr2.Get(j++));
		k++;
	}
	for(;i<length;k++)
		arr3.Append(A[i++]);
	for(;j<arr2.length;k++)
		arr3.Append(arr2.Get(j++));	
	return arr3;
}

int main(int argc, const char *argv[])
{
	Array arr1(10);
	arr1.Insert(0,0);
	arr1.Insert(1,2);
	arr1.Insert(2,4);
	arr1.Insert(3,6);
	arr1.Insert(4,8);
	
	Array arr2(10);
	arr2.Insert(0,5);
	arr2.Insert(1,10);
	arr2.Insert(2,15);
	arr2.Insert(3,20);
	arr2.Insert(4,25);
	Array arr3=arr1.Merge(arr2);
	arr3.Display();
	getch();
	return 0;
}
