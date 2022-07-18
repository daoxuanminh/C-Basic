#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
    char sdt[15];
    char hoten[255];
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
}Node;

Node *makeNewNode (const char *hoten,const char *sdt)
{
    Node *newNode = (Node*)malloc (sizeof(Node));
    strcpy (newNode->hoten,hoten);
    strcpy (newNode->sdt,sdt);
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

void insertToTBS (Node **head, Node* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
    }
    if (strcmp(newNode->sdt,(*head)->sdt)<0)
    {
        insertToTBS(&(*head)->leftChild,newNode);
    }
    if (strcmp(newNode->sdt,(*head)->sdt)>0)
    {
        insertToTBS(&(*head)->rightChild,newNode);
    }
}

void Search (Node *head, const char *sdt)
{
    Node *p = head;
    while (p != NULL)
    {
        if (strcmp(sdt,p->sdt)<0)
        {
            p=p->leftChild;
            continue;
        }
        else if (strcmp(sdt,p->sdt)>0)
        {
            p=p->rightChild;
            continue;
        }
        else
        {
            printf ("Thong tin so dien thoai can tim la:\n");
            printf ("%s - %s\n",p->hoten,p->sdt);
            return;
        }
    }
    printf ("Khong tim thay!\n");
}

int remove_node(Node *&head)
{
    if(head == NULL) return -1; //remove null
    Node *ptr = head; //remember this node for delete later
    
    if(head->leftChild == NULL) head=head->rightChild;
    else if(head->rightChild == NULL) head=head->leftChild;
    else //find the rightmost node on the left sub tree
    {
        Node *preP = head;
        ptr = head->leftChild;
        while(ptr->rightChild != NULL)
        {
            preP = ptr;
            ptr = ptr->rightChild;
        }
        strcpy (head->sdt,ptr->sdt);
        if(preP == head) head->leftChild = ptr->leftChild;
        else preP->rightChild = ptr->leftChild;
        }
        free(ptr);
        return 0;// remove success
}

int Remove(Node*& head, const char *key)
{
    if (head == NULL || strcmp(key, head->sdt)==0) 
        return remove_node(head);
    else if (strcmp(key, head->sdt)<0) 
        return Remove(head->leftChild, key);
    else return Remove(head->rightChild, key);
}

void duyetGiua (FILE *f, Node* head)
{
    if (NULL == head)
        return;
    duyetGiua(f, head->leftChild);
    fprintf (f,"%s\n%s\n",head->hoten,head->sdt);
    duyetGiua(f, head->rightChild);
}

void GhiFile (const char *filename, Node *head)
{
    FILE *f = fopen (filename, "w");
    duyetGiua (f,head);
    fclose (f);
}

void XoaBuff (char *hoten, char *sdt)
{
    for (int i=0; i<strlen(hoten); i++)
    {
        if (hoten[i] == '\n')
            hoten[i] = '\0';
    }
    for (int i=0; i<strlen(sdt); i++)
    {
        if (sdt[i] == '\n')
            sdt[i] = '\0';
    }
}

void DocFile (Node** head, const char *filename)
{
    FILE *f = fopen(filename,"r");
    char hoten[255],sdt[15];
    while (!feof(f))
    {
        fgets (hoten,255,f);
        fgets (sdt,15,f);
        XoaBuff (hoten,sdt);
        insertToTBS (&(*head), makeNewNode(hoten,sdt));
    }
    fclose(f);
}

void duyetDs (Node *head)
{
    if (head==NULL)
    {
        return;
    }
    duyetDs (head->leftChild);
    printf ("%-20s: %-15s\n",head->hoten,head->sdt);
    duyetDs (head->rightChild);
}


int main()
{
    Node *root = NULL;
    DocFile (&root, "input.txt");
    printf ("Danh sach hien tai la:\n");
    duyetDs (root);
    printf ("Nhap sdt muon tim: ");
    char key[15];
    scanf ("%s",key);
    Search (root,key);
    printf ("Nhap sdt muon xoa: ");
    scanf ("%s",key);
    Remove (root, key);
    printf ("Danh sach hien tai la:\n");
    duyetDs (root);
    GhiFile ("DS.txt",root);
}