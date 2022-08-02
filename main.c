#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Queue sq;

struct Queue{
int size;
int front;
int rear;
int *arr;
};

void enqueue();
void dequeue();
void display();
void peek();

int main()
{
    sq *s = (sq *)malloc(sizeof(sq));
    s->size=100;
    s->front=-1;
    s->rear=-1;
    s->arr = (int *)malloc(s->size*sizeof(int));
    int choice;

    printf("-----------------------\n");
    printf("QUEUEING USING ARRAYS\n");
    printf("-----------------------\n");

  do{
    printf("____________________________");
    printf("\nCHOOSE A QUEUE OPERATION\n\n(1)INSERT\n(2)DELETE\n(3)DISPLAY\n(4)PEEK\n(5)EXIT\n");
    printf("____________________________");

    printf("\nENTER YOUR CHOICE :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
            enqueue(s);
             break;

    case 2:
            dequeue(s);
            break;

    case 3:
             display(s);
             break;

    case 4:
             peek(s);
             break;

    case 5:
            printf("\nEXIT\n");
            break;

    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");

    }
  }while(choice!=5);

  getch();
  return 0;

}

//return queue status: Empty or Not

int isEmpty(sq *s){
    if(s->front==-1 && s->rear==-1) return 1;

    return 0;
}

//return queue status: Full or Not

int isFull(sq *s){
    if(s->rear==s->size-1) return 1;

    return 0;
}

//enqueue() function add an element at the rear position of the queue

void enqueue(sq *s)
{
    int x;

    if(isFull(s))
    {
        printf("\nQUEUE OVERFLOW!!!\n");
    }
    else if(s->front==-1 && s->rear==-1)
    {

         printf("\nENTER AN ELEMENT TO INSERT IN THE QUEUE: ");
         scanf("%d",&x);

        s->rear=s->front=0;
        s->arr[s->rear]=x;
        printf("\nINSETRED ELEMENT IN THE QUEUE :%d",s->arr[s->rear]);
        printf("\nrear=%d\n",s->rear);

    }

    else
        {
             printf("\nENTER AN ELEMENT TO INSERT IN THE QUEUE: ");
             scanf("%d",&x);

          s->arr[++s->rear]=x;
          printf("\nINSETRED ELEMENT IS THE QUEUE :%d\n",s->arr[s->rear]);
          printf("\nrear=%d\n",s->rear);

        }

}

//dequeue() function deletes the front element from the queue

void dequeue(sq *s)
{


    if(isEmpty(s))
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }
    else if(s->rear==s->front)
    {
        printf("\nDELETED ELEMENT FROM THE QUEUE :%d\n",s->arr[s->front]);
        s->rear=s->front=-1;

    }

    else
    {
        printf("\nDELETED ELEMENT FROM THE QUEUE :%d\n",s->arr[s->front++]);

    }
}

//display() function print all the elements in the queue

void display(sq *s)
{
    if(isEmpty(s))
   {
     printf("\nQUEUE UNDERFLOW!!!\n");
    }

    else
 {
        printf("\nELEMENTS IN THE QUEUE:");
     for(int i=s->front;i<s->rear+1;i++)
    {
        printf("\n%d",s->arr[i]);

    }
    printf("\n");


 }

}

//peek() and top() function are same both returns top most element of the queue

void peek(sq *s)
{
    if(isEmpty(s))
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }

    else
    {
        printf("TOP ELEMENT OF THE QUEUE :%d\n",s->arr[s->front]);
    }
}
