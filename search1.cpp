#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear  = -1;
void enqueue(int x)
{
    if(rear == MAX-1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1) 
        front = 0;

    rear++;
    queue[rear] = x;
    printf("%d inserted\n", x);
}


void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", queue[front]);
    front++;
}


void search(int key)
{
    int i, found = 0;

    if(front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
        return;
    }

    for(i = front; i <= rear; i++)
    {
        if(queue[i] == key)
        {
            printf("Element found at position %d\n", i+1);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Element not found\n");
}


void display()
{
    int i;
    if(front == -1 || front > rear)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue elements: ");
    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}


int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    search(20);
    search(50);

    return 0;
}
