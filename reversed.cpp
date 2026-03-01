#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL,*temp;

void insert_begin(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=head;
    head=newnode;
}

void display()
{
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void reverse()
{
    struct node *prev=NULL,*curr=head,*nextnode;

    while(curr!=NULL){
        nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    head=prev;
}

int main()
{
    int n,x,i;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert_begin(x);
    }

    display();
    reverse();
    printf("\n");
    display();

    return 0;
}
