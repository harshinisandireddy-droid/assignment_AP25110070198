#include<stdio.h>
#define MAX 5

int cq[MAX];
int front = -1;
int rear  = -1;

/* ENQUEUE */
void enqueue(int x)
{
    if((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1)   // first element
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = x;
    printf("%d inserted\n", x);
}

/* DEQUEUE */
void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", cq[front]);

    if(front == rear) // last element
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

/* SEARCH */
void search(int key)
{
    if(front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    int i = front;
    int found = 0;

    while(1)
    {
        if(cq[i] == key)
        {
            printf("Element found at position %d\n", i+1);
            found = 1;
            break;
        }

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    if(!found)
        printf("Element not found\n");
}

/* DISPLAY */
void display()
{
    if(front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");

    while(1)
    {
        printf("%d ", cq[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }
    printf("\n");
}

/* MAIN */
int main()
{
    enqueue(5);
    enqueue(15);
    enqueue(25);
    display();

    dequeue();
    display();

    search(25);
    search(100);

    return 0;
}
