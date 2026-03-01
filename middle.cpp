#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insert_front(int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=head;
    head=newnode;
}

void display()
{
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void middle()
{
    struct node *slow=head,*fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("\nMiddle Element: %d",slow->data);
}
int main()
{
    int n,x,i;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert_front(x);
    }

    display();
    middle();

    return 0;
}
