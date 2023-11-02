#include<stdio.h>
#include<iostream>

using namespace std;

int Compare(char A[],char B[]){
	int j;
	for(j=0;j<6;j++)
		if(A[j]!=B[j])
			return 0;
	return 1;
}

int main(){
	
	int i,j;
	char A[]="madam";
	char B[7];
	
	for(i=0;A[i]!='\0';i++){}
	i=i-1;
	
	for(j=0;j<6;j++){
		B[j]=A[i];
		i--;
	}
	B[j]='\0';
	
	if(Compare(A,B))
		printf("Palindrome");
	else
		printf("Not Palindrome");
	
    
	
	
	return 0;
}
