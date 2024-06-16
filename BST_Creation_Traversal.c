#include <stdio.h>
#include <stdlib.h>


//structure of a node
struct node{
	int data;
	struct node*left;
	struct node*right;

};

//function to create the root node
struct node*create_root(struct node*root,int data){
	

	//assign memory for the root
	root=(struct node*)malloc(sizeof(struct node));

	//assign values
	root->data= data;
	
	//initialize left and right side of the root to null
	root->left=NULL;
	root->right=NULL;

	return root;
		

}


//function to add nodes
void insert_node(struct node*root, int data){
	struct node* newnode;
	
	//when the entered data is lesser than that root node
	if (data< root-> data){
		
		//when the node to the left is free;
		if (root->left == NULL){
			newnode=(struct node*)malloc(sizeof(struct node));
			

			//assigning a value to the new node
			newnode->data= data;
			newnode->left= NULL;
			newnode->right=NULL;

			//making root's left point to the new node
			root->left=newnode;
			
		}



		//on the condition that the left node is not free, recursively traverse, until a left node is found
		else{
			insert_node(root->left,data);
		}
		
	}


	else{
		//if the node on the right is free
		if (root->right == NULL){
			newnode=(struct node*)malloc(sizeof(struct node));
			

			//assigning a value to the new node
			newnode->data= data;
			newnode->left= NULL;
			newnode->right=NULL;

			//making root's left point to the new node
			root->right=newnode;
			
		}



		//on the condition that the right node is not free, recursively traverse, until a right node is found
		else{
			insert_node(root->right,data);
		}
	}


}


//function to construct the tree
struct node*construct_tree(struct node*root, int data){
	if (root ==NULL){
		root=create_root(root,data);
	}
	
	else{
		insert_node(root,data);
	}

	return root;
}



//displaying the tree


//inorder traversal

void inorder(struct node*root){
	if (root->left!=NULL){
		inorder(root->left);
	}
	
	printf(" %d ", root->data);

	if (root->right != NULL){
		inorder(root->right);
	}

}


//preorder traversal

void preorder(struct node*root){

	printf(" %d ", root->data);


	if (root->left!=NULL){
		preorder(root->left);
	}
	
	

	if (root->right != NULL){
		preorder(root->right);
	}

}



//postorder traversal
void postorder(struct node*root){

	


	if (root->left!=NULL){
		postorder(root->left);
	}
	
	

	if (root->right != NULL){
		postorder(root->right);
	}

	printf(" %d ", root->data);

}



void main(){
	struct node*root=NULL;
	int n;
	int node;
	printf("Enter the number of nodes");
	scanf("%d",&n);

	for (int i=0;i<n;i++){
		printf("\nEnter the node value");
		scanf("%d",&node);
		root=construct_tree(root,node);
	}

	printf("\n Inorder Traversal\n");
	inorder(root);

	printf("\n Preorder Traversal\n");
	preorder(root);

	printf("\n Postorder Traversal\n");
	postorder(root);
}