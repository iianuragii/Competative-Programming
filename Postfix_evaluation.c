#include <stdio.h>
#include <ctype.h>

#define N 100 

int stack[N];
int top = -1;
int flag = 0; 
void push(int x)
{
	
    if (top == N - 1) 
        printf("stack overflow\n");
    else 
	{
        top++;
        stack[top] = x;
    }
}

int isAlphabet(char a)
{
	int x;
	if((int)a >= 97 && (int)a <= 122)
	{
		printf("Enter the value of the variable in stack:\n");
		scanf("%d",&x);
		push(x);
		return 1;
	}
	return 0;
}


int pop()
{
    int item;
    if (top == -1)
        printf("stack underflow\n");
    else 
	{
        item = stack[top];
        top--;
    }
    return item;
}

void disp()
{
	int i;
	if(top == -1)
		printf("Stack underflow\n");
	else
	{
		for(i = 0;i <= top;i++)
			printf("%d\t",stack[top]);
	}
}
  
int main()
{
	int i;
    char exp[20];
   	char *e;
   	int n1,n2,n3,num;
   	
   	printf("Enter the expression\n");
   	scanf("%s",exp);
   	e = exp;

    while(*e != '\0')
    {
    	if(isAlphabet(*e) == 0)
    	{
    		n1 = pop();
            n2 = pop();

            switch(*e)
            {
	            case '*':
	                n3 = n1 * n2;
	                break;
		
	            case '+':
	                n3 = n1 + n2;
	                break;
	
	            case '-':
	               n3 = n2 - n1;
	                break;
	                
	            case '/':
	            	if(n1 == 0)
	            	{
	            		printf("Invalid\n");
	            		printf("Re-enter n1\n");
	            		scanf("%d",&n1);
					}
	                n3 = n2 / n1;
	                break;
			}
            push(n3);
        }
        e++;
    }
    printf("Result : %d \n", pop());
    return 0;
}
	
