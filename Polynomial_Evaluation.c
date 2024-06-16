//polynomial addition using linked lists

#include <stdio.h>
#include <stdlib.h>


//struct definition

struct node{
	int coeff;
	int power;
	struct node*next;
};


//node creation
struct node* create (int coefficient, int pow,struct node*head){
	//static struct node*head;
	static struct node*temp;

	//to add the first node
	if (head==NULL){
		
		//allocate memory for the head
		head=(struct node*) malloc(sizeof(struct node));
		
		//temp and head are the same
		temp=head;

		//assign values
		temp->coeff=coefficient;
		
		
		temp->power=pow;
		
		//assign the last block of temp to null
		temp->next=NULL;

	}


	//addition of other nodes
	else{
		//assign memory for the next node
		temp->next=(struct node*)malloc(sizeof(struct node));
		
		//move temp to the next block
		temp=temp->next;


		//assign values
		temp->coeff=coefficient;
		
		
		temp->power=pow;

		//make the next block null
		temp->next=NULL;
	}
	temp->next=NULL;
	return head;
}

void display(struct node*head){
	
	struct node*temp;
	
	for (temp=head;temp!=NULL;temp=temp->next){
		printf(" %d",temp->coeff);

		if (temp->next !=NULL){
			printf("x^%d +",temp->power);
		}
		
		else{
			printf("x^%d ",temp->power);
		}
	}
}


struct node* add_poly(struct node*head1, struct node*head2,struct node*head3){
		struct node*temp1=head1;
		struct node*temp2=head2;
		struct node*temp3;
		

		while (temp1!=NULL && temp2!=NULL){
			

			//memory allocation for the third linked list
			if (head3==NULL){
				//when temp3 is empty
				//allocate memory for the third linked list
				head3=(struct node*)malloc(sizeof(struct node));

				//temp3 and head3 are the same
				temp3=head3;
			}


			else{
				temp3->next=(struct node*)malloc(sizeof(struct node));
			

				//move temp3
				temp3=temp3->next;
			
			}

			
			//addition	

			if (temp1->power > temp2->power){
				temp3->coeff=temp1->coeff;	
				temp3->power=temp1->power;

				//initialize the next part of temp3 to null
				temp3->next=NULL;
				

				//display(head3);


				//move temp1's pointer
				temp1=temp1->next;
				
			}

			else if (temp1->power < temp2->power){
				temp3->coeff=temp2->coeff;
				temp3->power=temp2->power;
				
				temp3->next=NULL;
				temp2=temp2->next;
			}



			else{
				temp3->coeff=temp1->coeff+temp2->coeff;
				temp3->power=temp1->power;

				temp3->next=NULL;


				//move both pointers
				temp1=temp1->next;
				temp2=temp2->next;
			}
		}
		


		//printing the rest of the list,until both linked lists reach null
		

		while (temp1!=NULL || temp2!=NULL){
			//allocate memory for the third linked list
			temp3->next=(struct node*)malloc(sizeof(struct node));
			

			//move pointer temp3
			temp3=temp3->next;
			

			//checking which list is not NULL yet

			if (temp1!=NULL){
				temp3->coeff=temp1->coeff;
				temp3->power=temp1->power;
				temp3->next=NULL;

				temp1=temp1->next;
			}


			else{
				temp3->coeff=temp2->coeff;
				temp3->power=temp2->power;
				temp3->next=NULL;

				temp2=temp2->next;
				
			}


		}
		return head3;
}
//main 
void main(){
	int coefficient;
	int pow;
	static struct node* head1=NULL;
	static struct node* head2=NULL;
	static struct node* head3=NULL;
	
	//input for the first polynomial;
	printf("Input for the first polynomial");
	
	
	int status=1;
	do{
		printf("\nEnter the coefficient");
		scanf("%d",&coefficient);
		printf("\nEnter the power");
		scanf("%d",&pow);
		head1=create (coefficient,pow,head1);
		printf("Enter 1 to create more nodes");
		scanf("%d",&status);

	}
	while(pow!=0 && status==1);

	

	status=1;
	printf("\n");
	printf("\nInput for the second polynomial");
	
	do{
		printf("\nEnter the coefficient");
		scanf("%d",&coefficient);
		printf("\nEnter the power");
		scanf("%d",&pow);
		head2=create (coefficient,pow,head2);
		printf("Enter 1 to create more nodes");
		scanf("%d",&status);
	}
	while(pow!=0 && status==1);

	printf("The polynomials entered are:\n");
	printf("Polynomial 1: ");
	display(head1);
	printf("\n");
	printf("Polynomial 2: ");
	display(head2);

	head3=add_poly(head1, head2, head3);
	printf("\n");
	printf("Polynomial Sum: ");
	display(head3);
}