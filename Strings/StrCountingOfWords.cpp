#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	
	int i,words=1;
	char A[]="Shadabb, Java Full Stack Developer";
	

    for(i=0;A[i]!=0;i++)
    	if(A[i]==' ' && A[i-1]!=' ')
    		words++;
    cout<<"Total Words : "<<words<<endl;
	
	return 0;
}

