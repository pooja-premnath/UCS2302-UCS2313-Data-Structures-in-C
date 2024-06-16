//searching for a node in the binary search tree


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


//searching for a particular node
int search(struct node*root, int node){
	while (root!=NULL){
		
		if(node> root->data){
			//traverse right sub tree
			root=root->right;
		}
		
		else if (node< root->data){
			//traverse left sub tree
			root=root->left;
		}

		else{
			//condition where the node is found
			return 1;		
		}
	}
	
	//when the node is not found
	return 0;
	
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
	printf("\nEnter the node to search for");
	scanf("%d", &search_node);
	int status=search(root, search_node);
	if (status==1){
		printf("\nNode found");
	}
	else{
		printf("\nNode not found");
	}
}