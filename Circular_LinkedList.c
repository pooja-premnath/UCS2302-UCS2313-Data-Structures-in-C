//Circular Linked List

#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node* next;
};


//NODE CREATION

struct node* create_node(int val){
	static struct node*temp;
	static struct node*head=NULL;


	//if the list is empty
	if (head==NULL){
		
		//allocate memory for the head
		head=(struct node*)malloc(sizeof(struct node));
		

		//temp and head are the same
		temp=head;

		//add a value to first half of head
		temp->data=val;

		//initialize the second half of head to itself
		temp->next=NULL;
	}


	else{
		
		//allocate memory for temp
		temp->next=(struct node*)malloc(sizeof(struct node));
		

		//move the pointer to the next location
		temp=temp->next;

		//add value to the first part of temp;
		temp->data=val;

		
		//initialize the second half of temp to NULL
		temp->next=NULL;
	}

	//establish the looping 
	temp->next=head;
	return head;
}


//DISPLAYING THE CIRCULAR LINKED LIST

void display(struct node*head){

	struct node*temp;
	int loops=0;
	for (temp=head;loops<3;temp=temp->next){
		printf("%d ->", temp->data);

		if (temp->next == head){
			printf(" 	");
			loops++;
		}
	}
}



//INSERTION AT THE BEGINNING/ENDING OF THE LIST

struct node* insert_at_beg(struct node*head ,int val){
	struct node*temp=head;

	//allocate memory 
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	

	//put in values
	newnode->data=val;

	//make newnode point to head
	newnode->next=head;

	//iterate until the node just before the head node
	for (temp=head->next;temp->next!=head;temp=temp->next);
	

	//after reaching the penultimate node, make that point to newnode
	temp->next=newnode;

	//reallocate head
	head=newnode;

	//return the head
	return head;
}


//INSERTION IN THE MIDDLE

struct node* insert_at_pos(struct node*head, int val, int pos){
	struct node*temp;
	struct node* newnode;
	int i;
	temp=head;
	for (i=0;i<pos-1;i++){
		if (temp->next!=NULL){
			temp=temp->next;
		}
	}

	//assign values to newnode
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=temp->next;

	//make temp pointer point to newnode
	temp->next=newnode;
	return head;
}


//DELETION AT THE BEGINNING/ENDING OF THE LIST

struct node* delete_at_beg(struct node* head){
	
	struct node*temp=head;
	
	//mark node to be deleted
	struct node*delnode=head;

	//move the head pointer to the next pos
	head=head->next;

	//iterate around till the next node is the one to be deleted
	for (temp=head; temp->next!=delnode;temp=temp->next);

	//point temp to the new head
	temp->next=head;

	//free memory
	free(delnode);

	return head;
}


//DELETION IN THE MIDDLE 
struct node* delete_at_pos(struct node*head, int pos){
	int i=0;
	struct node*temp=head;
	struct node*remove=NULL;
	for (i=0;i<pos-1;i++){
		temp=temp->next;
	}

	remove=temp->next; //remove is the node to be deleted
	temp->next=temp->next->next;
	free(remove);
	return head;
}


//SEARCHING FOR A NODE
void search_node(struct node*head, int val){
		struct node *temp;
		int i=1;
		int flag=0;
		temp=head;
		if (temp->data==val){
			
			flag=1;
			temp=temp->next;
			
		}
		
	
		else{
			temp=temp->next;
			while (temp!=head){
				
				if (temp->data==val){
					flag=1;
				}

				temp=temp->next;
			}
		}

		if (flag==0){
			printf("\nElement not found");
		}
		else{
			printf("\nElement found");
		}
		



}

void main(){
	static struct node*head=NULL;
	int status=0;
	int num;
	int ch;
	int updated_head;
	int pos;
	int ele;
	int search;
	while (status==0){
		printf("1: Creation of a node\n2: Add node at the beginning/end\n3: Insert in the middle of list\n4: Delete at the beginning/end\n5: Delete in the middle of the list\n6: Display circular linked list\n7: Search for an element");
		
		printf("\nEnter your choice:");
		scanf("%d", &ch);
		if (ch==1){
			printf("Creation of a node");
			printf("\nEnter an element");
			scanf("%d", &num);
			head=create_node(num);
			display(head);
			printf("\n");
			}

		else if (ch==2){
			printf("\nAddition of a node at the beginning/end");
			printf("\nEnter the node to insert at the beginning");
			scanf("%d",&updated_head);
			head=insert_at_beg(head,updated_head);
			display(head);
			printf("\n");
		}

		
		else if (ch==3){
			printf("\nInsert in the middle of the list");
			printf("\nEnter the element to insert");
			scanf("%d",&ele);
			printf("Enter the position to insert the element");
			scanf("%d",&pos);
			head=insert_at_pos(head,ele,pos);	
			display(head);
			printf("\n");
		}
	
		else if (ch==4){
			printf("\nDeletion at the beginning/end");
			head=delete_at_beg(head);
			display(head);
			printf("\n");
		}

		else if (ch==5){
			printf("\nDeletion in the middle");
			printf("\nEnter the position to delete the element from");
			scanf("%d",&pos);
			head=delete_at_pos(head,pos);
			printf("\n");
			display(head);
			printf("\n");
			}



		else if (ch==6){
			if (head==NULL){
				printf("\nNo elements in the list as of now");
			}

			else{
				printf("Displaying the circular linked list");
				display(head);
			}
		}


		else if (ch==7){
			printf("\nEnter the searching element");
			scanf("%d",&search);
			search_node(head, search);
		}



		else{
			printf("Invalid Choice");
		}
			
			
		printf("\n");
		printf("\nEnter 0 to continue operations");
		scanf("%d", &status);
	
	}

}