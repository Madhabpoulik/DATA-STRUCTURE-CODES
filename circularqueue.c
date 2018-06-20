#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void create(node**,node **);
void deleteall(node**,node **);
void display(node**,node **);
int peak(node **,node **);
int isempty(node **,node **);
void enqueue(node **,node **,int);
int dequeue(node **,node **);
int main()
{
      node *head=(node *)0x1;
      node *tail=(node *)0x1;

   int ch,x,i,ele,val,index;
   while(1)
   {

            printf("\n1:create \n2.enqueue \n3.dequeue \n4.peak \n5:display \n6.isempty \n7.delete \n8:exit \nenter your choice:");
            scanf("%d",&ch);
            switch(ch)
                {
                    case 1:
                            create(&head,&tail);
                            printf("queue is created");
                            break;
                    case 2:
                            if(head==(node *)0x1)
                                {
                                    printf("queue not created");
                                    continue;
                                }
                            printf("enter the no to enqueue:");
                            scanf("%d",&val);
                            enqueue(&head,&tail,val);
                            break;
                    case 3:
                        if(head==(node *)0x1)
                            {
                                printf("queue not created");
                                continue;
                            }
                            if(ele=dequeue(&head,&tail))
                            printf("the dequeued element is %d",ele);
                            if(ele==-9999)
                            printf("queue is empty enqueue first...");
                            break;
                    case 4:
                        if(head==(node *)0x1)
                            {
                                printf("queue not created");
                                continue;
                            }
                                ele=peak(&head,&tail);
                                printf("the peak element is %d",ele);
                                if(ele==0)
                            printf("queue is empty enqueue first...");
                                break;
                    case 5:
                        if(head==(node *)0x1)
                            {
                                printf("queue not created");
                                continue;
                            }
                            display(&head,&tail);
                            break;

                    case 6:
                        if(head==(node *)0x1)
                            {
                                printf("queue not created");
                                continue;
                            }
                            index=isempty(&head,&tail);
                            if(index==1)
                                printf("\n queue is empty");
                            else
                                printf("queue is not empty");
                            break;
                    case 7:
                        if(head==(node *)0x1)
                            {
                                printf("queue not created");
                                continue;
                            }
                        deleteall(&head,&tail);
                        break;
                    case 8:
                            exit(1);
                            break;
                        default:
                                printf("wrong input");
                                break;
                }
   }
    return 0;
}
void create(node**head,node **tail)
{
	*head=NULL;
	*tail=NULL;
}
void deleteall(node**head,node **tail)
{
	node *q;
	while(*head!=NULL)
	{
		q=*head;
		(*head)=(*head)->next;
		free(q);
	}
	*head=(node *)0x1;
}
void enqueue(node** head,node **tail,int x)
{
    node*t;
node*e=*tail;
node *l=*head;
t=(node*)malloc(sizeof (node));
t->data=x;
t->next=*tail;
if(*head==NULL)
    {
	*head=*tail=t;
	(t->next)=*tail;
    }
else
{
while(e->next!=*head)
	{
		e=e->next;
	}
l->next=t;
*head=t;
}
}
int dequeue(node **head,node **tail)
{
        node *h=*tail;
    if(h==NULL)
    {
        printf("queue is empty");
        return -9999;
    }
    else
    {
    *tail=h->next;
    }
    if(*tail==*head)
    {
        *head=*tail=NULL;
    }
    return(h->data);
    node *t=*head;
    *tail=h->next;
    t->next=*tail;
    free(h);
}
void display(node **head,node **tail)
{
    node *q= *tail;
    node *j=*head;
    if(q==NULL)
        printf("nothing to show");
	printf("list is:");
	while(q!=*head)
	{
		printf("\n%d",q->data);
		q=q->next;
	}
	if(q==*head)
    {
     printf("\n%d",q->data);
    }
}
int isempty(node**head,node **tail)
{
    if((*head==NULL)&&(*tail==NULL))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peak(node**head,node **tail)
{
    node *g=*tail;
    if(*tail!=NULL)
    {
        return (g->data);
    }
    else
    {
        return 0;
    }
}
