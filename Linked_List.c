#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};



struct node* create(int val){
	static struct node *head=NULL;
	static struct node *temp;
	if (head==NULL){
			
			//allocate memory for head
			head=(struct node*)malloc(sizeof(struct node));
			
			//head and temp are the same, make temp point to head
			temp=head;

			//assign values to temp
			temp->data=val;

			//assign second half of temp to null
			temp->next=NULL;
		}


		//to add other nodes
		else{
			//assign memory for temp->next where there is currently NULL
			temp->next=(struct node*)malloc(sizeof(struct node));
			
			//move temp to the next block, where the value will be held
			temp=temp->next;

			temp->data=val;

			//make the next block null
			temp->next=NULL;
		}
		temp->next=NULL;
		return head;
}


void display(struct node* head){
	struct node*temp;
	for (temp=head; temp!=NULL; temp=temp->next){
		printf(" %d ->",temp->data);
	}

	if (temp==NULL){
		printf(" NULL");
	}

	printf("\n");
}


struct node* insert_at_head(struct node* head,int val){
	
	static struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=head;
	head=temp;
	return head;
}


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


struct node* insert_at_end(struct node*head, int val){
	printf("inside end fn");
	struct node* temp;
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;


	temp=head;
	for (temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=newnode;
	return head;
}


struct node* delete_at_beg(struct node*head){
	struct node*temp;
	temp=head;
	head=head->next;
	free(temp);
	return head;
}


struct node* delete_at_end(struct node*head){
	struct node*temp;
	printf("inside fn\n");
	if (head->next==NULL){
		head=NULL;
	}
	else{
		for(temp=head;(temp->next)->next!=NULL;temp=temp->next);
		temp->next=NULL;
	}

	return head;
}


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


struct node* search(struct node* head, int val){
	struct node*temp=head;
	int pos=0;
	int flag=0;
	while (temp!=NULL){
		if(temp->data==val){
			flag=1;
			break;

		}
		else{
			temp=temp->next;
		}

		pos++;

	}

	if (flag==1){
		printf("Found at %d", pos);
	}

	else{
		printf("Node not found");
	}

	return head;
}

void main(){;
	static struct node* head=NULL;
	int status=0;
	int num=0;
	while (status==0){
	
		printf("Enter a number");
		scanf("%d", &num);	
		head=create(num);
		display(head);
		printf("Enter 0 to continue operations");
		scanf("%d", &status);	
	}
	

	//inserting at the head
	/*head=insert_at_head(head,3);
	display(head);
	head=insert_at_head(head,-100);
	display(head);*/


	//inserting at a position
	/*insert_at_pos(head,1000,2);
	display(head);*/


	//inserting at the end
	/*insert_at_end(head, 4000);
	display(head);*/


	/*head=delete_at_beg(head);
	display(head);*/

	/*head=delete_at_end(head);
	display(head);*/


	/*head=delete_at_pos(head,3);
	display(head);*/


	//head=search(head,3);
}