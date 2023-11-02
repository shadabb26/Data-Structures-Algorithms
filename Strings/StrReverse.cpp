#include<stdio.h>
#include<iostream>

using namespace std;

void reverseWithArray(char A[]){
	int i,j;
	char B[7];
	
	for(i=0;A[i]!='\0';i++){}
	i=i-1;
	
	for(j=0;j<=6;j++){
        B[j]=A[i];
		i--;
	}
	B[j]='\0';
	cout<<B<<endl;
}

void reverseWithSwap(char A[]){
	int i,j;
	char temp;

	for(j=0;A[j]!='\0';j++){}
	j=j-1;
	
	for(i=0;i<j;i++,j--){
		temp=A[i];
		A[i]=A[j];
		A[j]=temp;
	}
	cout<<A<<endl;
}


int main(){
	
	char A[]="Python";
	reverseWithArray(A);
	reverseWithSwap(A);
	
	
	return 0;
}
