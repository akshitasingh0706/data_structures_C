#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL; // global pointers

/* this creates a linked list from an array don’t stress to much about not fully making sense of it */
void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Iterative
void iDisplay(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Recursive
void rDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        rDisplay(p->next);;
    }
}

int iCountNodes(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return(count);
}

int rCountNodes(struct Node *p)
{
    if (p == 0)
        return 0;
    else
        return rCountNodes(p->next) + 1;
}

int rCountNodes2(struct Node *p)
{
    if (p)
        return rCountNodes2(p->next) + 1;
    return 0;
}

int rSumNodes(struct Node *p)
{
    if (p)
        return rSumNodes(p->next) + p->data;
    return 0;
}


int iMaxNodes(struct Node *p)
{
    int max = 0;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return(max);
}

int rMaxNodes(struct Node *p)
{
    if (p == 0)
        return 0;
    int x = rMaxNodes(p->next);
    return x > p->data ? x : p->data;
}


struct Node* iSearchNode(struct Node *p, int key)
{
    if (p == 0)
        return 0;
    while (p)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node* rSearchNode(struct Node *p, int key)
{
    if (p == 0)
        return 0;
    if (p->data == key)
        return p;
    return rSearchNode(p->next, key);

}

struct Node* SearchNode_mth(struct Node *p, int key)
{
    struct Node *q = NULL;
    
    while (p)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
    }
    q = p;
    p = p->next;
    return NULL;
}

void Insert(struct Node *p, int position, int value)
{
    struct Node *t;
    // check if the position of insertion is a valid index
    if (position < 0 || position > rCountNodes(p)) return;
    
    /* create a node where the new value is inserted and assign value
    that we wish to insert into t */
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    
    // if we want to insert an element at the very first node
    if (position == 0)
    {
        t->next = first;
        first = t;
    }
    // if we want to insert an element at any other but first node
    else
    {
        for (int i = 0; i < (position - 1); i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void sortedInsert(struct Node *p, int value)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;
    
    /* in case there is no node at all,
     we insert the value into the first node */
    if (first == NULL)
        first = t;
    // for all other cases...
    else
    {
        /* while there exists a node for p, and
         while the value in p in less the one one
         we wish to insert */
        while (p && p->data < value)
        {
            q = p;
            p = p->next;
        }
        /* if the very first node has a value greater than
         the one we want to insert */
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        // for all other cases...
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int position)
{
    struct Node *q = NULL;
    int val = -1;
    
    if (position < 1 || position > rCountNodes(p))
        return -1;
    if (position == 1)
    {
        q = first;
        val = first->data;
        first = first->next;
        free(q);
        return val;
    }
    else
    {
        for (int i = 0; i < position - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        val = p->data;
        free(p);
        return val;
    }
}

int isSorted(struct Node *p)
{
    int x = -65536;
    
    while (p)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicates(struct Node *p)
{
    /* here, we make p follow q*/
    struct Node *q = p->next;
    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(p);
            q = q->next;
        }
    }
}

void arrayReverse(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;
    A = (int *)malloc(rCountNodes(p) * sizeof(int));
    
    while (q)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}


void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void rReverse(struct Node *q, struct Node *p)
{
    if (p)
    {
        rReverse(p, p->next);
        p->next = q;
    }
    else
        first = q;
}


int main()
{
//    int A[] = {3, 5, 35, 10, 15, 2};
//    create(A, 6);
//    Insert(first, 6, 1);
    
    int B[] = {3, 5, 10, 15, 20};
    create(B, 5);
    Delete(first, 3);
//    sortedInsert(first, 12);

    
    rDisplay(first);
//    printf("%d\n",rCountNodes2(first));
//    printf("%d\n",rSumNodes(first));
//    printf("%d\n",rMaxNodes(first));
    
    

    return 0;
}
