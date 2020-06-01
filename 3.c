#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int x=0,space=0;

struct node
{
    char str[50];
    struct node *left;
    struct node *right;
}*root;

struct node *avl(struct node *temp,struct node *leaf)
{
    if(strcmpi(temp->str,leaf->str)>0)
    {
        if(temp->left == NULL)
        {
            temp->left = leaf;
        }
        else
        {
            avl(temp->left,leaf);
        }
    }
    if(strcmpi(temp->str,leaf->str)<0)
    {
        if(temp->right == NULL)
        {
            temp->right = leaf;
        }
        else
        {
            avl(temp->right,leaf);
        }
    }

}

struct node *create(char arr[])
{
    struct node *leaf;
    leaf=(struct node*)malloc(sizeof(struct node));
    strcpy(leaf->str,arr);
    leaf->left=NULL;
    leaf->right=NULL;
    avl(root,leaf);
}

struct node *traverse(struct node *leaf)
{
    int i;
    if(leaf!=NULL)
    {
        if(x!=0)
        {
            space++;
            printf("\n");
            for(i=0;i<space;i++)
            {
                printf("    ");
            }
            printf ("Child data = %s and space = %d",leaf->str,space);
        }
        x++;
        traverse(leaf->left);
        leaf=leaf->right;
    }
    if(leaf!=NULL)
    {
        printf("\n");
        for(i=0;i<space;i++)
        {
            printf("    ");
        }
        printf ("Child data = %s and space = %d",leaf->str,space);
        traverse(leaf->left);
        space--;
        traverse(leaf->right);
    }
}

int main()
{


    root=(struct node*)malloc(sizeof(struct node));
    strcpy(root->str,"Arthi");
    root->left=NULL;
    root->right=NULL;
    create("Christy");
    create("Dorothy");
    create("Fraser");
    create("Eliza");
    printf("\n Root node = %s",root->str);
    traverse(root);
    x=0,space=0;
    create("David");
    printf("\n Root node = %s",root->str);
    traverse(root);
}
