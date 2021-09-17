#include <stdio.h>
#include <stdlib.h>


/*
 STACKS USING ARRAYS
 */

struct Stack
{
    int size; // size of stack
    int top; // pointer to top of the stack
    int *S; // pointer to a dynammically constructed array
};

void create(struct Stack *st)
{
    /* 1) Get the size of the stack
       2) Point "top" to nothing
       3) Initialize the array dynamically */

    printf("Enter Size");
    scanf("%d",&st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size*sizeof(int));
}
 
void Display(struct Stack st)
{
    for(int i = st.top ; i >= 0 ; i--)
        printf("%d ",st.S[i]);
    printf("\n");
}

void pushARR(struct Stack *st, int val)
{
    /* If stack is full, we can't do anything.
     In all other cases, we follow 2 steps:
     1) increment the top pointer
     2) insert the given value at the top of the array S */
    
    if(st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = val;
    }
}

int popARR(struct Stack *st)
{
    /* If the stack is empty, we can't do anything.
     In all other cases, we remove the topmost
     element of the stack */
    
    int val = -1;
    if(st->top == -1)
        printf("Stack Underflow\n");
    val = st->S[st->top--];
    return val;
}

int peekARR(struct Stack st, int index)
{
    /* If the index is invalid, we can't do anything.
       In all other cases, return the value at the
     specified index */
    
    int val = -1;
    if(st.top - index + 1 < 0)
        printf("Invalid Index \n");
    val = st.S[st.top - index + 1];
    return val;
}

int isEmptyARR(struct Stack st)
{
    return st.top == -1;
}

int isFullARR(struct Stack st)
{
    return st.top == st.size-1;
}

int stackTopARR(struct Stack st)
{
    if(!isEmptyARR(st))
        return st.S[st.top];
    return -1;
}


/*
 STACKS USING LINKED LISTS
 */

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void pushLL(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("stack is full\n");
    else
    {
        /* 1) assign the value that needs to be inserted
              to the node t
           2) then make it point to the node top
           3) now that t is the topmost node, make the node top
              equal to t */
        t->data=x;
        t->next=top;
        top=t;
    }
}

int popLL()
{
    struct Node *t;
    int x=-1;

    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        /* 1) Assign node t to the node top
           2) Move top to the node next to top because the
              orignal top will soon be deleted
           3) Assign the value of node t to val so that the value
              that is being removed can be returned
           4) Get rid of t because its not needed anymore */
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void DisplayLL()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

/* Parenthesis Matching */
int isBalanced(char *exp)
{
    /* 1) Loop through the expresssion until terminator
           2) If an opening bracket is found, we push it into the stack
           3) If is not found, we see if a closing bracket if found
               4) In case a closing bracket is found, we check
                  5) If the top is empty (i.e # if '('s < # of ')'s
                      If yes, then we know the expression is inbalanced
                  6) If the top is not NULL, we pop the the closing bracket
       7) Finally, we see if the top is NULL (= exp is balanced) */
    for(int i = 0 ; exp[i] != '\0' ; i++)
    {
        if(exp[i] == '(')
            pushLL(exp[i]);
        else if(exp[i] == ')')
        {
            if(top == NULL)
            return 0;
            popLL();
        }
    }
    if(top == NULL)
        return 1;
    return 0;
}


/*
QUEUES USING ARRAYS
*/

struct Queue
{
    int size; // size of Queue
    int front; // pointer at the first element of the Queue (used for deletions)
    int rear; // points at the last element of the Queue (used for insertions)
    int *Q; // a pointer to create an array dynamically
};

void enqueue(struct Queue *q, int val)
{
    // if queue is full, no insertion possible
    if (q->rear == q->size - 1)
        printf("Queue is full");
    // in all other cases
    else
    {
        // shift the rear pointer one step
        q->rear++;
        q->Q[q->rear] = val;
    }
}

int dequeue(struct Queue *q)
{
    int val = -1;
    
    // if there are no elements, no deletion possible
    if (q->rear == q->front)
        printf("Queeue if empty");
    // in all other cases
    else
    {
        q->front++;
        val = q->Q[q->front];
    }
    return val;
}

int main()
{
    struct Queue q;
    printf("Enter size of the Queue");
    scanf("%d", &q.size); // read size from user
    q.Q = (int *)malloc(q.size * sizeof(int)); // create queue array in heap
    q.front = q.rear = -1; // initialize front and rear to 1
    
    
    
    
    char *exp="((a+b)*(c-d)))";
    printf("%d ",isBalanced(exp));

    return 0;
}
