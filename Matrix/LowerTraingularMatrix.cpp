#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Matrix{
	int *A;
	int n;
};

void Set(struct Matrix *m,int i, int j, int x)
{
	if(i>=j)	
		m->A[i*(i-1)/2+j-1]=x;
//		m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j];  Column Representation
}

int Get(struct Matrix m,int i, int j)
{
	if(i>=j)	
		return m.A[i*(i-1)/2+j-1];
//		return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];  Column Representation
	else
		return 0;
}

Display(struct Matrix m)
{
	int i,j;
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			if(i>=j)
				cout<<m.A[i*(i-1)/2+j-1];
//              cout<<m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]; Column Representation
			else 
				cout<<"0";
		}
		cout<<endl;
	}
}



int main()
{
	struct Matrix m;
	int i,j,x;
	cout<<"Enter Dimensions"<<endl;
	cin>>m.n;
	m.A=(int *)malloc(m.n*(m.n+1/2)*sizeof(int));
	
	cout<<"Enter Elements:"<<endl;
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			cin>>x;
			Set(&m,i,j,x);
		}
		cout<<endl;
	}
	Display(m);
	return 0;
}
