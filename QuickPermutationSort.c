#include <stdio.h>
int k = 0;
void swap(int *i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
int partition(int *arr,int l,int r)
{
    int pivot = arr[r];
    int i =l;
    int j;
    for(j = l;j < r;j++)
    {
        k++;
        if(arr[j] < pivot)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[r]);
    return i;
}
void quicksort(int *arr,int l,int r)
{
    int i;
	if(l >= r)
        return ;
    i = partition(arr,l,r);
    quicksort(arr,l,i-1);
    quicksort(arr,i+1,r);
}
void permutation(int *arr,int size,int n,FILE *p)
{
    int i;
	if(n == 1)
    {
        filePrint(arr,size,p);
        return;
    }
    for(i = 0;i < n;i++)
    {
        permutation(arr,size,n - 1,p);
        if (n % 2 == 0)
            swap(arr+i,arr+n-1);
        else
            swap(arr,arr + n -1);        
    }
}
int fact(int n)
{
    int i,f = 1;
    for(i = 1;i <= n;i++)
        f = f * i;
    return f;
}
void filePrint(int arr[],int n,FILE *p1)
{
    int i;
    for(i = 0;i < n;i++)
        fprintf(p1,"%d\t",arr[i]);
    fprintf(p1,"\n");
}
void arrayPrint(int arr[],int n)
{
    int i;
    for(i = 0;i < n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}
int main()
{
    int i,j,n,len = 0,t = 0;
    FILE *ptr;
    FILE *p;
    p = fopen("Output.txt","w+");
    printf("Enter the array length:\n");
    scanf("%d",&n);
    len = fact(n);
    int arr[n];
    
    for(i = 0;i < n;i++)
        arr[i] = i + 1;
    
     ptr = fopen("Input.txt","w+");
    permutation(arr,n,n,ptr);
	fclose(ptr);
    ptr = fopen("Input.txt","r");
    fprintf(p,"Sorted Arrays:\n");
    for(j = 0;j < len;j++)
    {
        for(i = 0;i < n;i++)
            fscanf(ptr,"%d",&arr[i]);
        //printf("Unsorted Array:\n");
        for(i = 0;i < n;i++)
            printf("%d\t",arr[i]);
        printf("\n");
        quicksort(arr,0,n - 1);
        
        for(i = 0;i < n;i++)
            fprintf(p,"%d\t",arr[i]);
            fprintf(p,"\n");
        t = t + k;
        fprintf(p,"The no. of comparisons are %d\n",k);
        k = 0;
    }  
    printf("The avg no. of comparisons are: %f\n",(t*1.0)/len);
    fprintf(p,"The avg no. of comparisons are: %f\n",(t*1.0)/len);
    fclose(ptr);
    fclose(p);  
}


