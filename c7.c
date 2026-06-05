#include <stdio.h>
#include<stdlib.h>
typedef struct tree
{
     int data;
     struct tree*left;
     struct tree*right;
}tree;
tree *createnode(int data)
{
    tree*nn=(tree*)malloc(sizeof(tree));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    
    return nn;
}
tree*insert(tree*root,int data)
{
     if(root==NULL)
     {
         return createnode(data);
     }
     if(data<root->data)
     {
         root->left=insert(root->left,data);
         
     }
     else
     {
          root->right=insert(root->right,data);
     }
     return root;
}
tree*minvalue(tree*root)
{
    while( root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
tree*delete(tree*root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key<root->data)
    {
        root->left=delete(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=delete(root->right,key);
    }
    else
    {
         if(root->left==NULL && root->right==NULL)
         {
             free(root);
             return NULL;
             
         }
         if(root->left==NULL)
         {
             tree*temp=root->right;
             free(root);
             return temp;
         }
         if(root->right==NULL)
         {
               tree*temp=root->left;
               free(root);
               return temp;
         }
        tree* temp = minvalue(root->right);
         root->data=temp->data;
         root->right=delete(root->right,temp->data);
         
    }
    return root;
}
void inorder(tree*root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
    }
}

int main()
{
    tree*root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,60);
    insert(root,70);
    insert(root,35);
    printf("Bfore deletion");
    inorder(root);
   root= delete(root,50);
    printf("\nAfter deletion");
    inorder(root);

    return 0;
}
