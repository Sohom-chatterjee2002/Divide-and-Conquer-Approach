/*Binary Search - DAC Approach*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int binary_search(int arr[],int low,int high,int key)
{
	if(high<low)
		return -1;
	else
	{
		int mid=(floor(low+high)/2);   //divide
		if(arr[mid]==key)
			return mid;
		int left,right;
		left=binary_search(arr,low,mid-1,key);    //conquer
		right=binary_search(arr,mid+1,high,key);  //conquer
		//combine
		if(left==-1 && right==-1)
			return -1;
		else if(left==-1 && right!=-1)
			return right;
		else
			return left;
	}
}
int main()
{
	int n,i,key,index;
	int *arr;
	printf("Enter the number of element in your array: ");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int));
	printf("Enter your array elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter your search element: ");
	scanf("%d",&key);
	index=binary_search(arr,0,n-1,key);
	if(index==-1)
		printf("%d is not found in your inputted array.\n",key);
	else
		printf("%d is found in your array at index %d",key,index);
	free(arr);
	return 0;
}
