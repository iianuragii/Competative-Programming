#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    if(num>=1 && num<=1000)
    {
        arr = (int*) malloc(num * sizeof(int));
        for(i = 0; i < num; i++)
        {   
            scanf("%d", arr + i);
        }
        for(i = num-1; i >=0; i--)
        {
            if(*(arr+i)>=1 && *(arr+i)<=1000)
            printf("%d ", *(arr + i));
        }
    }
    return 0;
}
