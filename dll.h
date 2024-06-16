struct node{
	int data;
	struct node *next;
	struct node*prev;
};

	

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


struct node* delete_at_tail(struct node* head, struct node*tail){
		
		struct node*temp;
		if (head->next ==NULL){
			
			temp=head;
			printf("%d is popped",temp->data);
			head=NULL;
			free(temp);
			return head;
		}


		else{
			temp=tail;
			tail->prev->next=NULL;
			printf("%d is popped",temp->data);
			tail=tail->prev;
			free(temp);
			return tail;
	}

}


