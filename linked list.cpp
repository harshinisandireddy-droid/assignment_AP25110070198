#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL,*temp,*newnode;

void insert_end(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;

    if(head==NULL)
        head=newnode;
    else{
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}

void display()
{
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int n,x,i;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert_end(x);
    }

    display();
    return 0;
}
