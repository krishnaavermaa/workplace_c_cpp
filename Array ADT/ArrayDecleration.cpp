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
	int LinearSearch(int key);
	int BinarySearch(int key);
	int Get(int index);
	void Set(int index, int x);
	int Max();
	int Min();
	int Sum();
	float Avg();
	void Reverse();
	void RevDigits();
	void BubbleSort();
	void SelectionSort();
	void InsertSort(int x);
	int isSorted();
	void Rearrange();
	Array Merge(Array arr2);//works if both i/p arrays are similarly sorted
	Array Union(Array arr2);//works if both i/p arrays are similarly sorted
	Array Diff(Array arr2);//works if both i/p arrays have same length 
	Array Inter(Array arr2);//works if both i/p arrays are similarly sorted
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

void Array::swap(int* x,int* y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

int Array::LinearSearch(int key)
{
	for(int i=0;i<length;i++)
	{
		if(A[i]==key) return i;
	}
	return -1;
}

int Array::BinarySearch(int key)
{
	int s=0,e=length-1,m,sort=isSorted();
	while(s<=e)
	{
		m=(s+e)/2;
		if(A[m]==key) return m;
		if(sort==1)//asc
		{
			if(A[m]>key) e=m-1;
			else s=m+1;
		}
		if(sort==-1)//des
		{
			if(A[m]>key) s=m+1;
			else e=m-1;
		}
	}
	return -1;
}

int Array::isSorted()
{
	int asc=0,des=0;
	for(int i=1;i<length;i++)
	{
		if(A[i-1]-A[i]>0)
			des++;
		else if(A[i-1]-A[i]<0)
			asc++;
	}
	if(asc==length-1) return 1;//where 1 represents ascendingly sorted array
	if(des==length-1) return -1;//where -1 represents descendingly sorted array
	return 0;//means unsorted array
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

int Array::Max()
{
	int max=A[0];
	for(int i=0;i<length;i++)
	{
		if(max<A[i])
			max=A[i];
	}
	return max;
}

int Array::Min()
{
	int min=A[0];
	for(int i=0;i<length;i++)
	{
		if(min>A[i])
			min=A[i];
	}
	return min;
}

float Array::Avg()
{
	float avg=0;
	for(int i=0;i<length;i++)
		avg=avg+A[i];
	avg=avg/(float)length;
	return avg;
}

void Array::Reverse()
{
	for(int i=0,j=length-1;i<j;i++,j--)
	{
		/*int temp=A[i];
		A[i]=A[j];
		A[j]=temp;*/
		swap(&A[i],&A[j]);
	}
}

void Array::RevDigits()
{
	int n,sum,l;
	for(int i=0;i<length-1;i++)
	{
		n=A[i],sum=0,l=length;
		while(n!=0)
		{
			sum=sum+(n%10)*pow(10,--l);
			n=n/10;
		}
		A[i]=sum;
	}
}

void Array::BubbleSort()//for ascending sort
{
	for(int i=length-1;i>0;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(A[j-1]>A[j]) swap(&A[i],&A[j]);
		}
	}
}

void Array::SelectionSort()//for descending sort
{
	for(int i=0;i<length-1;i++)
	{
		for(int j=i;j<length-1;j++)
		{
			if(A[j]>A[i]) swap(&A[j], &A[i]);
		}
	}
}

void Array::InsertSort(int x)
{
	int i=length-1;
	if(length<size)
	{
		if(isSorted()==1)
		{
			while(A[i]>x) Insert(i+1,A[i--]);
			A[--i]=x;
		}
		if(isSorted()==-1)
		{
			while(A[i]<x) Insert(i+1,A[i--]);
			A[--i]=x;
		}
	}
}

void Array::Rearrange()
{
	int i=0,j=length-1;
	while(i<j)
	{
		while(A[i]<0) i++;
		while(A[j]>=0) j++;
		if(i<j) swap(&A[i], &A[j]);
	}
}

//this fn works ONLY if input arrays are sorted either BOTH ascendingly 
//or BOTH descendingly
Array Array::Merge(Array arr2)
{
	int i,j,k;
	i=j=k=0;
	Array arr3(length+arr2.length);
	if(arr2.isSorted()!=isSorted()) return arr3;
	int sorted=arr2.isSorted();
	if(sorted==1)//ascending
	{
		while(i<length && j<arr2.length)
		{
			if(A[i]<=arr2.Get(j))
				arr3.Append(A[i++]);
			else arr3.Append(arr2.Get(j++));
			k++;
		}
	}
	else if(sorted==-1)//descending
	{
		while(i<length && j<arr2.length)
		{
			if(A[i]>=arr2.Get(j))
				arr3.Append(A[i++]);
			else arr3.Append(arr2.Get(j++));
			k++;
		}
	}
	for(;i<length;k++)
		arr3.Append(A[i++]);
	for(;j<arr2.length;k++)
		arr3.Append(arr2.Get(j++));	
	return arr3;
}

//this fn works ONLY if input arrays are sorted either BOTH ascendingly 
//or BOTH descendingly
Array Array::Union(Array arr2)
{
	int i,j,k;
	i=j=k=0;
	Array arr3(length+arr2.length);
	if(arr2.isSorted()!=isSorted()) return arr3;
	int sorted=arr2.isSorted();
	if(sorted==1)//ascending
	{
		while(i<length && j<arr2.length)
		{
			if(A[i]<=arr2.Get(j))
				arr3.Append(A[i++]);
			else arr3.Append(arr2.Get(j++));
			k++;
		}
	}
	else if(sorted==-1)//descending
	{
		while(i<length && j<arr2.length)
		{
			if(A[i]>=arr2.Get(j))
				arr3.Append(A[i++]);
			else arr3.Append(arr2.Get(j++));
			k++;
		}
	}
	for(;i<length;k++)
		arr3.Append(A[i++]);
	for(;j<arr2.length;k++)
		arr3.Append(arr2.Get(j++));	
	return arr3;
}

Array Array::Diff(Array arr2)
{
	Array arr3(length);
	if(arr2.length!=length) return arr3;
	for(int i=0;i<length;i++)
		arr3.Append(A[i]-arr2.Get(i));
	return arr3;
}

Array Array::Inter(Array arr2)
{
	int i,j,k,len=0;
	i=j=k=0;
	if(length>=arr2.length)
		len=length;
	else len=arr2.length;
	Array arr3(len);
	if(isSorted()!=arr2.isSorted()) return arr3;
	if(isSorted()==1)//asc
	{
		while(i<length && j<arr2.length)
		{
			if(A[i]<arr2.Get(j)) i++;
			if(arr2.Get(j)<A[i]) j++;
			if(A[i]==A[j])
			{
				arr3.Insert(k++,A[i]);
				i++;
				j++;
			}
		}
	}
	else if(isSorted()==-1)//des
	{
		while(i<length && j<arr2.length)
		{
			if(A[i]>arr2.Get(j)) i++;
			if(arr2.Get(j)>A[i]) j++;
			if(A[i]==A[j])
			{
				arr3.Insert(k++,A[i]);
				i++;
				j++;
			}
		}
	}
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
