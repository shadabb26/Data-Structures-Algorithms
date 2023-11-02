#include <stdio.h>
#include <stdlib.h>


struct Array{
	int A[10];
	int size;
	int length;
};


void Display(struct Array arr){
	int i;
	printf("Array : ");
	for(i=0;i<=arr.length;i++)
		printf("%d ",arr.A[i]);
	printf("\n");
}

void Append(struct Array *arr,int x){
	if(arr->length<arr->size){
		arr->A[arr->length++]=x;
	}
}

void Insert(struct Array *arr,int index,int x){
	int i;
	if(index>=0 && index<=arr->length){
		for(i=arr->length;i>index;i--)
		    arr->A[i]=arr->A[i-1];
		arr->A[index]=x;
		arr->length++;
	}
}

int Delete(struct Array *arr,int index){
	int i,x;
	if(index>=0 && index< arr->length){
        x=arr->A[index];
		for(i=index;i<arr->length-1;i++)
			arr->A[i]=arr->A[i+1];
		arr->length--;
		return x;
	}
	return 0;
}

void Swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int LinearSearch(struct Array *arr,int x){
	int i;
	for(i=0;i<arr->length;i++)
		if(arr->A[i]==x)
		// Transposition done to improve Linear Search 
		Swap(&arr->A[i],&arr->A[i-1]);
		// Move to Header / Front 
       // Swap(&arr->A[i],&arr->A[0]);
		return i;
	return -1;
}

int BinarySearch(struct Array arr,int key){
	int high,low,mid;
	low=0;
	high=arr.length;
	
	while(low<=high){
		mid=(low+high)/2;
		if(key==arr.A[mid])
			return mid;
		else if(key<arr.A[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
	
}

int RecursiveBinarySearch(int a[],int low,int high,int key){
	int mid;
	if(low<=high){
		mid=(low+high)/2;
		if(key==a[mid])
			return mid;
		else if(key<a[mid])
			return RecursiveBinarySearch(a,low,mid-1,key);
		else
			return  RecursiveBinarySearch(a,mid+1,high,key);
	}
	return -1;
}

int Get(struct Array arr,int index){
	if(index>=0 && index <arr.length)
		return arr.A[index];
	return -1;
}

void Set(struct Array *arr,int index,int x){
	if(index>=0 && index <arr->length)
		arr->A[index]=x;
}

int Max(struct Array arr){
	int i,max;
	max=arr.A[0];
		for(i=0;i<arr.length;i++)
			if(arr.A[i]>max)
				max=arr.A[i];
		return max;
}

int Min(struct Array arr){
	int i,min;
	min=arr.A[0];
		for(i=0;i<arr.length;i++)
			if(arr.A[i]<min)
				min=arr.A[i];
		return min;
}

int Sum(struct Array arr){
	int i,sum=0;
	for(i=0;i<arr.length;i++)
		sum+=arr.A[i];
	return sum;
}

int Average(struct Array arr){
	int i,sum=0;
	for(i=0;i<arr.length;i++)
		sum+=arr.A[i];
	return sum/2;
}

void Reverse(struct Array *arr){
	int i,j,B[arr->length];
	for(i=arr->length-1,j=0;i>=0;i--,j++)
		B[j]=arr->A[i];
	for(i=0;i<arr->length;i++)
		arr->A[i]=B[i];
}

void ReverseSwap(struct Array *arr){
	int i,j;
	for(i=arr->length-1,j=0;i<j;i++,j--)
		Swap(&arr->A[i],&arr->A[j]);
}

void LeftRotate(struct Array *arr){
	int i;
	for(i=0;i<arr->length-1;i++)
		arr->A[i]=arr->A[i+1];
}

void RightRotate(struct Array *arr){
	int i;
	for(i=arr->length-1;i>=0;i--)
		arr->A[i]=arr->A[i-1];
}

void InsertInSorted(struct Array *arr,int x){
	int i=arr->length;
	if(arr->length==arr->size)
		return ;
	while(i>=0 && arr->A[i]>x)
	{
		arr->A[i+1]=arr->A[i];
		i--;
	}
		
	arr->A[i+1]=x;
	arr->length++;
}

int isSorted(struct Array arr){
	int i;
	for(i=0;i<arr.length;i++)
		if(arr.A[i]>arr.A[i+1])
			return 0;
	return 1;
}

void Rearrange(struct Array *arr){
	int i,j;
	i=0;
	j=arr->length;
	while(i<j){
		while(arr->A[i]<0)i++;
		while(arr->A[j]>=0)j--;
		if(i<j)Swap(&arr->A[i],&arr->A[j]);
	}
}

struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
	int i,j,k;
	i=j=k=0;
	
	struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
	
	while(i<arr1->length && j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
			arr3->A[k++]=arr1->A[i++];
		else
	 		arr3->A[k++]=arr2->A[j++];
	}
	for(;i<arr1->length;i++)
		arr3->A[k++]=arr1->A[i];
	for(;j<arr2->length;j++)
		arr3->A[k++]=arr2->A[j];
	arr3->length=arr1->length+arr2->length;
	arr3->size=10;
	
	return arr3;
}

struct Array* Union(struct Array *arr1,struct Array *arr2)
{
	int i,j,k;
	 i=j=k=0;
	
	struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
	
	while(i<arr1->length && j<arr2->length)
	{
	 	if(arr1->A[i]<arr2->A[j])
	 		arr3->A[k++]=arr1->A[i++];
	 	else if(arr2->A[j]<arr1->A[i])
	 		arr3->A[k++]=arr2->A[j++];
	 	else
	 	{
	 		arr3->A[k++]=arr1->A[i++];
	 		j++;
	 	}
	 	
	}
	 
	 	for(;i<arr1->length;i++)
	 		arr3->A[k++]=arr1->A[i];
	 	for(;j<arr2->length;j++)
	 		arr3->A[k++]=arr2->A[j];
	
	 	arr3->length=k;
	 	arr3->size=10;
	
	return arr3;
}

struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
	int i,j,k;
	i=j=k=0;
	
	struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
	
	while(i<arr1->length && j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
	 		i++;
		else if(arr2->A[j]<arr1->A[i])
	 		j++;
	 	else if(arr1->A[i]==arr2->A[j])
	 	{
	 		arr3->A[k++]=arr1->A[i++];
	 		j++;
	 	}
	 	
	}

 	arr3->length=k;
 	arr3->size=10;

 	return arr3;
}

struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
	int i,j,k;
	i=j=k=0;
	
	struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
	
	while(i<arr1->length && j<arr2->length)
	{
	 	if(arr1->A[i]<arr2->A[j])
	 		arr3->A[k++]=arr1->A[i++];
	 	else if(arr2->A[j]<arr1->A[i])
	 		j++;
	 	else
	 	{
	 		i++;
	 		j++;
	 	}
	}
	
	for(;i<arr1->length;i++)
		arr3->A[k++]=arr1->A[i];
	
	arr3->length=k;
	arr3->size=10;
	
	return arr3;
}



int main(){

	

	return 0;
}
