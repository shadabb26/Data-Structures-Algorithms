#include <stdio.h>
#include <iostream>
using namespace std;

int Validate(char A[]){
	
	int i;
	for(i=0;A[i]!='\0';i++)
	{
		if(!(A[i]>=65 && A[i]<=90) && !(A[i]>=97 && A[i]<=122) && !(A[i]>=48 && A[i]<=57) && !A[i]==32)
			return 0;
    }
	return 1;
}


int main(){
	int i;
	char A[]="Shadab";

	if(Validate(A))
		cout<<"Valid String";
	else
		cout<<"Invalid String";
	
	return 0;
	
}
