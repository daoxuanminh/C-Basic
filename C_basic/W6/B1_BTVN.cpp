// Bai tap xau doi xung lam bang ngan xep

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxlen 20
typedef struct List
{
    char s;
    struct List *next;
} Node;

Node *make_node(char s)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->s = s;
    return p;
}
// Them vao dau danh sach
Node *push(char s, Node *top)
{
    Node *p;
    p = make_node(s);
    p->next = top;
    top = p;
    return top;
}

Node *pop (Node *top)
{
    Node *tmp = top;
    top = top->next;
    free (tmp);
    return top;
}

void check(Node *top, char str[])
{
    // TH xau chan
    if (strlen(str) % 2 == 0)
    {
        for (int i=0; i<strlen(str); i++)
        {
            if (top == NULL)
            {
                top = push (str[i],top);
                continue;
            }
            if (str[i] == top->s)
            {
                top = pop (top);
            }
            else
            {
                top = push (str[i],top);
            }
        }
        if (top == NULL)
        {
            printf ("Xau doi xung!\n");
            return ;
        }
        printf ("Xau khong doi xung!\n");
    }
    else
    {
        int vi_tri_giua = (int)strlen(str)/2;
        for (int i=0; i<strlen(str); i++)
        {
            if (top == NULL)
            {
                top = push(str[i], top);
                continue;
            }
            if (i == vi_tri_giua)
            {
                continue;
            }
            if (str[i] == top->s)
            {
                top = pop (top);
            }
            else
            {
                top = push (str[i], top);
            }
        }
        if (top == NULL)
        {
            printf ("Xau doi xung!\n");
            return ;
        }
        printf ("Xau khong doi xung!\n");
    }
}


int main()
{
    Node *top = NULL;
    char str[maxlen];
    fflush(stdin);
    gets(str);
    //printf ("%s",str);
    check(top, str);
    return 0;
}
