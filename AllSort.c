#include <stdio.h>
void ins(int a[], int n)   //Insertion Sort
{
	int i,j,x;
	for(i = 1; i < n;i++)
	{
		j = i - 1;
		x = a[i];
		while(j >= 0 && a[j] > x)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}
void qs(int a[], int l, int h)     //Quick Sort
{
    int i;
	if(h > l)
	{
		int m = par(a,l,h - 1);
		qs(a,l,m - 1);
		qs(a,m + 1,h);
	}
}

int par(int a[],int l, int h)
{
    int j,t = 0;
	int p = a[h];
	int i = l - 1;
	for(j = l;j < h;j++)
	{
		if(a[j] <= p)
		{
			i++;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
    t = a[i+1];
	a[i+1] = a[h];
	a[h] = t;
	return (i+1);
}


void bubble(int a[], int n)     //Bubble sort
{
	int i,j,t = 0;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t ", a[i]);
  
}

int main()
{
	int i,n,ch;
	printf("Enter the array size\n");
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter the array elements\n");
	for(i = 0;i < n;i++)
		scanf("%d",&arr[i]);
		
	printf("Unsorted array elemnts\n");
	for(i = 0;i < n;i++)
		printf("%d\t",arr[i]);
		
	printf("\n 1. insertion\n 2. Quick\n 3. Bubble\n");
	scanf("%d",&ch);
	
	if(ch == 1)
		ins(arr,n);
	else if(ch == 2)
	    qs(arr,0,n);
	else if(ch == 3)
		bubble(arr,n);
	else
		printf("Wrong Input\n");
		
	printArray(arr,n);
}
