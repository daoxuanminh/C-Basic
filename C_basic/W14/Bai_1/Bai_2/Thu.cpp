#include <stdio.h>
#include <stdlib.h>



typedef struct Node
{
    int data;
    Node* pNext;
}Node;


void InDS (Node *head);

Node *makeNode (int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->pNext = NULL;
    return newNode;
}
// Khong duoc duyet den con tro null
Node *InsertLast (Node *head, Node *p)
{
    if (head == NULL)
        return head = p;
    Node *tg = head;
    while (tg->pNext!=NULL)
    {
        tg = tg->pNext;
    }
    tg->pNext = p;
    return head;
}

void InDS (Node *head)
{
    printf ("%d\t",head->data);
    Node *p = head->pNext;
    while (p != NULL)
    {
        printf ("%d ",p->data);
        p = p->pNext;
    }
}

int main ()
{
    Node *head=NULL;
    Node *p=NULL;
    head = InsertLast (head,makeNode(1));
    head = InsertLast (head,makeNode(5));
    head = InsertLast (head,makeNode(4));
    head = InsertLast (head,makeNode(3));
    head = InsertLast (head,makeNode(2));
    InDS (head);
}