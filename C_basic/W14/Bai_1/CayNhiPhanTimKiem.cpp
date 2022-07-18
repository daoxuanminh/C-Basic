#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
using namespace std;
typedef struct TreeNode
{
    int key;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
} NODE;



NODE *search_loop(NODE *root, int searchkey)
{
    while (root != NULL && root->key != searchkey)
        if (searchkey < root->key)
            root = root->leftChild;
        else
            root = root->rightChild;

    return root;
}



// cấp phat bo nho dong cho nut moi
NODE *makeNewNode(int key)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->key = key;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}
// root phai khac NULL
int insert(NODE *root, int key)
{
    NODE *pRoot = root;
    // con tro toi truoc vi tri can chen
    while (true)
    {
        if (pRoot->key == key)
            return -1;
        // duplicate
        if (pRoot->key > key)
        {
            // them vao con trai
            if (pRoot->leftChild == NULL)
            {
                pRoot->leftChild = makeNewNode(key);
                break;
            }
            else
                pRoot = pRoot->leftChild;
        }
        else
        { // them vao con phai
            if (pRoot->rightChild == NULL)
            {
                pRoot->rightChild = makeNewNode(key);
                break;
            }
            else
                pRoot = pRoot->rightChild;
        }
    }
    return 0; // success
}
int remove_node(NODE *&root)
{
    if (root == NULL)
        return -1;
    // remove null
    NODE *ptr = root;
    // remember this node for delete later
    if (root->leftChild == NULL)
        root = root->rightChild;
    else if (root->rightChild == NULL)
        root = root->leftChild;
    else // find the rightmost node on the left sub tree
    {
        NODE *preP = root;
        ptr = root->leftChild;

        while (ptr->rightChild != NULL)
        {
            preP = ptr;
            ptr = ptr->rightChild;
        }
        root->key = ptr->key;
        if (preP == root)
            root->leftChild = ptr->leftChild;
        else
            preP->rightChild = ptr->leftChild;
    }
    free(ptr);
    return 0; // remove success
}
int remove(NODE *&root, int key)
{
    if (root == NULL || key == root->key)
        return remove_node(root);
    else if (key < root->key)
        return remove(root->leftChild, key);
    else
        return remove(root->rightChild, key);
}
void printTree_inorder_rec(NODE *root)
{
    if (NULL == root)
        return;
    printTree_inorder_rec(root->leftChild);
    printf("%d, ", root->key);
    printTree_inorder_rec(root->rightChild);
}

int DocFile(NODE **root, const char *filename)
{
    int N, value;
    FILE *f = fopen(filename, "r");
    fscanf(f, "%d %d", &N, &value);
    *root = makeNewNode(value);
    while (fscanf(f, "%d", &value) != EOF)
    {
        insert(*root, value);
    }
    fclose(f);
    return N;
}

void themKhoa(NODE **root, int *size)
{
    printf("Nhap key muon them: ");
    int key;
    scanf("%d", &key);
    insert(*root, key);
    (*size)++;
}


void TimNODEvaXoa (NODE **root, int *size)
{
    printf ("Nhap key muon xoa: ");
    int key;
    scanf ("%d",&key);
    NODE* p=NULL;
    p = search_loop (*root, key);
    if (p == NULL)
        printf ("Khong tim thay!\n");
    else 
    {
        printf ("Co tim thay!\n");
        remove ((*root),key);
        (*size)--;
    }
}


void duyetGiua (FILE *f, NODE* root)
{
    if (NULL == root)
        return;
    duyetGiua(f, root->leftChild);
    fprintf (f,"%d ",root->key);
    duyetGiua(f, root->rightChild);
}

void GhiFile (NODE *root, int size, const char *fileName)
{
    FILE *f=fopen (fileName,"w");
    fprintf (f,"%d\n",size);
    duyetGiua (f, root);
    fclose (f);
}

int main()
{
    NODE *root = NULL; // them lan luot 7,4,8,2,5,10
    int size = DocFile(&root, "Input.txt");
    printTree_inorder_rec(root);
    
    printf("\n");
    themKhoa (&root, &size);
    printTree_inorder_rec(root);

    printf("\n");
    TimNODEvaXoa (&root, &size);
    printTree_inorder_rec(root);
    
    GhiFile (root, size, "Output.txt");

    /*
    root = makeNewNode(7);
    insert(root, 4);
    insert(root, 8);
    insert(root, 2);
    insert(root, 5);
    insert(root, 10);
    remove(root, 7);
    printf("Cay sau khi xoa 7:\n");
    printTree_inorder_rec(root);
    */
    return 0;
}