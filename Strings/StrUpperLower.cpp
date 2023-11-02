#include <stdio.h>
#include <iostream>
using namespace std;


void toUpperCase(char A[]){
	int i;
	for(i=0;A[i]!='\0';i++){
		A[i]=A[i]-32;
	}
	
	cout<<A<<endl;
}

void toLowerCase(char A[]){
	int i;
	for(i=0;A[i]!='\0';i++){
		A[i]=A[i]+32;
	}
	
	cout<<A<<endl;
}

toggleCase(char A[]){
	int i;
	for(i=0;A[i]!='\0';i++)
		if(A[i]>=65 && A[i]<=90)
			A[i]+=+32;
		else if(A[i]>=97 && A[i]<=122)
			A[i]-=32;
	cout<<A<<endl;
	
}

int main(){
	
	char A[]="welcome";
	char B[]="WELCOME";
	char C[]="WeLcOmE";
	toUpperCase(A);
	toLowerCase(B);
	toggleCase(C);
	
	return 0;
}
