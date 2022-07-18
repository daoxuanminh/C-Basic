#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef struct Node
{
    char label;       // identifier of the node struct
    Node *leftChild;  // pointer to the left child struct
    Node *rightChild; // pointer to the right child
} Node;
// ham tao nut moi
// cap phat bo nho dong cho nut moi
Node *makeNode(char label)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->label = label;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}
// them nut moi co nhan la Label thanh con trai/con phai cua nut hien tai
// isLeftChild = 1 --> them vao con trai
// isLeftChild = 0 --> them vao con phai
// nut root phai khac NULL
void insertNode(Node *root, char label, int isLeftChild)
{
    Node *newNode = makeNode(label);
    if (isLeftChild)
        root->leftChild = newNode;
    else
        root->rightChild = newNode;
}
// ham duyet cay theo muc de in ra cac nut lan luot theo muc
// duyet cay theo muc
void levelTraversal(Node *root)
{
    if (NULL == root)
        return;
    queue<Node *> Q;
    Q.push(root);
    while (Q.size() > 0)
    {
        Node *p = Q.front();
        Q.pop();
        printf("%c, ", p->label);
        if (NULL != p->leftChild)
            Q.push(p->leftChild);
        if (NULL != p->rightChild)
            Q.push(p->rightChild);
    }
    printf("\n");
}
// duyet theo thu tu giua
void inorderTraversal(Node *root)
{
    if (NULL == root)
        return;
    inorderTraversal(root->leftChild);
    printf("%c, ", root->label);
    inorderTraversal(root->rightChild);
}

Node *findLabel(Node *root, char label)
{
    if (NULL == root)
        return NULL;
    queue<Node *> Q;
    Q.push(root);

    while (Q.size() > 0)
    {
        Node *p = Q.front();
        Q.pop();
        if (label == p->label)
            return p;
        if (NULL != p->leftChild)
            Q.push(p->leftChild);
        if (NULL != p->rightChild)
            Q.push(p->rightChild);
    }
    return NULL;
}

Node *load(const char* filename){
    Node *root = NULL, *p;
    FILE* f = fopen(filename,"r");
    if (f==NULL) {
        printf("Khong mo duoc file");
        return 0;
    }
    char u;
    while(1)
    {
        fscanf(f,"%c",&u);
        // bo ky tu xuong dong trong file
        if(u=='\r' ||u=='\n') continue;
        if(u == '$') break;// termination
        if(root == NULL) root = makeNode(u);// create the root
        char l,r;
        p = findLabel(root,u);
        fscanf(f,"%c%c",&l,&r);
        if(l !='#') insertNode(p,l,1);
        if(r != '#') insertNode(p,r,0);
    }
    fclose(f);
    return root;
}

int main ()
{
    Node* root = load ("input.txt");
    load ("input.txt");
}

/*
int main()
{
    Node *root = makeNode('=');
    insertNode(root, 'A', 1);
    insertNode(root, '+', 0);
    insertNode(root->rightChild, '3', 1);
    insertNode(root->rightChild, '*', 0);
    insertNode(root->rightChild->rightChild, '/', 1);
    insertNode(root->rightChild->rightChild, '6', 0);
    insertNode(root->rightChild->rightChild->leftChild, '7', 1);
    insertNode(root->rightChild->rightChild->leftChild, '-', 0);
    insertNode(root->rightChild->rightChild->leftChild->rightChild, '3', 1);
    insertNode(root->rightChild->rightChild->leftChild->rightChild, 'b', 0);
    printf("%s", findNode(root, '=')->label);
    levelTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    return 0;
}
*/


