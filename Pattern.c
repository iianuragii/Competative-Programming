#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a, int b){
    return a>b?a:b;
}
int main() 
{
    int n;
    scanf("%d", &n);
      // Complete the code to print the pattern.
    int i = 0, j = 0;
    for(i = 1; i<=2*n-1; i++){
        for(j = 1; j<=2*n-1; j++){
            printf("%d ",(max(max(i,2*n-i),max(j,2*n-j))-n)+1);
        }
        printf("\n");
    }
    return 0;
}
