#include <stdio.h>
int main()
{
    int T,X=0,a=0;
    printf("");
    scanf("%d",&T);
    if(T>=1 && T<=30)
    {
        while(T>0)
        {
            printf("");
            scanf("%d",&X);
            if(X>=1 && X<=30)
            {
                a=2*X;
                printf("%d\n",a);
            }
            T--;
        }
    }
}
