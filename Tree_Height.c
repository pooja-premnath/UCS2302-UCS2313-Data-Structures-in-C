#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node*left, *right;
};


struct node*create_root(struct node*root, int data){
	root=(struct node*)malloc(sizeof(struct node));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}

void insert_node(struct node*root, int data){
	struct node*newnode;
	if (data<root->data){
		if(root->left==NULL){
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->data=data;
			newnode->left=NULL;
			newnode->right=NULL;
			root->left=newnode;
		}

		else{
			insert_node(root->left,data);
		}

	}

	else{
		if(root->right==NULL){
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->data=data;
			newnode->left=NULL;
			newnode->right=NULL;
			root->right=newnode;
		}

		else{
			insert_node(root->right,data);
		}

	}

}


struct node*construct_tree(struct node*root, int data){
	if(root==NULL){
		root=create_root(root,data);
	}

	else{
		insert_node(root,data);
	}

	return root;

}

void inorder(struct node*root){
	if(root->left!=NULL){
	
		inorder(root->left);
		
		
	}
	printf(" %d",root->data);
	
	if(root->right!=NULL){
		inorder(root->right);
		
	}
}


int height(struct node*root){
	int lh=0;
	int rh=0;


	//condition for a leaf node
	if (root->right== NULL && root ->left ==NULL){
		return 1;
	}



	//queries sent to children, the height function is called on the child node
	if (root->left !=NULL){
		//printf("\n %d Has a left child", root->data);
		lh=height(root->left);
	}


	if (root->right!=NULL){
		//printf("\n %d Has a right child", root->data);
		rh=height(root->right);
	}
	


	//every time a child node is explored, 1+ the max(lh,rh) is returned
	if(lh<rh){
		//printf("\nRight subtree's height: %d", rh);
		//printf("\n lh %d returned", lh);
		return 1+rh;
	}

	else{
		//printf("\nLeft subtree's height: %d", lh);
		//printf("\n rh %d returned",rh);
		return 1+ lh;
	}

}



void main(){
	struct node*root= NULL;
	int data;
	int i,n;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		printf("Enter the value of the node");
		scanf("%d",&data);
		root=construct_tree(root,data);
	}
	printf("\nInorder: ");
	inorder(root);
	printf("\nThe height of the tree is %d", height(root));
	
	
}