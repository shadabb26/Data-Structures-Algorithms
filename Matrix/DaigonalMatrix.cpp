#include <stdio.h>
#include <iostream>

using namespace std;

struct Matrix
{
	int A[10];
	int n;
};

void Set(struct Matrix *m,int i, int j,int x)
{
	if(i==j)
		m->A[i-1]=x;
}

int Get(struct Matrix m,int i, int j)
{
	if(i==j)
		return m.A[i-1];
	return 0;
}


void Display(struct Matrix m)
{
	int i,j;
	for(i=0;i<m.n;i++)
	{
		for(j=0;j<m.n;j++)
		{
			if(i==j)
				cout<<m.A[i]<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
}


int main(){
	
	struct Matrix m;
	m.n=4;
	Set(&m,1,1,51);
	Set(&m,2,2,25);
	Set(&m,3,3,53);
	Set(&m,4,4,52);
	cout<<"Element At 2,2 : "<<Get(m,2,2)<<endl;
	Display(m);
	return 0;
}
