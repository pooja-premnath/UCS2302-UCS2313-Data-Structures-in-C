#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node*prev;
};


void print_from_head(struct node*head);
void print_from_tail(struct node*tail);


struct node*create_node(struct node*head,struct node*tail,int num){
	struct node*temp=tail;
	if (head==NULL){
			
	
			//allocate memory for head
			head=(struct node*)malloc(sizeof(struct node));
			
			//head and temp are the same, make temp point to head
			temp=head;

			//assign values to temp
			temp->data=num;

			//make the previous half of head point of null

			temp->prev=NULL;

			//assign second half of temp to null
			temp->next=NULL;
			tail=temp;
				
			
		}


		//to add other nodes
		else{
			
			//assign memory for temp->next where there is currently NULL
			temp->next=(struct node*)malloc(sizeof(struct node));
			


			//establish a backward link
			temp->next->prev=temp;
			
			//move temp to the next block, where the value will be held
			temp=temp->next;

			temp->data=num;

			//make the next block null
			temp->next=NULL;
			tail=temp;
			
		}
		temp->next=NULL;
		tail=temp;
		return temp;
	}


void print_from_tail(struct node*tail){
	static struct node*temp;
	for (temp=tail;temp!=NULL;temp=temp->prev){
		printf(" %d ->",temp->data);
	}
	if (temp==NULL){
		printf(" NULL");
	}
}



void print_from_head(struct node*head){
		static struct node*temp;
		temp=head;
		//printf("head inside function is %d", temp->data);
		for (temp=head;temp!=NULL;temp=temp->next){
			printf(" %d ->",temp->data);
		}
		if (temp==NULL){
			printf(" NULL");
		}

}


void insert_at_pos(struct node*head, int pos, int val){
		struct node*newnode;
		struct node*temp=head;
		int i=0;
		for (temp=head;temp!=NULL;temp=temp->next){
			//printf("\ni: %d",i);
			if (i==pos-1){
				
				break;	
			}
			i++;
		}
		
		//allocate memory for the newnode
		newnode=(struct node*)malloc(sizeof(struct node));

		//assign values
		newnode->data=val;
	

		//make the last part of newnode point to the next node
		newnode->next=temp->next;


		//establish the backward link by connecting the next node's previous part to newnode
		newnode->next->prev=newnode;
		
		//connect the second half of temp to newnode;
		temp->next=newnode;

		//connect the back half of newnode to temp
		newnode->prev=temp;
	

}

struct node* insert_at_tail(struct node*tail,int val){
		struct node* newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=val;
		newnode->next=NULL;


		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
		
		return tail;

}

struct node* insert_at_head(struct node* head, int val){
		struct node* newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=val;
		newnode->prev=NULL;
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
		return head;

}


void delete_at_pos(struct node*head, int pos){
		int i=0;
		struct node*temp=head;
		for (i=0;i<pos;i++){
			temp=temp->next;
		}
		
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);

}



struct node* delete_at_tail(struct node*tail){
		struct node*temp;
		tail->prev->next=NULL;
		temp=tail;
		tail=tail->prev;
		free(temp);

	return tail;

}


struct node* delete_at_head(struct node*head){
	struct node*temp;
	head->next->prev=NULL;
	temp=head;
	head=head->next;
	free(temp);
	return head;

}


void search(struct node*head,int val){
		int flag=0;
		
		struct node*temp=head;
		for (temp=head;temp!=NULL;temp=temp->next){
			if(temp->data ==val){	
				flag=1;
				break;
			}
		}
		if (flag==1){
			printf("\nElement found");
		}
		else{
			printf("\nElement not found");
		}
}

void main(){	
	struct node* head=NULL;
	int status=0;
	int num=0;
	int pos;
	struct node *temp=NULL;
	struct node*tail=NULL;

	while (status==0){
		int ch;
		printf("\n1:Create doubly linked list\n2:Print from head\n3:Print from tail\n4:Insertion at the head\n5:Insertion at a position\n6:Insertion at the tail\n7:Deletion at the head\n8:Deletion at a position\n9:Deletion at the tail\n10:Search");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		if (ch==1){

			printf("\nCreation of a doubly linked list");
			printf("\nEnter the number");
			scanf("%d",&num);
			if (head==NULL){
				head=tail=create_node(head,tail,num);
				printf("\nThe doubly linked list is\n");
				print_from_head(head);
			}
			else{
				tail=create_node(head,tail,num);
				printf("\nThe doubly linked list is\n");
				print_from_head(head);
			}
		}
		
		else if (ch==2){
			printf("\nPrinting a doubly linked list from the head");
			printf("\nHead: %d", head->data);
			printf("\nThe doubly linked list is:\n");
			print_from_head(head);
		}

		else if (ch==3){
			printf("\nPrinting a doubly linked list from the tail");
			printf("\nTail: %d", tail->data);
			printf("\nThe doubly linked list is:\n");
			print_from_tail(tail);
		}


		else if(ch==4){
			printf("\nInsertion at the head");
			printf("\nEnter the number to insert");
			scanf("%d",&num);
			head=insert_at_head(head,num);
			printf("\nThe linked list is:\n");
			print_from_head(head);
		 }

		else if(ch==5){
			printf("\nInsertion in the middle");
			printf("\nEnter the number to insert");
			scanf("%d",&num);
			
			printf("\nEnter the position to insert the number");
			scanf("%d",&pos);
			insert_at_pos(head,pos,num);
			printf("\nThe linked list is:\n");
			print_from_head(head);
		}

		else if (ch==6){
			printf("\nInsertion at the tail");
			printf("\nEnter the number to insert");
			scanf("%d",&num);
			tail=insert_at_tail(tail,num);
			printf("\nThe linked list is:\n");
			print_from_head(head);
		}


		else if( ch==7){
			printf("\nDeletion at the head");
			head=delete_at_head(head);
			printf("\nThe linked list is:\n");
			print_from_head(head);
		}

		else if(ch==8){
			printf("\nDeletion at a position");
			printf("\nEnter the position to delete an element at");
			
			scanf("%d",&pos);
			delete_at_pos(head,pos);
			printf("\nThe linked list is:\n");
			print_from_head(head);
		}

		else if(ch==9){
			printf("Deletion at the tail");
			tail= delete_at_tail(tail);
			printf("\nThe linked list is:\n");
			print_from_head(head);
		
		}

		else if (ch==10){
			printf("\nSearching for an element");
			printf("\nEnter the searching element");
			int ele;
			scanf("%d",&ele);
			search(head,ele);
		}

		else{
			printf("\nInvalid Choice...try again");
		}
		printf("\nEnter 0 to continue operations");
		scanf("%d", &status);		
	
	}
	
}