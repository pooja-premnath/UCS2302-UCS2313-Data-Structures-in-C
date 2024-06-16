#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// structure to maintain priority of operators
struct priority{
	char operator;
	int value;
};



int precedence(struct priority p[5], char symbol){
		int flag=0;
		for (int i=0;i<5;i++){
			if(p[i].operator==symbol){
				//printf("\n operator is %c and value is %d",p[i].operator,p[i].value);
				flag=1;
				return p[i].value;
				
			}
		}
		if (flag==0){	
			return 0;
		}
}


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
void push(char *s, char data, int *top, int n){
	if (stack_full(top,n)==1){
		printf("\nStack Full");
	}
	else{
		s[*top]=data;
		
		(*top)++;
	}	
}


//pop operations
char pop(char *s, int *top){
	char data;
	if (stack_empty(top)==1){
		printf("\nEmpty Stack");
		return ' ';
	}
	
	else{
		(*top)--;
		data=s[*top];
		
		return data;
	}
}

int left_to_right_associative(char top_val){
	if(top_val =='^'){
		return 0;
	}
	else{
		return 1;
	}
}


char peek(char *s, int *top){
	//printf("\n top inside the peek function is %d", *top);
	int top_val=*top-1;
	return s[top_val];
}


int convert(char *s,char value,int *top, int n,char*post, int pos,struct priority p[5]){
		char popped_val;
		switch(value){


			case '(':
				push(s, value, top, n);
				printf("\n%c pushed",value);
				break;


			case ')':
				printf("\nFound a closing bracket");
				while((popped_val=pop(s,top)) != '(' && !(stack_empty(top))){
					printf("\n%c is popped",popped_val);
					post[pos++]=popped_val;
					
				}
				break;

			
			case '+':
			case '-':  
			case '^':
			case '/':
			case '*':
					/*printf("\n top is %d", *top);
					printf("\n element on top of the stack is %c", peek(s,top));
					printf("\n precedence of top %d",precedence(p,peek(s,top)));
					printf("\n precedence of incoming char %d",precedence(p,value));*/
					while ((!(stack_empty(top)) && (precedence(p,peek(s,top))>=precedence(p,value))) || ((precedence(p,peek(s,top))==precedence(p,value)) && left_to_right_associative(peek(s,top)) )){
						char pop_value=pop(s,top);
						printf("\n%c is popped",pop_value);
						printf("\n pop value is %c", pop_value);
						post[pos++]=pop_value;
						
					}

					push(s,value,top,n);
					printf("\n%c pushed",value);
					break;

			default:
				printf("\n%c goes to the output", value);
				post[pos++]=value;
			
		 }
		
		return pos;
}


double eval(char *post){
	char ps[100],n=100; 
	int *p_top=(int *)malloc(sizeof(int));
	*p_top=0;
	int i=0;
	char c;
	double op1, op2;
	double res;
	while (post[i]!='\0'){
		c=post[i];

		//if the element is a digit, push it into the stack		
		if(isdigit(c)>0){
			push(ps,c,p_top,n);
		}


		//pop two elements from the stack otherwise 		
		else if (c!='(' && c!=')'){
			op1=pop(ps, p_top)-'0';
			op2=pop(ps,p_top)-'0';
			if (c=='+'){
				res=op1+op2;
			}
	
			else if(c=='*'){
				res=op1*op2;
			}
			else if(c=='-'){
				res=op2-op1;
			}
			else{
				res=op1/op2;
			}
			char str[100];
			
			push(ps,res+'0',p_top,n);
		}
		i++;

	}
	res=pop(ps,p_top)-'0';
	return res;

}

void main(){


	//assignment of priority of operators
	struct priority p[5];
	p[0].operator='^';
	p[1].operator='+';
	p[2].operator='-';
	p[3].operator='*';
	p[4].operator='/';

	p[0].value=3;
	p[1].value=1;
	p[2].value=1;
	p[3].value=2;
	p[4].value=2;
	
	//stack initialization and getting user input
	char s[100];
	char exp[100];
	char post[100];
	double result;
	int n=20;
	printf("\nEnter an infix expression");
	scanf("%s",exp);
	printf("\nThe infix expression is: %s",exp);

	
	//initialization of a top pointer
	int *top=(int*)malloc(sizeof(int));
	*top=0;
	int pos=0;



	//iterating through the expression to convert it into postfix
	printf("\n\nINFIX TO POSTFIX CONVERSION STEPS");
	for (int i=0;exp[i]!='\0';i++){
		pos=convert(s,exp[i],top,n,post,pos,p);	
		
		//push(s,exp[i],top,n);
		//printf("\n Top: %d",*top);
		
		
		
	}
	

	while(!(stack_empty(top))){
		post[pos++]=pop(s, top);
	}
	post[pos]='\0';
	printf("\n");
	printf("\nPostfix: %s",post);

	result=eval(post);
	printf("\n");
	printf("\nThe evaluated result is: %lf", result);
	
}