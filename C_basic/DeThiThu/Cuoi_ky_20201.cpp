#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char dia_diem[40];
    int gio,phut;
    Node *Next,*Pre;
}Node;

Node *makeNode (char *dia_diem, int gio, int phut)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy (newNode->dia_diem,dia_diem);
    newNode->gio = gio;
    newNode->phut = phut;
    newNode->Next = NULL;
    newNode->Pre = NULL;
    return newNode;
}

Node *insertNode (Node *head, Node *newNode)
{
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    Node *p = head;
    while (p->Next != NULL)
    {
        p = p->Next;
    }
    newNode->Pre = p;
    p->Next = newNode;
    return head;
}

Node *LoadFile (const char *fileName, Node *head)
{
    FILE *f = fopen(fileName,"r");
    char dia_diem[40];
    int gio, phut;
    while (!feof(f))
    {
        fscanf (f,"%s %d %d",dia_diem, &gio, &phut);
        head = insertNode(head, makeNode(dia_diem, gio, phut));
    }
    fclose (f);
    return head;
}

void printList (Node *head)
{
    Node *p = head;
    printf ("%-50s %-10s %-10s\n","Dia diem", "Gio", "Phut");
    while (p != NULL)
    {
        printf("%-50s %-10d %-10d\n",p->dia_diem,p->gio, p->phut);
        p = p->Next;
    }    
}

Node* TimKiem3 (Node *head)
{
    char diaDiem[40];
    printf ("Nhap vao dia chi!\n");
    scanf ("%s",diaDiem);
    //system("cls");
    printf ("Ket qua:\n%s: ",diaDiem);
    Node *p = head;
    Node *q=NULL;
    int dem=0;
    while (p!=NULL)
    {
        if (strcmp(diaDiem,p->dia_diem)==0)
        {
            printf ("%d:%d, ",p->gio, p->phut);
            q=p;
            dem++;
        }
        p = p->Next;
    }
    if (dem == 0)
    {
        printf ("Ban chua den dia diem nay!\n");
        return NULL;
    }
    return q;
}

Node* TimKiem (Node *head, char *diaDiem)
{
    Node *p = head;
    Node *q=NULL;
    int dem=0;
    while (p!=NULL)
    {
        if (strcmp(diaDiem,p->dia_diem)==0)
        {
            //printf ("%d:%d, ",p->gio, p->phut);
            q=p;
            dem++;
        }
        p = p->Next;
    }
    if (dem == 0)
    {
        //printf ("Ban chua den dia diem nay!\n");
        return NULL;
    }
    return q;
}

void ChucNang6 (Node *head)
{
    char diaDiem[40];
    int gio, phut;
    printf ("Lich trinh benh nhan: ");
    scanf ("%s %d %d",diaDiem,&gio, &phut);
    Node *p = TimKiem (head, diaDiem);
    printf ("Lich trinh cua ban:   %s %d %d\n",p->dia_diem,p->gio,p->phut);
    if (p == NULL)
    {
        printf ("Lich su di chuyen cua ban OK\n");
        return;
    }
    if (p->gio == gio)
    {
        if (p->phut >= phut)
        {
            printf ("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
            return;
        }
        else 
        {
            printf ("Lich su di chuyen cua ban OK\n");
            return;
        }

    }
    else if (p->gio > gio)
    {
        printf ("Ban co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
        return;
    }
    else if (p->gio < gio)
    {
        printf ("Lich su di chuyen cua ban OK\n");
        return;
    }
}

void timKiem4 (Node *head)
{
    int gio, phut;
    printf ("Nhap gio,phut: ");
    scanf ("%d %d",&gio, &phut);
    while ((gio<0 || gio>=24) || (phut<0 || phut>=60))
    {
        printf ("Nhap lai:\n");
        printf ("Nhap gio,phut: ");
        scanf ("%d %d",&gio, &phut);
    }
    Node *p = head;
    while (true)
    {
        if (gio > p->gio)
        {
            p=p->Next;
            continue;
        }
        else if (gio == p->gio)
        {
            if (phut < p->phut)
            {
                p=p->Next;
                continue;
            }
        }
        else 
            break;
    }
    p=p->Pre;
    if (p!=NULL)
        printf ("%s\n",p->dia_diem);
    //printf ("%d:%d\n",p->gio, p->phut);
    else
        printf ("KHONG tim thay lich su di chuyen!\n");
}

int main ()
{
    Node *head=NULL;
    head = LoadFile ("DiaDiem.txt", head);
    //printList (head);
    //TimKiem3 (head);
    //timKiem4 (head);
    ChucNang6 (head);
    return 0;
}

