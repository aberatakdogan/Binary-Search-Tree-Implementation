#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BST
{
int data;
struct BST *left;
struct BST *right;
}node;

node *construct();
void insert(node *root,node *temp);
void inorder(node *root);
void findParent(node *node, int val, int parent);

int nodeVal;

char input[100];

int main()
{

node *root=NULL,*temp;


while(1)
{

scanf("%s",input);

if(strcmp(input,"LIST")==0)
{
   inorder(root);
   printf("\n");

}

if(strcmp(input,"CONSTRUCT")==0)
{

int numOfValues;

char c1;
scanf("%c",&c1);

if(scanf("%c",&c1)!='[' )
{


while(1)
{

temp=construct();

if((temp->data) < 1000 && (temp->data))
{
if(root==NULL){
root=temp;
//printf("%d,",root->data);
}
else if(root!=NULL){
insert(root,temp);
//printf("%d,",temp->data);
}
}
else
{
    break;
}

}


}


}
if(strcmp(input,"INSERT")==0)
{

    temp = construct();
    insert(root,temp);

  

    findParent(root,temp->data,-1);
    if(temp->data == root->data)
    {
        printf("It is a root node\n");
    }

}

if(strcmp(input,"PARENT")==0)
{

    scanf("%d",&nodeVal);
    findParent(root, nodeVal, -1);

    if(nodeVal == root->data)
    {
        printf("It is a root node\n");
    }
}

if(strcmp(input,"EXIT")==0)
{
    exit(0);
}


}

return 0;
}

void findParent(node *node, int val, int parent)
{
    if(node == NULL)
    {
        return;
    }


    if(node->data == val && parent!=-1)
    {
        printf("The parent of %d is %d\n",val,parent);
    }
    else
    {
        findParent(node->left,val,node->data);
        findParent(node->right, val, node->data);
    }


}

node *construct()
{

node *temp;

temp=(node*)malloc(sizeof(node));

scanf("%d,",&temp->data);

temp->left=temp->right=NULL;

return temp;
}



void insert(node *root,node *temp)
{
if((temp->data)<(root->data))
{
if(root->left!=NULL)
insert(root->left,temp);
else
root->left=temp;
}
if((temp->data)>(root->data))
{
if(root->right!=NULL)
insert(root->right,temp);
else
root->right=temp;
}

if((temp->data)==(root->data))
{
if(root->right!=NULL)
insert(root->right,temp);
else
root->right=temp;
}

}



void inorder(node *root)
{
if(root!=NULL && (root->data)!=0 )
{
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);

}
}
