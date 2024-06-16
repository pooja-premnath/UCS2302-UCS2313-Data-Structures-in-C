#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct node{
	char data;
	struct node*next;
	struct node*prev;
};

struct node*createnode(struct node*head, struct node*tail, char num){
	static struct node*temp;
	if (head==NULL){
		head=(struct node*)malloc(sizeof(struct node));
		
		//temp and head are the same
		temp=head;
	
		//assign values
		temp->data=num;

		//since it is the first node, make head's previous NULL
		temp->prev=NULL;

		//initialize the pointer to the next node as null
		temp->next=NULL;	
	}


	else{
		//initialize memory for the next node
		temp->next=(struct node*)malloc(sizeof(struct node));
		
		//establish the backward link
		temp->next->prev=temp;

		//move temp pointer to the new node
		temp=temp->next;


		temp->data=num;

		//assign the next block as null
		temp->next=NULL;
	}
	temp->next=NULL;
	tail=temp;
	return temp;

}

void displayfromhead(struct node*head){
	struct node*temp;
	for (temp=head;temp!=NULL;temp=temp->next){
		printf("%c",temp->data);
	
	}
}


struct node* delete_dollar(struct node*head, int ind){
	struct node*temp;
	struct node*delnode;
	int pos=0;
	temp=head;
	while (pos< ind-1){
		temp=temp->next;
		pos++;
	}
	delnode=temp->next;
	temp->next=delnode->next;
	delnode->next->prev=temp;
	free(delnode);
	return head;
}
void main(){
	struct node*head= NULL;
	char num;
	int ind;
	struct node*temp;
	struct node*tail;
	int status;
	int pos=0;
	char exp[100];
	printf("Enter an expression");
	scanf(" %s", exp);
	printf("\nThe expression entered is %s\n", exp);
	int i=0;
	while (exp[i] != '\0'){
		if (head==NULL){
			head=createnode(head, tail, exp[i]);
			//displayfromhead(head);
			//printf("\n");
			
		
		}
		else{
			tail=createnode(head, tail, exp[i]);
			//displayfromhead(head);
			//printf("\n");
		}

		
		if (exp[i] =='$'){
			ind=i;
			
		}
		i++;
		
	}
	
	printf("The $ sign is at position %d", ind);

	head=delete_dollar(head,ind);
	head=delete_dollar(head,ind-1);
	printf("\n");
	displayfromhead(head);

}

