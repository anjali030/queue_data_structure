#include<stdio.h>
#include<conio.h>
#define MAX 6
struct queue
{

        int data;
        struct queue *next;
}*front,*rear;
void main()
{
   int ch, num;
   redo:
           printf("\nenter 1 to insert");
           printf("\nenter 2 to delete");
           printf("\nenter 3 to show elements");
           printf("\nenter 4 to exit");
           printf("\n enter your choice");
           scanf("%d",&ch);
           switch(ch)
           {

           case 1:
                printf("enter element to insert in queue");
                scanf("%d",&num);
                qinsert(num);
                goto redo;
           case 2:
                qdelete();

                goto redo;
           case 3:
                qshow();
                goto redo;
           case 4:
                exit(0);
           default:
                printf("invalid choice");
                goto redo;
           }
}
qinsert(int num)
{
        struct queue *temp;
        temp=(struct queue *)malloc (sizeof(struct queue *));
        temp->data=num;
        temp->next=NULL;

       if(front==NULL)
       {
               front=rear=temp;
               return;
       }
       rear->next=temp;
       rear=rear->next;
}
int qdelete()
{

        int num;
        struct queue *temp;
        if(front==NULL)
        {

                printf("underflow");
                return;
        }
        num=front->data;
        temp=front;
        front=front->next;
        free(temp);
        printf("data removed is %d",num);
}
void qshow()
{
        struct queue *q;

                if(front==NULL)
                {
                        printf("no element in queue");
                        return;
                }
                printf("elements in queue");
                for(q=front;q!=NULL;q=q->next)
                {

                        printf("%d\t",q->data);
                }
}
