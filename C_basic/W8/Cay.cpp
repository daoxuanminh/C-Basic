#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct Node
{
    char name[256];
    struct Node *leftMostChild;
    struct Node *rightSibling;
} Node;
// cap phat bo nho de luu tru nut moi // gan ten va gia tri leftmostchild, rightsibling la NULL
Node *makeNode(const char *name)
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->name, name);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
// tim va tra ve nut co gia tri la keyname
// neu name khong co tren cay --> tra ve NULL // tim de quy = DFS, thoi gian co O(n)
Node *find(Node *r, const char *keyname)
{
    if (r == NULL)
        return NULL;
    if (strcmp(r->name, keyname) == 0)
        return r;
    // neu khong bang --> tim tiep tai cay con cua nut hien tai
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        Node *q = find(p, keyname);
        if (q != NULL)
            return q;
        p = p->rightSibling;
    }
}
// them keyname la anh chi em nho nhat cua nut hien tai
// se la anh chi em phai nhat trong cac nut con --> duyet toi con phai nhat hien tai
// sau do se add them vao cuoi
Node *addLast(Node *p, const char *keyname)
{
    // cap phat nut moi va gan vao
    if (p == NULL)
        return makeNode(keyname);
    // di chuyen toi anh chi em phai nhat hien tai
    p->rightSibling = addLast(p->rightSibling, keyname);
    return p;
}
// them keyname la anh chi em nho nhat cua nut hien tai khong de quy
Node *addLast_loop(Node *p, const char *keyname)
{
    Node *newChild = makeNode(keyname);
    while (p->rightSibling != NULL)
        p = p->rightSibling;
    p->rightSibling = newChild;
}
// them nut child la con nho nhat cua parent
void addChild(Node *root, const char *parent, const char *child)
{
    Node *r = find(root, parent);
    if (r == NULL)
        return;
    r->leftMostChild = addLast(r->leftMostChild, child);
}
// ham them con cua nut hien tai khong de quy
void addChild_loop(Node *root, const char *parent, const char *child)
{
    Node *r = find(root, parent);
    if (r == NULL)
        return;
    // tao nut con moi
    Node *newChild = makeNode(child);
    // neu nut r chua co con
    if (r->leftMostChild == NULL)
        r->leftMostChild = newChild;
    else // neu da co con thi them vao con nho nhat
    {
        Node *p = r->leftMostChild;
        while (p->rightSibling != NULL)
            p = p->rightSibling;
        p->rightSibling = newChild;
    }
}

void printTreeF_loop(Node *root, const char *filename)
{
    if (root == NULL)
        return;
    FILE *f = fopen(filename, "w");
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *r = Q.front();
        Q.pop();
        fprintf(f, "%s ", r->name);
        Node *p = r->leftMostChild;
        while (p != NULL)
        {
            fprintf(f, "%s ", p->name);
            if (p->leftMostChild != NULL)
                Q.push(p);
            p = p->rightSibling;
        }
        fprintf(f, "$\n");
    }
    fprintf(f, "$$\n");
    fclose(f);
}



void listChildren(Node *root, const char *keyname)
{
    Node *p = find(root, keyname);
    if (p == NULL)
        printf("Not Found %s\n", keyname);
    else
    {
        printf("Found %s with children: ", keyname);
        Node *q = p->leftMostChild;

        while (q != NULL)
        {
            printf("%s ", q->name);
            q = q->rightSibling;
        }
    }
    printf("\n");
}
// hàm tính chiều cao của nút p trên cây
// chieu cao nút lá tính là 0
int height(Node *p)
{
    if (p == NULL)
        return -1;
    int maxH = -1;
    Node *q = p->leftMostChild;
    while (q != NULL)
    {
        int h = height(q);
        maxH = maxH < h ? h : maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}
// hàm dem so nut trên cây
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    // cay khac rong
    int sum = 1;
    // con dầu tiên
    Node *q = root->leftMostChild;
    while (q != NULL)
    {
        sum = sum + countNodes(q);
        q = q->rightSibling;
    }
    return sum;
}
void freeTree(Node *r)
{
    if (r == NULL)
        return;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        Node *sp = p->rightSibling;
        freeTree(p);
        p = sp;
    }
    printf("free node %s\n", r->name);
    free(r);
    r = NULL;
}

Node *doc_file(Node *r, const char filename[])
{
    char Child[20], Parent[20];
    FILE *f = fopen(filename, "r");
    fscanf(f, "%s", Parent);
    r = makeNode(Parent);
    while (strcmp(Parent, "$$") != 0)
    {
        fscanf(f, "%s", Child);
        if (strcmp(Child, "$") != 0)
        {
            addChild(r, Parent, Child);
        }
        else
        {
            fscanf(f, "%s", Parent);
        }
    }
    fclose(f);
    return r;
}

void printTree(Node *r)
{

    if (r == NULL)
        return;
    printf("%s: ", r->name);
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        printf("%s ", p->name);
        p = p->rightSibling;
    }
    printf("\n");
    p = r->leftMostChild;
    while (p != NULL)
    {
        printTree(p);
        p = p->rightSibling;
    }
}
// In ra các nút lá có trong cây
void in_nut_la (Node *r)
{
    if (r == NULL)
        printf ("Cay rong!\n");
    Node *p=r;
    while (p!=NULL)
    {
        if (p->leftMostChild==NULL)
        {
            printf ("%s\n",p->name);
        }
        else 
        {
            Node *q=p->leftMostChild;
            in_nut_la(q);
        }
        p=p->rightSibling;
    }
    
}

int dem_nut_trong_cay (Node *r)
{
    int count=0;
    if (r == NULL)
    {
        printf ("Cay rong!\n");
        return h;  
    }
    Node *p = r->leftMostChild;
    while ()
    {
        /* code */
    }
    
}

int main()
{
    Node *root = NULL;
    root = doc_file(root, "Input.txt");
    printTree(root);
    //printTreeF_loop(root, "Output.txt");
    //printf("So luong nut tren cay la %d\n", countNodes(root));
    //listChildren(root, "Jame");
    //Node *p = find(root, "Jame");
    printf ("\nCac nut la trong cay la: \n");
    in_nut_la (root);
    //printf("Chieu cao nut %s la %d\n", p->name, height(p));
}

/*
int main()
{
    Node *root = makeNode("Jame");
    addChild_loop(root, "Jame", "John");
    addChild_loop(root, "Jame", "Jim");
    addChild_loop(root, "Jame", "Ann");
    addChild_loop(root, "Jame", "Jack");
    addChild_loop(root, "Jim", "Bill");
    addChild_loop(root, "Jim", "Will");
    addChild_loop(root, "Jack", "Elf");
    addChild_loop(root, "Jack", "Nann");
    printTree(root);
    return 0;
}
*/
