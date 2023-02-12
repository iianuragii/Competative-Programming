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
    if(l >= r)
        return ;
    int i = partition(arr,l,r);
    quicksort(arr,l,i-1);
    quicksort(arr,i+1,r);
}
int main()
{
    int i,j,n,length = 0,t = 0;
    FILE *ptr;
    FILE *p;
    ptr = fopen("Input.txt","w+");
    p = fopen("Output.txt","w+");
    printf("Enter the number of arrays you want:\n");
    scanf("%d",&n);
    printf("Enter the array length\n");
    scanf("%d",&length);
    int arr[length];
    for(j = 0;j < n;j++)
    {
        for(i = 0;i < length;i++)
        {fprintf(ptr,"%d\t",rand() % 1000);}
        fprintf(ptr,"\n");
    }
    fclose(ptr);
    ptr = fopen("Input.txt","r");
    for(j = 0;j < n;j++)
    {
        
        for(i = 0;i < length;i++)
            {fscanf(ptr,"%d",&arr[i]);}
       
        quicksort(arr,0,length - 1);
        
        for(i = 0;i < length;i++)
            {fprintf(p,"%d\t",arr[i]);}
        fprintf(p,"\n");
        t = t + k;
        fprintf(p,"The no. of comparisons are %d\n",k);
        fprintf(p,"\n");
        k = 0;
    }   
    fprintf(p,"Average case comparison = %f",(t*1.0)/n);
    fclose(ptr);
    fclose(p);
}


