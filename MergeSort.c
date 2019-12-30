#include<stdio.h>

void MergeSort(int arr[] , int a,int b);
void Merge(int arr[] , int a , int m , int b);

int main()
{
	int l,i;
	scanf("%d", &l);
	
	int a[l];
	
	for(i=0 ; i<l ; i++)
		scanf("%d", &a[i]);
		
		
	MergeSort(a,0,l-1);
	
	for(i=0 ; i<=l-1 ; i++)
		printf("%d ", a[i]);
}

void MergeSort(int arr[] , int a , int b)
{
	if(a<b)
	{
		int m=(a+b)/2;
		
		MergeSort(arr,a,m);
		MergeSort(arr,m+1,b);
		
		Merge(arr,a,m,b);
	}
}

void Merge(int arr[] , int a , int m , int b)
{
	int i,j,k;
	int n1=m-a+1;
	int n2=b-m;
	
	int L[n1];
	int R[n2];
	
	k=a;
	
	for(i=0 ; i<n1 ; i++ , k++)
		L[i]=arr[k];	
		
	for(j=0 ; j<n2 ; j++ , k++)
		R[j]=arr[k];
		
		
	i=0;
	j=0;
	k=a;
	
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=R[j];
			j++;
			k++;
		}
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
				
}
