#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    struct tree*left;
    struct tree*right;
}tree;
tree*search(tree*root,int key)
{
    if(root==NULL||root->data==key)
    {
        return root;
    }
    if(key<root->data)
    {
        return search(root->left,key);
    }
    return search(root->right,key);
}
tree *createnode(int data)
{
    tree*nn=(tree*)malloc(sizeof( tree));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
tree *insert(tree*root,int data)
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
void inorder(tree*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(tree*root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        
        preorder(root->right);
    }
}
void postorder(tree*root)
{
    if(root!=NULL)
    {
       
        postorder(root->left);
        
        postorder(root->right);
         printf("%d ",root->data);
    }
}

int main()
{
    
        tree*root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    printf("Inorder Travesal:");
    inorder(root);
    printf("\n");
    printf("preorder Travesal:");
    preorder(root);
     printf("\n");
    printf("postorder Travesal:");
    postorder(root);
    int key;
    printf("\nEnter element to search: ");
     scanf("%d", &key);

      tree *result = search(root, key);

   if (result != NULL)
      {
    printf("%d found in BST\n", key);
     }
    else
       {
    printf("%d not found in BST\n", key);
     }
    
}
