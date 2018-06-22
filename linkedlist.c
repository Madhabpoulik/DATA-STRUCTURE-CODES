#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void create(node**);
void createlist(node **,int);
void delete(node**);
void insbeg(node **,int);
void insend(node **,int);
void insnth(node **,int,int);
void delend(node **);
void delbeg(node **);
void delnth(node **,int);
void print(node**);
int reverset(node*,int);
void revers(node **);
int main()
{
   node *head=(node *)0x1;
   int ch,x,i,pos;
   while(1)
   {
       printf("\n1.create\n 2.create list\n 3.insert at beginning\n 4.insert at Nth position\n 5.insert at end\n 6.delete at beginning\n 7.delete at Nth position\n 8.delete at ending\n 9.reverse\n 10.print\n 11.delete\n 12.exit\n enter your choice: ");
       scanf("%d",&ch);
       switch(ch)
       {
                case 1:
                        create(&head);
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
                        createlist(&head,x);
                        break;
                case 3:
                        if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        printf("\nenter the no.:");
                        scanf("%d",&x);
                        insbeg(&head,x);
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
                        insnth(&head,pos,x);
                        break;

                case 5:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        printf("\nenter the no.:");
                        scanf("%d",&x);
                        insend(&head,x);
                        break;
                case 6:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        delbeg(&head);
                        break;
                case 7:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        printf("\nwhats the position:");
                        scanf("%d",&pos);
                        delnth(&head,pos);
                        break;
                case 8:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        delend(&head);
                        break;
                case 9:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        revers(&head);
                        break;

                case 10:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        print(&head);
                        break;
                case 11:
                            if(head==(node *)0x1)
                        {
                            printf("linklist not created");
                            continue;
                        }
                        delete(&head);
                        break;
                case 12:
                        exit(1);
                        break;
                default:
                        printf("wrong input");
                        break;

       }
   }
    return 0;
}








void create(node**head)
{
	*head=NULL;
}








void print(node **head)
{
    node *q= *head;
	if(q==NULL)
        printf("nothing to show");
	else
    {
         printf("list is:");
        while(q!=NULL)
        {
		printf("\n%d",q->data);
		q=q->next;
        }
    }
}








void delete(node **head)
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







void insbeg(node **head,int x)
{
	node *a;
	a=(node *)malloc(sizeof(node));
	(a->data)=x;
	(a->next)=*head;
	*head=a;
}







void insnth(node **head,int pos,int x)
{
	node *z,*e=*head;
	int i;
	z=(node *)malloc(sizeof(node));
	z->data=x;
	z->next=NULL;
	 int c=0;
    while(e!=NULL)
    {
        e=e->next;
        c++;
    }
    if(pos>c)
        printf("wrong input.... give new input....\nyour max input is=%d",c);
    else
    {

	if(pos==0)
	{
		z->next=*head;
		*head=z;
		return;
	}
	    node *w=*head;
        for( i=0;i<pos-2;i++)
        {
            w=w->next;
        }
        z->next=w->next;
        w->next=z;
	}
}








void delbeg(node **head)
{
    node *h=*head;

    if(h==NULL)
        printf("no number to delete....");
    else
    {
       *head=h->next;
        free(h);
    }
}







void delend(node **head)
{
    node *u=*head,*p=u->next;
    if(u==NULL)
        printf("no number left to delete.....");
    else if(p==NULL)
    {
        free(u);
        *head=NULL;

    }

    else
    {
    while(p->next!=NULL)
    {
        u=p;
        p=p->next;
    }
    u->next=p->next;
    p->next=NULL;
    free(p);

    }
}







void delnth(node **head,int pos)
{
    node *k=*head;
    if(k==NULL)
        printf("no number to delete.....!!!");
    else
    {
        if(pos==1)
        {
        *head=k->next;
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
    }
}







void insend(node** head,int x)
{
    node*t;
node*e=*head;
t=(node*)malloc(sizeof (node));
t->data=x;
t->next=NULL;
if(*head==NULL)
{
    *head=t;
}
else
{
while(e->next!=NULL)
	{
		e=e->next;
	}
t->next=NULL;
e->next=t;
}
}






void createlist(node** head,int x)
{
    node *i;
    node*e=*head;
    i=(node*)malloc(sizeof (node));
i->data=x;
i->next=NULL;
if(*head==NULL)
{
    *head=i;
}
else
{
while(e->next!=NULL)
	{
		e=e->next;
	}
i->next=NULL;
e->next=i;
}
}






void revers(node **head)
{
    node *t=*head;
    node *prev=NULL;
    node *next=NULL;
    while(t!=NULL)
    {
        next=t->next;
        t->next=prev;
        prev=t;
        t=next;
    }
    *head=prev;
}

