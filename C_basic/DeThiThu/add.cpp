#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct node
{
    char phone_number[MAX],to_number[MAX],date[MAX],from_time[MAX],end_time[MAX];
    node *pNext;
}node;
node *makeNode (node *head,char phone_number[MAX],char to_number[MAX],char date[MAX],char from_time[MAX],char end_time[MAX]){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->pNext = NULL;
    strcpy(newNode->phone_number,phone_number);
    strcpy(newNode->to_number,to_number);
    strcpy(newNode->date,date);
    strcpy(newNode->from_time,from_time);
    strcpy(newNode->end_time,end_time);
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

void printInf(node * head){
    if (head == NULL)
        return;
    node *p = head;
    while (p != NULL)
    {
        printf ("%s %s %s %s %s\n",p->phone_number,p->to_number,p->date,p->from_time,p->end_time);
        p = p->pNext;
    }
}


int check_phone_number (node *head){
    node *p = head;
    int dem=0;
    while (p != NULL)
    {
        if(strlen(p->phone_number)!=10)
        {
            dem++;
            p=p->pNext;
            continue;
        }
        for (int i=0; i<strlen(p->phone_number); i++)
        {
            if (p->phone_number[i] > '9' || p->phone_number[i] < '0')
            {
                dem++;
                break;
            }
        }
        p = p->pNext;
    }
    if (dem == 0)
    {
        return 1;
    }
    return dem;
}


int number_calls_from (node *head)
{
    char phone_number[MAX];
    scanf ("%s",phone_number);
    node *p =head;
    int dem=0;
    while (p != NULL)
    {
        if (strcmp(p->phone_number,phone_number)==0)
        {
            dem++;
        }
        p = p->pNext;
    }
    return dem;
}
int number_total_calls(node *head){
    node *p =head;
    int dem=0;
    while (p != NULL)
    {
        dem++;
        p = p->pNext;
    }
    return dem;
}

void covertTime (char timeCall[], int rs[]){
    rs[0] = atoi(&timeCall[0]);
    rs[1] = atoi(&timeCall[3]);
    rs[2] = atoi(&timeCall[6]);
}

int count_time_calls_from(node *head){
    char phone_number[MAX];
    scanf ("%s",phone_number);
    // printf ("Nhap xong sdt\n");
    node *p = head;
    int total=0;
    while (p != NULL)
    {
        if (strcmp(p->phone_number,phone_number)==0)
        {
            // printf ("Vap if trong while\n");
            int fromTime[3]; covertTime(p->from_time,fromTime);
            // printf ("%d %d %d\n",fromTime[0],fromTime[1],fromTime[2]);
            int endTime[3]; covertTime(p->end_time,endTime);
            // printf ("%d %d %d\n",endTime[0],endTime[1],endTime[2]);
            // printf ("from: %d %d %d\n",fromTime[0],fromTime[1],fromTime[2]);
            // printf ("end : %d %d %d\n",endTime[0],endTime[1],endTime[2]);
            total += 3600*(-fromTime[0]+endTime[0])+60*(-fromTime[1]+endTime[1])+(-fromTime[2]+endTime[2]);
        }
        p = p->pNext;
    }
    return total;
}

int checkQuery (char query[],node *head){
    if(strcmp(query,"?check_phone_number")==0)
    {
        return check_phone_number(head);
    }
    else if (strcmp(query,"?number_calls_from")==0)
    {
        return number_calls_from(head);
    }
    else if (strcmp(query,"?number_total_calls")==0)
    {
        return number_total_calls(head);
    }
    else if (strcmp(query,"?count_time_calls_from")==0)
    {
        return count_time_calls_from(head);
    }
    else
    {
        return 0;
    }
}

int main(){
    char call[5];
    node *head=NULL;
    // printf ("%p",head);
    char phone_number[MAX],to_number[MAX],date[MAX],from_time[MAX],end_time[MAX];
    while (1)
    {
        scanf ("%s",call);
        if (strcmp(call,"#")==0)
        {
            break;
        }
        scanf ("%s %s %s %s %s",phone_number,to_number,date,from_time,end_time);
        head = insert_node(head,makeNode(head,phone_number,to_number,date,from_time,end_time));
    }
    // char query[5]["?check_phone_number","?check_phone_number","?check_phone_number","?check_phone_number"];
    int result[MAX];
    char query[MAX];
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
    // scanf ("%s",phone_number); cau nay chi duoc goi khi da kiem tra xong dang query
    // printInf (head);
    for (int i=0;i<count; i++)
    {
        printf("%d\n",result[i]);
    }
    // getchar();
    // fflush (stdin);
}
