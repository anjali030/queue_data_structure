#include<stdio.h>
#include<conio.h>
#define MAX 6
int q[10],front=-1,rear=-1;
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

        if(front==-1 && rear==-1)
        {

                front=0;
                rear=0;
                q[rear]=num;
                return;
        }
        if(front==0 && rear==MAX-1||front==rear+1)
        {

                printf("queue overflow");
                return;
        }
        if(rear==MAX-1)
        {

                rear=0;
        }
        else
        {
                rear=rear+1;
                q[rear]=num;

        }

}
int qdelete()
{

        int num;
        if(front==-1 && rear==-1)
        {

                printf("underflow");
                return;
        }
        num=q[front];
        q[front]=NULL;
        if(front==rear)
        {

                front=rear=-1;
        }
        else
                if(front==MAX-1)
                        front=0;
                else
                        front=front +1;
                        return;
}
void qshow()
{

        int i;
        printf("\n front=%d\t rear=%d\t",front,rear);
        for(i=0;i<MAX;i++)
        {

                if(q[i]==NULL)
                        printf("-\t");
                else
                        printf("%d \t",q[i]);
        }
}
