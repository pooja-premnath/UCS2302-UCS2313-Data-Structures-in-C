//single linked list implementation of stacks


#include <stdio.h>
#include <stdlib.h>
#include "dll.h"


//condition to check if stack is empty
int stack_empty(struct node*head){
	//printf("Top is %d\n", top->data);
	if (head==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void main(){
	struct node*head=NULL;
	struct node*temp=NULL;
	struct node*tail=NULL;

	int status=0;
	while (status==0){
		printf("\n1:Push Operations\n2:Pop Operations");
		int ch;
		printf("\nEnter your choice");
		scanf("%d",&ch);
		if (ch==1){
			printf("\nEnter the element to push");
			int ele;
			scanf("%d",&ele);
			

			if (head==NULL){
				head=tail=create_node(head,tail,ele);
			}
			else{
				tail=create_node(head,tail,ele);
				
			}

			printf("%d is pushed into the stack", ele);
		}

		else if (ch==2){
				if (stack_empty(head)==0){
					if (head->next==NULL){
						head=delete_at_tail(head,tail);
						
						tail=NULL;
						
					}


					else{
						tail= delete_at_tail(head,tail);
						
					}
					
				}
				else{
					printf("\nEmpty Stack");
				}
				
			
		}

		else{
			printf("Invalid Choice, try again");
		}

		printf("\nEnter 0 to continue stack operations");
		scanf("%d",&status);
	}
}