/* OUTPUT RESTRICTED DOUBLE ENDED QUEUE USING LINKED LIST*/
#include<stdio.h>
#include<stdlib.h>

struct dequeue
{
    int data;
    struct dequeue* next;
    struct dequeue* prev;
}*new,*first=NULL,*last=NULL,*temp;

void create()
{
    new=(struct dequeue*)malloc(sizeof(struct dequeue));
    printf("Enter the element: ");
    scanf("%d",&new->data);
}

void push_beg()
{
    
    create();
    if(first==NULL)
    {
        first=last=new;
        first->prev=NULL;
        last->next=NULL;
    }
    else
    {
        first->prev=new;
        new->next=first;
        new->prev=NULL;
        first==new;

    }
    printf("\nA new element has been added to the start of the list....\n");
}

void push_end()
{
    create();
    if(first==NULL)
    {
        first=last=new;
        first->prev=NULL;
        last->next=NULL;
    }
    else
    {
        new->prev=last;
        last->next=new;
        new->next=NULL;
        last=new;
    }
    printf("A new element has been added at the end of the list...\n");
}

void pop_beg()
{
    if(first==NULL)
    {
        printf("List is empty!! Data underflow. \n");
        return;
    }

    else if(first->next==NULL)
    {
        first=NULL;
        free(first);
        printf("\n node deleted at the beginning of the list...\n");
    }

    else
    {
        temp=first;
        first=first->next;
        first->prev=NULL;
        free(temp);
        printf("\n node deleted at the beginning of the list...\n");
    }
}

void display()
{
    if(first==NULL)
    {
        printf("List is empty!! Cannot display data.\n");
    }
    else
    {
        temp=first;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}


void output_restricted()
{   
    char ch='y';
    int ochoice;
    while(ch=='Y'||ch=='y')
    {
        printf("OUTPUT RESTRICTED DEQUE\n");
        printf("1.Insert at the beginning \n2.Insert at the end\n3.Delete at the beginning\n4.Display\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ochoice);
        switch (ochoice)
            {
            case 1:
            push_beg();
            printf("\n");
            break;
            case 2:
            push_end();
            printf("\n");
                break;
            case 3:
            pop_beg();
            printf("\n");
                break;
            case 4:
            display();
            printf("\n");
                break;
            default:
            printf("\n");
                break;
            }
        printf("Do you want to do more operations?...y/n: ");
    scanf("%s",&ch);
    }
}


int main()
{
    output_restricted();
    return 0;
}
