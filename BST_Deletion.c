//deletion of a node in a BST




#include <stdio.h>
#include <stdlib.h>



//tree structure
struct node{	
	int data;
	struct node*left;
	struct node*right;
};




//insertion of other nodes in the tree
void insert_node(struct node* root,int data){
		struct node*newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		
		//addition on the left hand side
		if(data<root->data){
			
			//check if the node is free
			if (root->left ==NULL){
				newnode->data=data;
				newnode->left=NULL;
				newnode->right=NULL;
				root->left=newnode;
			}

			//if the left node is not free, recursively traverse until a left node is free		
			else{
				insert_node(root->left, data);
			}
	
		}


		//addition on the right hand side
		else{
			
			//check if the node is free
			if (root->right ==NULL){
				newnode->data=data;
				newnode->left=NULL;
				newnode->right=NULL;
				root->right=newnode;
			}

			//if the right node is not free, recursively traverse until a right node is free		
			else{
				insert_node(root->right, data);
			}
	

		}
}


//inorder traversal of the tree
void inorder(struct node* root){
	if(root->left !=NULL){
		inorder(root->left);
	}

	printf(" %d ", root->data);

	if(root->right !=NULL){
		inorder(root->right);
	}


}


//creation of the root node
struct node* create_root(struct node* root, int data){
		root=(struct node*)malloc(sizeof(struct node));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
}



//construct tree
struct node* construct_tree(struct node* root,int data){
		if(root==NULL){
			root=create_root(root,data);

		}


		else{
			insert_node(root,data);
		}

		
		return root;
}


struct node*pred(struct node*root){	
	while (root->left != NULL){
		root=root->left;
		
	}
	return root;
}

struct node* delete_node(struct node*root, int data){

	//("\n %d", base->data);
	if (root==NULL){
		return root;
	}

	//to limit operations to the left sub tree
	else if (data < root->data){
		root->left=delete_node(root->left,data);
	}


	//to limit operations to the right sub tree
	else if (data > root->data){
		root->right= delete_node(root->right, data);
	
	}

	//once the node to be deleted has been identified, the following cases are to be considered

	else{
		
		//Case 1: when there is no child
		if (root->left ==NULL && root->right ==NULL){
			free(root);
			//printf(" \n root has been freed");
			root=NULL;
		}	


		//Case 2: when there is one child
		else if (root->left ==NULL){

			struct node*temp=root;
			root=root->right;
			free(temp);
		}	

		else if (root->right ==NULL){
			struct node*temp=root;
			root=root->left;
			free(temp);
		}

		//Case 3: When there are two children
		else{
			struct node*temp=pred(root->right);
			root->data=temp->data;
			root->right=delete_node(root->right,temp->data);
		}
	}

	return root;
}



void main(){
	int arr[100];
	int n;
	int data;
	int search_node;
	struct node*root= NULL;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		printf("Enter the value of the node");
		scanf("%d",&data);
		root=construct_tree(root,data);
	}
	

	printf("Inorder Traversal");
	inorder(root);
	
	int delnode;
	printf("\n");
	printf("\nEnter the node to be deleted");
	scanf("%d", & delnode);
	
	printf("\n");
	struct node*temp=delete_node(root, delnode);
	
	printf("\n");
	printf("Tree after deletion of node  ");
	inorder(root);
	
}
		