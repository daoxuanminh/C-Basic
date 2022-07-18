#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    char maCP[5];
    float giaMo[10];
    float giaDong[10];
    Node *leftChild;
    Node *rightChild;
    float TBH = 0;
    int soNgayTang = 0;
} Node;
int soCP;
int dem = 0;

Node *makeNewNode(char *maCP, float giaMo, float giaDong)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->maCP, maCP);
    newNode->giaMo[dem] = giaMo;
    newNode->giaDong[dem] = giaDong;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

void insertToTBS(Node **head, Node *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
    }
    if (strcmp(newNode->maCP, (*head)->maCP) < 0)
    {
        insertToTBS(&(*head)->leftChild, newNode);
    }
    if (strcmp(newNode->maCP, (*head)->maCP) > 0)
    {
        insertToTBS(&(*head)->rightChild, newNode);
    }
}

Node *Search(Node *head, char *maCp)
{
    Node *p = head;
    while (p != NULL)
    {
        if (strcmp(maCp, p->maCP) < 0)
        {
            p = p->leftChild;
            continue;
        }
        else if (strcmp(maCp, p->maCP) > 0)
        {
            p = p->rightChild;
            continue;
        }
        else
        {
            return p;
        }
    }
    return NULL;
}

Node *LoadFile(Node *head, const char *filename)
{
    FILE *f = fopen(filename, "r");
    fscanf(f, "%d", &soCP);
    char maCP[5];
    float giaMo, giaDong;
    for (int i = 0; i < soCP; i++)
    {
        fscanf(f, "%s %f %f", &maCP, &giaMo, &giaDong);
        insertToTBS(&head, makeNewNode(maCP, giaMo, giaDong));
    }
    dem++;
    int count = 1;
    Node *p = NULL;
    while (!feof(f))
    {
        fscanf(f, "%s %f %f", &maCP, &giaMo, &giaDong);
        p = Search(head, maCP);
        p->giaDong[dem] = giaDong;
        p->giaMo[dem] = giaMo; 
        if (count % 7 == 0)
        {
            dem++;
        }
        count++;
    }
    fclose(f);
    return head;
}

void duyetDs(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    duyetDs(head->leftChild);

    for (int i = 0; i < 10; i++)
    {
        head->TBH += ((head->giaDong[i] - head->giaMo[i]) / 10);
    }
    printf("%-5s %.3f\n", head->maCP, head->TBH);    
    duyetDs(head->rightChild);
}

void ChucNang3 (Node *head)
{
    if (head == NULL)
    {
        return;
    }
    ChucNang3 (head->leftChild);
    if (head->giaDong[0] > head->giaMo[0] && head->giaDong[1] > head->giaMo[1])
    {
        printf ("%s\n",head->maCP);
    }
    ChucNang3(head->rightChild);
}

char nameCP[7][3];
int demTen = 0;
int max=0;

void ChucNang4 (Node *head)
{
    if (head == NULL)
    {
        return;
    }
    ChucNang4 (head->leftChild);
    int j=0;
    for (int i=0; i<10; i++)
    {
        if (head->giaDong[i] > head->giaMo[i])
        {
            j++;
        }
    }
    if (j>max)
    {
        max = j;
        strcpy (nameCP[demTen],head->maCP);
        demTen++;
    }
    if (j==max)
    {
        strcpy (nameCP[demTen],head->maCP);
        demTen++;
    }
    ChucNang4 (head->rightChild);
}

int main()
{
    Node *head = NULL;
    // head = LoadFile(head,"data.txt");
    Node *q=NULL;
    int n;
    while (1)
    {
        printf("*  Menu\n");
        printf("*  1) Doc file\n");
        printf("*  2) Tim kiem theo ma chung khoan\n");
        printf("*  3) Tim kiem ma chung khoan co xu huong tang\n");
        printf("*  4) Tim ma co so ngay tang lon nhat\n");
        printf("*  5) Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &n);
        fflush(stdin);
        if (n==5)
        {
            printf("Dao Xuan Minh - 20205100\n");
            return 0;
        }
        switch (n)
        {
        case 1:
            head = LoadFile(head,"data.txt");
            printf("%-5s %-8s\n", "MaCP", "TB");
            duyetDs(head);
            printf ("\n");
            break;
        case 2:
            char tenCp[3];
            scanf ("%s",tenCp);
            q = Search (head, tenCp);
            if (q == NULL)
            {
                printf ("Khong tim thay Co Phieu\n");
            }
            else
            {
                float maxDong = q->giaDong[0],minDong = q->giaDong[0];
                for (int i=1; i<10; i++)
                {
                    if (maxDong < q->giaDong[i])
                    {
                        maxDong = q->giaDong[i];
                    }
                    if (minDong > q->giaDong[i])
                    {
                        minDong = q->giaDong[i];
                    }
                }
                printf ("Max gia dong: %.3f\n",maxDong);
                printf ("Min gia dong: %.3f\n",minDong);
            }
            printf ("\n");
            break;
        case 3:
            printf ("Ma co phieu co xu huong tang la:\n");
            ChucNang3 (head);
            printf ("\n");
            break;
        case 4:
            ChucNang4 (head);
            for (int i=0; i<7; i++)
            {
                if (nameCP[i]!=NULL)
                {
                    printf ("%s-%d\n",nameCP[i],max);
                }
            }
            printf ("\n");
            break;
        default:
            printf("Lua chon khong hop le nhap lai:\n");
            break;
        }
    }
}
