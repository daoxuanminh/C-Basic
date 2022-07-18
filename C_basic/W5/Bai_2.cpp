#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct da_thuc
{
    float so_mu;
    float he_so;
    da_thuc *next;
} node;

void sapxep(node **head)
{
    node *i = *head;
    for (i; i != NULL; i = i->next)
    {
        for (node *j = i->next; j != NULL; j = j->next)
        {
            float tg;
            if (i->so_mu < j->so_mu)
            {
                tg = i->he_so;
                i->he_so = j->he_so;
                j->he_so = tg;
                tg = i->so_mu;
                i->so_mu = j->so_mu;
                j->so_mu = tg;
            }
        }
    }
}

void duyet_ds(node *h)
{
    printf("--------------------------------\n");
    node *p = h;
    int i = 0;
    do
    {
        printf("Da thuc thu %d\n", i);
        printf("So mu: %.1f\n", p->so_mu);
        printf("He so: %.1f\n", p->he_so);
        i++;
        p = p->next;
        printf("--------------------------------\n");
    } while (p != NULL);
}

//-------------------------------------------

node *make_node(float so_mu, float he_so)
{
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->he_so = he_so;
    new_node->so_mu = so_mu;
    new_node->next = NULL;
    return new_node;
}
//-------------------------------------------
node *them_dathuc(node *head, float so_mu, float he_so)
{
    node *p = head;
    if (p == NULL)
    {
        return make_node(so_mu, he_so);
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = make_node(so_mu, he_so);
    return head;
}

void nhap_dathuc(node **head)
{
    printf("Nhap so mu: ");
    float so_mu, he_so;
    scanf("%f", &so_mu);
    printf("Nhap he so: ");
    scanf("%f", &he_so);
    *head = them_dathuc(*head, so_mu, he_so);
}
void tinhdathuc(float x, node *head)
{
    float y = 0;
    node *p = head;
    while (p != NULL)
    {
        y += p->he_so * pow(x, p->so_mu);
        p = p->next;
    }
    printf("%.1f\n", y);
}

int main()
{
    node *head = NULL;
    float x;
    nhap_dathuc(&head);
    nhap_dathuc(&head);
    sapxep(&head);
    //printf ("Nhap x = ");
    //scanf ("%f",&x);
    //tinhdathuc (x,head);
    duyet_ds(head);
}