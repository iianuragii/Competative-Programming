#include<stdio.h>
int maxi(int,int);
int main()
{
    int T,A=0,B=0,x;
    printf("");
    scanf("%d",&T);
    if(T>=1 && T<=2500)
    {
        while(T>0)
        {
            printf("");
            scanf("%d %d",&A,&B);
            if(A==B)
                printf("YES");
            else
            {
                if(A>B)
                    x=maxi(B,A);
                else
                    x=maxi(A,B);
            if(x==1)
                printf("YES");
            else
                printf("NO");
            }
            T--;
            printf("\n");
        }
    }
}
int maxi(int p,int q)
{
    while(p<q)
    {
        p=p*2;
    }
    if(p==q)
        return 1;
    else
        return 0;
}