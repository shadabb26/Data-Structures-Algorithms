#include <stdio.h>
#include <iostream>

using namespace std;


void Swap(char *a, char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void Permutation(char S[],int l,int h)
{
	int i;
	if(l==h)
	{
		cout<<S<<endl;
	}
	else
	{
		for(i=l;i<=h;i++)
		{
			Swap(&S[l],&S[i]);
			Permutation(S,l+1,h);
			Swap(&S[l],&S[i]);
		}
	}
}


int main()
{
	char A[]="ABC";
	Permutation(A,0,2);
	return 0;
}
