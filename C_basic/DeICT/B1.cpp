#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 20
typedef struct node
{
    char from_account[20],to_account[20],time_point[20],atm[10];
    int money;
    node *pNext;
}node;
node *makeNode (node *head,char from_account[MAX],char to_account[MAX],int money,char time_point[MAX],char atm[10]){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->pNext = NULL;
    strcpy(newNode->atm,atm);
    strcpy(newNode->from_account,from_account);
    strcpy(newNode->to_account,to_account);
    strcpy(newNode->time_point,time_point);
    newNode->money = money;
    return newNode;
}

node *insert_node(node *head,node *newNode){
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    node *p = head;
    while (p->pNext != NULL)
    {
        p = p->pNext;
    }
    p->pNext = newNode;
    return head;
}
int number_transactions(node *head){
    node *p =head;
    int dem=0;
    while (p != NULL)
    {
        dem++;
        p = p->pNext;
    }
    return dem;
}
int checkQuery (char query[],node *head){
    if(strcmp(query,"?number_transactions")==0)
    {
        return number_transactions(head);
    }
    else if (strcmp(query,"?total_money_transaction")==0)
    {
        // return total_money_transaction(head);
    }
    else if (strcmp(query,"?list_sorted_accounts")==0)
    {
        // return list_sorted_accounts(head);
    }
    else if (strcmp(query,"?total_money_transaction_from")==0)
    {
        // return total_money_transaction_from(head);
    }
    else if (strcmp(query,"?inspect_cycle")==0)
    {
        // return inspect_cycle(head);
    }
    return 0;
}

int main ()
{
    node *head=NULL;
    char from_account[MAX],to_account[MAX],time_point[MAX],atm[MAX];
    int money;
    while (1)
    {
        scanf ("%s",from_account);
        if (strcmp(from_account,"#")==0)
        {
            break;
        }
        scanf ("%s %d %s %s",to_account,&money,time_point,atm);
        head = insert_node(head,makeNode(head,from_account,to_account,money,time_point,atm));
    }
    int result[100000000];
    char query[100];
    int count=0;
    while (1)
    {
        scanf ("%s",query);
        // printf ("%s",query);
        if (strcmp(query,"#")==0)
        {
            break;
        }

        // printf ("Nhap thanh cong\n");
        result[count] = checkQuery (query,head);
        count++;
    }
    for (int i=0;i<count; i++)
    {
        printf("%d\n",result[i]);
    }
}   