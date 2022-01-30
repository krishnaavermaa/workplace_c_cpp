#include<stdlib.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Element{
	int I;
	int J;
	int x;
};
struct SparseMatrix{
	/*we have created a structure of all these
	elements as we don't want to pass everything
	m,n,num and *e separately to every method 
	which needs it. Because those method require 
	all these info like in a pack*/
	int m;
	int n;
	int num;
	struct Element* e;
	/*this Element* e is the main 2-d array i.e 
	3-column array (coordinateList) we are using*/
};

void create(SparseMatrix *A)
{
	/*parameter is pointer as we want the changes 
	to be reflected in the SparseMatrix variable 
	in main() which we are passing in all other 
	methods in main. Other approach is to declare 
	SparseMatrix A as global instead.*/
	cout<<"Enter dimension of matrix"<<endl;
	cin>>A->m;
	cin>>A->n;
	cout<<"Enter the number of non-zero elements"<<endl;
	cin>>A->num;
	A->e=new Element[A->num+1];
	A->e[0]={A->m,A->n,A->num};
	cout<<"Enter all the elements of matrix"<<endl;
	int k=1;
	for(int i=0;i<A->m;i++)
	{
		for(int j=0;j<A->n;j++)
		{
			int temp;
			cin>>temp;
			if(temp!=0)
			{
				A->e[k].I=i;
				A->e[k].J=j;
				A->e[k].x=temp;
				k++;
			}
		}
	}
}

SparseMatrix* add(SparseMatrix *A, SparseMatrix *B)
{
	SparseMatrix* C;
	C=new SparseMatrix;
	C->m=A->m;
	C->n=A->n;
	C->num=A->num+B->num;
	C->e=new Element[C->num+1];
	C->e[0]={C->m,C->n,C->num};
	if(A->m==B->m && A->n==B->n)
	{
		int i=1,j=1,k;
		for(k=1;k<C->num+1 || i<A->num+1 || j<B->num+1;k++)
		{
			cout<<"#"<<endl;
			if(A->e[i].I < B->e[j].I)
			{
				C->e[k].I=A->e[i].I;
				C->e[k].J=A->e[i].J;
				C->e[k].x=A->e[i].x;
				i++;
				cout<<"_1_"<<C->e[k].x<<endl;
			}
			else if(A->e[i].I > B->e[j].I)
			{
				C->e[k].I=B->e[j].I;
				C->e[k].J=B->e[j].J;
				C->e[k].x=B->e[j].x;
				j++;
				cout<<"_2_"<<B->e[j].x<<endl;
			}
			else// if(A->e[i].I == B->e[j].I)
			{
				if(A->e[i].J < B->e[j].J)
				{
					C->e[k].I=A->e[i].I;
					C->e[k].J=A->e[i].J;
					C->e[k].x=A->e[i].x;
					i++;
					cout<<"_3_"<<C->e[k].x<<endl;
				}
				else if(A->e[i].J > B->e[j].J)
				{
					C->e[k].I=B->e[j].I;
					C->e[k].J=B->e[j].J;
					C->e[k].x=B->e[j].x;
					j++;
					cout<<"_4_"<<C->e[k].x<<endl;
				}
				else// if(A->e[i].J == B->e[j].J)
				{
					C->e[k].I=A->e[i].I;
					C->e[k].J=A->e[i].J;
					C->e[k].x=A->e[i].x+B->e[j].x;
					i++;
					j++;
					cout<<"_5_"<<C->e[k].x<<endl;
				}
			}
		}
		while(B->num > j)
		{
			C->e[k].I=B->e[j].I;
			C->e[k].J=B->e[j].J;
			C->e[k].x=B->e[j].x;
			j++;
			k++;
		}
		while(A->num > i)
		{
			C->e[k].I=A->e[i].I;
			C->e[k].J=A->e[i].J;
			C->e[k].x=A->e[i].x;
			i++;
			k++;
		}
			
	}
		return C;
}

void display(SparseMatrix *A)
{
	int k=1;
	for(int i=0;i<A->m;i++)
	{
		for(int j=0;j<A->n;j++)
		{
			if(i==A->e[k].I && j==A->e[k].J){
				cout<<A->e[k].x;
				k++;
			}
			else cout<<"0";
			cout<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	struct SparseMatrix A;
	struct SparseMatrix B;
	struct SparseMatrix *C;
	create(&A);
	create(&B);
	C=add(&A,&B);
	display(C);
}