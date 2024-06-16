#include <stdio.h>
#include <stdlib.h>


//stack full check
int stack_full(int *top,int n){
	if (*top ==n){
		return 1;
	}

	else{
		return 0;
	}

}


//stack empty check
int stack_empty(int *top){
	if (*top ==0){
		return 1;
	}

	else{
		return 0;
	}
}


//push operations
void push(int *s, int data, int *top, int n){
	if (stack_full(top,n)==1){
		printf("\nStack Full");
	}
	else{
		s[*top]=data;
		
		(*top)++;
	}	
}


//pop operations
int pop(int *s, int *top){
	int data;
	if (stack_empty(top)==1){
		printf("\nEmpty Stack");
		return ' ';
	}
	
	else{
		(*top)--;
		data=s[*top];
		printf("Data popped is %d",data);
		return data;
	}
}


void main(){
	int s[100];
	int n=100;
	//initialization of a top pointer
	int *top=(int*)malloc(sizeof(int));
	*top=0;
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
			push(s,ele,top,n);
			}

		else if (ch==2){
			int popped_ele=pop(s,top);
			if (popped_ele != ' '){
				printf("\n%d was popped",popped_ele);
			}
		}

		else{
			printf("Invalid Choice, try again");
		}

		printf("\nEnter 0 to continue stack operations");
		scanf("%d",&status);
	}
}