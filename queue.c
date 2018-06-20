#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void create(node**,node **);
void delete(node**,node **);
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
                            ele=dequeue(&head,&tail);
                            if(ele!=-9999)
                            printf("the dequeued element is %d",ele);
                            if(ele==-9999)
                            printf(" enqueue first...");
                            break;
                    case 4:
                        if(head==(node *)0x1)
                            {
                                printf("queue not created");
                                continue;
                            }
                                ele=peak(&head,&tail);
                                if(ele!=79797979)
                                printf("the peak element is %d",ele);
                                if(ele==79797979)
                            printf(" enqueue first...");
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
                        delete(&head,&tail);
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
void delete(node**head,node **tail)
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
void enqueue(node**head,node **tail,int val)
{
    node *a,*l;
    l=*tail;
    a=(node *)malloc(sizeof(node));
	a->data=val;
	a->next=NULL;
    if(*head==NULL && *tail==NULL)
    {
        *head=*tail=a;
        return;
    }
    else
    {
        l->next=a;
       *tail=a;

    }
}

void display(node**head,node **tail)
{
    node *i;
    i=*head;
    if((i==NULL)&&(*tail==NULL))
    {
        printf("queue is empty" );
        return;
    }
    printf("list is");
    while(i!=NULL)
    {
        printf("\n%d",i->data);
        i=i->next;

    }

}
int dequeue(node**head,node **tail)
{
    node *o,*l;
    o=*head;
    if(o==NULL)
    {
        printf("queue is empty");
        return -9999;
    }
    if(*tail==*head)
        {
        *head=*tail=NULL;
        }
        else
        {
            *head=o->next;
        }
        return (o->data);
        free(o);
}
int peak(node**head,node **tail)
{
    node *g=*head;
    if(*head!=NULL)
    {
        return (g->data);
    }
    else
    {
        return 79797979;
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
