#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x)
{
    if(rear == MAX-1) return;
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n, x, i;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }

    printf("Original queue: ");
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);

    while(front<=rear)
        push(dequeue());

    front=0; rear=-1;
    while(top!=-1)
        enqueue(pop());

    printf("\nReversed queue: ");
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);

    return 0;
}
