#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void create(node**,node **);
void createlist(node**,node **,int);
void delete(node**,node **);
void print(node**,node **);
void insbeg(node**,node **,int);
void insend(node**,node **,int);
void insnth(node**,node **,int,int);
void delend(node**,node **);
void delbeg(node**,node **);
void delnth(node**,node **,int);
void print(node**,node **);
int main()
{
    node *head=(node *)0x1;
    node *tail=(node *)0x1;
   int ch,x,i,pos;
   while(1)
   {
       printf("\n1.create\n 2.create list\n 3.insert at beginning\n 4.insert at Nth position\n 5.insert at end\n 6.delete at beginning\n 7.delete at Nth position\n 8.delete at ending\n 9.print\n 10.delete\n 11.exit\n enter your choice: ");
       scanf("%d",&ch);
        switch(ch)
       {
                case 1:
                        create(&head,&tail);
                        printf("linklist is created");
                        break;
                case 2:
                        if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        printf("\nenter the no.:");
                        scanf("%d",&x);
                        createlist(&head,&tail,x);
                        break;
                case 3:
                        if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        printf("\nenter the no.:");
                        scanf("%d",&x);
                        insbeg(&head,&tail,x);
                        break;
               case 4:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        printf("\nenter the no.:");
                        scanf("%d",&x);
                        printf("\nwhats the position:");
                        scanf("%d",&pos);
                        insnth(&head,&tail,pos,x);
                        break;

                case 5:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        printf("\nenter the no.:");
                        scanf("%d",&x);
                        insend(&head,&tail,x);
                        break;
                case 6:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        delbeg(&head,&tail);
                        break;
                case 7:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        printf("\nwhats the position:");
                        scanf("%d",&pos);
                        delnth(&head,&tail,pos);
                        break;
                case 8:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        delend(&head,&tail);
                        break;
                case 9:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        print(&head,&tail);
                        break;
                case 10:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        delete(&head,&tail);
                        break;
                case 11:
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
void print(node **head,node **tail)
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
void delete(node **head,node **tail)
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
void insbeg(node **head,node **tail,int x)
{
	node *a,*b;
	b=*head;
	a=(node *)malloc(sizeof(node));
	(a->data)=x;
	(a->next)=*tail;
	if(*head==NULL)
    {
	*head=*tail=a;
	(a->next)=*tail;
    }
    else
    {
        *tail=a;
        b->next=*tail;

    }
}
void insnth(node **head,node **tail,int pos,int x)
{
	node *z;
	int i;
	z=(node *)malloc(sizeof(node));
	z->data=x;
	z->next=NULL;
	if(pos==1)
	{
		z->next=*tail;
		*tail=z;
		return;
	}
	node *w=*tail;
	for( i=0;i<pos-2;i++)
	{
		w=w->next;
	}
	z->next=w->next;
	w->next=z;
}
void delbeg(node **head,node **tail)
{
    node *h=*tail;
    node *t=*head;
    *tail=h->next;
    t->next=*tail;
    free(h);
}
void delend(node **head,node **tail)
{
    node *u=*tail;
    while(u!=*head)
    {
        u=u->next;
        *head=u;
    }
    node *y=u->next;
    free(y);
}
void delnth(node **head,node **tail,int pos)
{
    node *k=*tail;
    node *j=*head;
    if(pos==1)
    {
        *head=(k->next);
        j->next=*tail;
        free(k);
    }
    int i;
    for(i=0;i<pos-2;i++)
    {
        k=k->next;
    }
    node *o=k->next;
    k->next=o->next;
    free(o);
    if(k->next==*head)
    {

    }
}
void insend(node** head,node **tail,int x)
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
void createlist(node** head,node **tail,int x)
{
    node *i;
    node*e=*head;
    i=(node*)malloc(sizeof (node));
i->data=x;
i->next=*head;
if(*head!=NULL)
    return ;
}

