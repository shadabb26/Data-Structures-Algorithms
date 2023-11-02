#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	
//	Using Concept of HASH TABLE
	
	int i;
	char A[]="finding";
	int H[26]={0};
	
	for(i=0;A[i]!='\0';i++)
	{
		H[A[i]-97]+=1;
	}
	for(i=0;i<26;i++)
	{
		if(H[i]>1)
		{
			printf(" %c comes %d Times\n",i+97,H[i]);
			
		}
		
	}
	
	return 0;
}
