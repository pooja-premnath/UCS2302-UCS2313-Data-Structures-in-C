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


struct node* inorder_predecessor(struct node* root, int node){
	struct node*current=root;
	struct node*pred=NULL;
	
	//finding the node in the BST
	while (current->data != node){
		if (current->data > node){
			current=current->left;
		}

		else{
			current=current->right;
		}	
	}


	//case 1: if the given node has a left subtree
	// the inorder predecessor= righmost node of left subtree

	if (current->left !=NULL){
		pred=current->left;
		while(pred->right !=NULL){
			pred=pred->right;
		}

		return pred;
	}


	//case 2: when there is no left sub tree
	//the inorder predecessor is in the ancestor nodes (node from which the last right is taken)
	
	current=root;
	
	while (current->data!=node){
		if(node > current->data){
			pred=current;
			current=current->right;
		}
		else{
			current=current->left;
		}
	}

	return pred;
	
}


struct node* inorder_successor(struct node*root, int node){
	struct node*current=root;
	struct node*successor=NULL;
	
	//finding the node in the BST
	while (current->data != node){
		if (current->data > node){
			current=current->left;
		}

		else{
			current=current->right;
		}	
	}


	//case 1: if the node has a right subtree
	//inorder successor is the leftmost node of right subtree 
	if (current->right !=NULL){
		successor=current->right;
		while(successor->left!=NULL){
			successor=successor->left;
		}


		return successor;
	}
	
	

	//case 2: if the node has no right subtree
	//inorder successor is in the ancestor nodes(node from which the last left is taken)
	
	current=root;
	while(current->data !=node){
		if (node <= current->data){
			successor=current;
			current=current->left;
		}
		else{
			current=current->right;
		}
	}
	
	return successor;
	
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
	printf("\nEnter the node to find the inorder predecessor of");
	int node;
	scanf("%d", &node);
	struct node* val=inorder_predecessor(root,node);
	if (val!=NULL){
		printf("\nInorder predecessor: %d", val->data);
	}
	else{
		printf("\nNo inorder predecessor");
	}

	printf("\nEnter the node to find the inorder successor of");
	scanf("%d",&node);
	val=inorder_successor(root,node);
	if (val!=NULL){
		printf("\nInorder successor: %d", val->data);
	}
	else{
		printf("\nNo inorder successor");
	}
}
		