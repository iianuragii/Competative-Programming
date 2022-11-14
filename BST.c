#include <stdio.h>
#include <stdlib.h>
 
typedef struct list
{
    int val;
    struct list *left;
    struct list *right;
}node;

node *search(node *p,int x)
{
    if(p==NULL || p->val == x)
        return p;
    else if(p->val > x)
        return search(p->left,x);
    else
        return search(p->right,x);
}

node *move(node *p,int x)
{
    if(p->val > x)
    {
        if(p->left != NULL)
            return move(p->left,x);
        else
            return p;
    }
    else
    {
        if(p->right != NULL)
            return move(p->right,x);
        else
            return p;
    }
}

node *create(node *p,int x)
{
    node *q = (node*)malloc(sizeof(node));
    q->val = x;
    q->left = q->right = NULL;
    if(p == NULL)
    {
        p = q;
        return p;
    }
    else
    {
        node *temp = p;
        node *parent = move(p,x);
        if(parent ->val > x)
            parent->left = q;
        else
            parent ->right = q;
        return temp;
    }
}

node *min(node *p)
{
    if(p == NULL || p->left == NULL)
        return p;
    else
        return min(p->left);
}
        
node *del(node *p, int x)
{
    if(p == NULL)
        return p;
    else if(p->val > x)
        p->left = del(p->left,x);
    else if(p->val < x)
        p->right = del(p->right,x);
    else
    {
        if(p->left == NULL)
        {
            node *temp = p->right;
            free(p);
            return temp;
        }
        else if(p->right == NULL)
        {
            node *temp = p->left;
            free(p);
            return temp;
        }
        else
        {
            node *temp = min(p->right);
            p->val = temp->val;
            p->right = del(p->right,temp->val);
        }
    }
    return p;
}

void preorder(node *p)
{
    if(p)
    {
        printf("%4d \t",p->val);
        preorder(p->left);
        preorder(p->right);
    }
}

void main()
{
    node *p = NULL, *q = NULL;
    int a,ch = 0,i,n = 0,item = 0;
    while(ch != 6)
    {
        printf("1.Create\n 2.Insert\n 3.Searching\n 4.Delete\n 5.preOrder Display\n 6.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Size?\n");
                    scanf("%d",&n);
                    for(i = 0; i < n;i++)
                    {
                        printf("Enter the elements\n");
                        scanf("%d",&item);
                        p = create(p,item);
                    }
                    break;
            case 2: printf("Enter the element to be inserted\n");
                    scanf("%d",&item);
                    p = create(p,item);
                    break;
            case 3: printf("Enter the element to be Searched\n");
                    scanf("%d",&item);
                    q = search(p,item);
                    if(q == NULL)
                        printf("Element not present\n");
                    else
                        printf("Element present\n");
                    break;
            case 4: printf("Enter the element to be deleted\n");
                    scanf("%d",&item);
                    del(p,item);
                    break;
            case 5: preorder(p);
                    break;
            case 6: break;
            default: printf("Wrong Choice!!\n");
        }
    }
}
