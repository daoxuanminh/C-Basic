#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CountNode=0;

typedef struct Node
{
    char hoten[50];
    char ten[50];
    float diem;
    struct Node *pNext;
}Node;
// truyen vao ham con tro head va con tro co thong tin ca nut moi de sap xep chen vao danh sach
Node* insert(Node *pHead, Node* ptr)
{
    if(pHead==NULL)  pHead=ptr;
    else // tìm vi tri chen vao giua/cuoi danh sach
    {
        if(pHead->diem >= ptr->diem) //phan tu moi them dung dau danh sach cu
        {
            ptr->pNext=pHead;
            pHead=ptr; // cap nhat lai dau           
        }       
        else
        { 
            Node *preQ=pHead; // con tro toi phan tu ngay truoc vi tri chen
            Node *q=pHead->pNext; // la con tro toi vi tri chen
            while(q!=NULL && q->diem < ptr->diem)
            {
                  preQ=q;
                  q=q->pNext;
            }
            ptr->pNext=q;  // chen ptr vao sau preQ
            preQ->pNext=ptr;    
        }
    }
    return pHead;
}


// cat ten ra khoi full name
char *cat_ten (char *hoten)
{ 
    int pos=0;
    for (int i=0; i<strlen(hoten); i++)
    {
        if (hoten[i]==' ')
            pos = i+1;
    }
    return &hoten[pos];
}
// tao nut moi va tra ve nut moi
Node* createNode (char hoten[], float diem)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->hoten,hoten);
    strcpy (newNode->ten,cat_ten(hoten));
    //newNode->ten = cat_ten(hoten);
    newNode->diem = diem;
    newNode->pNext = NULL;
    return newNode;
}
// ham duyet danh sach
void duyet_ds (Node* head)
{
    if (head == NULL)
        printf ("Danh sach trong!\n");
    while (head != NULL)
    {
        printf ("%s - %.2f - %s\n",head->hoten, head->diem, head->ten);
        head = head->pNext;
    }   
}



// ham doc danh sach tu file
Node* doc_file (const char file_name[], Node *head)
{
    FILE *f = fopen (file_name, "r");
    fscanf (f,"%d\n",&CountNode);
    char name[50];
    float diem;
    Node* p = NULL;
    while (fscanf (f,"%[^\n]",name) != EOF)
    {
        fscanf (f,"%f\n",&diem);
        p = createNode(name,diem);
        head = insert (head,p);
    }
    fclose (f);
    return head;
}

void in_ra_file (const char fileName[], Node* head)
{
    FILE *f = fopen (fileName, "w");
    fprintf (f,"%d\n", CountNode);
    Node* p = head;
    while (p!=NULL)
    {
        fprintf (f,"%s\n",p->hoten);
        fprintf (f,"%.1f\n",p->diem);
        p=p->pNext;
    }
    fclose (f);
}

Node* BoSungThemNguoi (Node *head)
{
    int n;
    char hoten[50];
    float diem;
    printf ("Nhap so luong nguoi bo sung: ");
    scanf ("%d",&n);
    for (int i=0; i<n; i++)
    {
        printf ("Ho va ten: ");
        fflush (stdin);
        gets (hoten);
        //fflush (stdin);
        printf ("Nhap diem: ");
        scanf ("%f",&diem);
        Node *p = createNode (hoten,diem);
        head = insert(head,p);
    }
    CountNode++;
    return head;
}



int main ()
{
    Node* head = NULL;
    char file_input[] = "input.txt";
    head = doc_file ("input.txt", head);
    duyet_ds (head);
    printf ("======================\n");
    head = BoSungThemNguoi (head);
    duyet_ds (head);
    in_ra_file ("OutputW10.txt", head);
    return 0;
}

/*
    char name1[50] = "NguyenNhuQuy",name2[50] = "Dao xuan Minh";
    char name[50];
    //fflush(stdin);
    //gets(name);
    //printf ("%s", name);
    Node* head = createNode (name2, 14);
    Node *moi = createNode(name1,11);
    head = insert (head,moi);
    duyet_ds (head);
    */