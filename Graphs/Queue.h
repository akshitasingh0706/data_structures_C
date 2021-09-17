#ifndef Queue_h
#define Queue_h

#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int val)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    // if queue is full, no insertion possible
    if (t == NULL)
        printf("Queue is full");
    // in all other cases
    else
    {
        t->data = val;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *t;
    
    // if there are no elements, no deletion possible
    if (front == NULL)
        printf("Queeue if empty");
    // in all other cases
    else
    {
        val = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return val;
}

int isEmpty()
{
    return front == NULL;
}

#endif /* Queue_h */
