#include<stdio.h>
#include<stdlib.h>



void enqueue(int q[],int n,int *front,int *rear,int data)
{
    if(*rear==n)
    {
        printf("queue full");
    }
    else
    {
        q[*rear]=data;
        (*rear)++;
    }
}
int dequeue(int q[],int *front,int *rear)
{
    int data;
    if(*front==*rear)
    {
        printf("queue empty");
        return -1;
    }
    else
    {
        data=q[*front];
        (*front)++;
        return data;
    }
}
int isInQueue(int *q, int *front, int *rear, int data){
	int i;
	for (i=*front;i<*rear;i++){
		if(q[*front]==data){
			return 1;
		}
	}

	return 0;
}


void bfs(int size, int a[][size],int *v, int q[], int *front, int *rear, int n){
	int i,j;
	if (*front != *rear){
		i=dequeue(q, front, rear);
		v[i]=1;
		printf("%d ",i);
		for (j=0; j<size;j++){
			if (a[i][j]==1 && v[j]==0 && (isInQueue(q,front,rear,j)==0)){
				//printf("\n %d is queued", j);
				enqueue(q,n,front,rear,j);
				}
		}
	
	//printf("\n next recursive call");	
	bfs(size, a, v, q, front, rear, n);
		
	}


}




int main()
{
    int q[50];
    int n=50;
	 int size=6;
	 int v[6]={0,0,0,0,0,0};
    int *front,*rear;
    front=(int *)malloc(sizeof(int));
    rear=(int *)malloc(sizeof(int));
    *front=0;
    *rear=0;
    int a[6][6]={0,0,0,1,0,1,
							0,0,1,0,0,1,
							0,1,0,1,1,1,
							1,0,1,0,1,0,
							0,0,1,1,0,0,
							1,1,1,0,0,0};

	enqueue(q,n,front,rear,0);
	//printf("\ndata %d is dequeued\n",dequeue(q,front,rear));
	bfs(size, a, v, q, front, rear, n);
	
}
