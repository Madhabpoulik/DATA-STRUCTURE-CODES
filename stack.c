#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void create(node**);
void delete(node**);
void push(node **,int);
int pop(node **);
int peak(node **);
int isempty(node **);
void display(node**);
int main()
{
    node *head=(node *)0x1;
   int ch,x,i,ele,val,index;
   while(1)
   {
    printf("\n1:create \n2.push \n3.pop \n4.peak \n5:display \n6.isempty \n7.delete \n8:exit \nenter your choice:");
    scanf("%d",&ch);
    switch(ch)
        {
            case 1:
                    create(&head);
                    printf("stack is created");
                    break;
            case 2:
                    if(head==(node *)0x1)
                        {
                            printf("stack not created");
                            continue;
                        }
                    printf("enter the no to be pushed:");
                    scanf("%d",&val);
                    push(&head,val);
                    break;
            case 3:
                if(head==(node *)0x1)
                    {
                        printf("stack not created");
                        continue;
                    }
                   ele=pop(&head);
                   if(ele!=1000)
                    printf("the poped element is %d",ele);
                    if(ele ==1000)
                      printf(" push first....");
                    break;
            case 4:
                if(head==(node *)0x1)
                    {
                        printf("stack not created");
                        continue;
                    }
                    ele=peak(&head);
                    if(ele!=1000)
                        printf("the peak element is %d",ele);
                    if(ele ==1000)
                      printf(" push first....");
                        break;
            case 5:
            if(head==(node *)0x1)
                {
                    printf("stack not created");
                    continue;
                }
                display(&head);
                break;

            case 6:
                if(head==(node *)0x1)
                    {
                        printf("stack not created");
                        continue;
                    }
                    index=isempty(&head);
                    if(index==1)
                        printf("\n stack is empty");
                    else
                        printf("\nstack is not empty");
                    break;
            case 7:
                if(head==(node *)0x1)
                    {
                        printf("stack not created");
                        continue;
                    }
                delete(&head);
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
void create(node**head)
{
	*head=NULL;
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
void push(node **head,int val)
{
	node *a,*z;
	z=(node *)malloc(sizeof(node));
	z->data=val;
	a=*head;
	if(*head==NULL)
	{
		*head=z;
		z->next=NULL;
	}
	else
		{
			z->next=a;
			*head=z;
		}
}
int pop(node **head)
{
	node *b;
	b=*head;

   if(b==NULL)
   {
    printf("\nnothing to be poped.....stack is empty\n");
    return 1000;
   }
   else
    {
        (*head)=b->next;
        return(b->data);
        free(b);
     }

}
int peak(node **head)
{
	node *b;
	b=*head;
    if(b==NULL)
   {
    printf("nothing to be peaked.....stack is empty");
    return 1000;
   }
   else
   {
       return(b->data);
   }
}
int isempty(node **head)
{
    	if(*head==NULL)
			return 1;
        else
			return 0;
}
void display(node **head)
{
    node *q= *head;

	if(q==NULL)
        printf("nothing to show");
	while(q!=NULL)
	{
	    printf("list is:");
		printf("\n%d",q->data);
		q=q->next;
	}
}
