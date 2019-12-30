#include<stdio.h>
#include<string.h>

void LEX(char arr[][100],int n);
void VOW(char arr[][100],int n);
void DISTINCT(char arr[][100],int n);

int main()
{
	int n,i;
	scanf("%d",&n);
	
	char arr[n][100];
	
	for(i=0 ; i<n ; i++)
		scanf("%s", arr[i]);
	
	int inst,ins;
	scanf("%d",&inst);
	

	int inp[inst];
	char fun[inst][9];
	
	for(ins=0 ; ins<inst ; ins++)
	{
		scanf("%d", &inp[ins]);
		
		if(inp[ins]==2)
			scanf("%s", fun[ins]);
	}
	
	for(ins=0 ; ins<inst ; ins++)
	{	
		if(inp[ins]==1)
		{
			for(i=0 ; i<n ; i++)
				printf("%s ", arr[i]);
				
			printf("\n");
		}
		else if(inp[ins]==2)
		{
			if(strcmp(fun[ins],"LEX")==0)
				LEX(arr,n);
				
			else if(strcmp(fun[ins],"VOW")==0)
				VOW(arr,n);
				
			else if(strcmp(fun[ins],"DISTINCT")==0)
				DISTINCT(arr,n);				
		}
	}
}

void LEX(char arr[][100],int n)
{
	int i,j;
	char temp[100];
	
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n-1-i ; j++)
		{
			if(strcmp(arr[j],arr[j+1])>0)
			{
				strcpy(temp,arr[j]);
				strcpy(arr[j],arr[j+1]);
				strcpy(arr[j+1],temp);
			}
		}
}

void VOW(char arr[][100],int n)
{
	int temp,i,j;
	char tem[100];
	int brr[n];
	for(i=0 ; i<n ; i++)
	{
		brr[i]=0;
		
		for(j=0 ; arr[i][j]!='\0' ; j++)
		{
			switch(arr[i][j])
			{
				case 'a':
				case 'e':
				case 'o':
				case 'i':
				case 'u':
					brr[i]++;
			}
		}
	}
	
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n-1-i ; j++)
			if(brr[j]<brr[j+1])
			{
				temp=brr[j];
				brr[j]=brr[j+1];
				brr[j+1]=temp;
				
				strcpy(tem,arr[j]);
				strcpy(arr[j],arr[j+1]);
				strcpy(arr[j+1],tem);
			}
}

void DISTINCT(char arr[][100],int n)
{
	int temp,i,j;
	char tem[100];
	int alph[26]={0};
	int brr[n];
	
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j<26 ; j++)
			alph[j]=0;
		
		brr[i]=0;
		
		for(j=0 ; arr[i][j]!='\0' ; j++)
			alph[arr[i][j] - 'a']=1;
	
	
		for(j=0 ; j<26 ; j++)
			if(alph[j]==1)
				brr[i]++;
	}
	
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n-1-i ; j++)
			if(brr[j]<brr[j+1])
			{
				temp=brr[j];
				brr[j]=brr[j+1];
				brr[j+1]=temp;
				
				strcpy(tem,arr[j]);
				strcpy(arr[j],arr[j+1]);
				strcpy(arr[j+1],tem);
			}
}
