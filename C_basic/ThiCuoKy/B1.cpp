#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}typedef TreeNode; 
TreeNode *makeNode(int x)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->val = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int InsertNode(TreeNode **root, TreeNode*p){
    //neu node root khac rong thi thuc hien them vao cay
    if (&root != NULL){
        //neu 2 data cua 2 node bang nhau thi ket thuc
        if ((*root)->val == p->val){
            return 0;
        }
        //neu khoa cua root lon hon khoa cua p thi goi de quy trai
        if ((*root)->val > p->val){
            return InsertNode(&(*root)->left, p);
        }
        else{//neu khoa cua root nho hon khoa cua p thi goi de quy phai
            return InsertNode(&(*root)->right,p);
        }
    }else { //truong hop neu node root la rong thi them node p vao node root
        *root = p;
    }
}

void inorderTraversal(TreeNode *root)
{
    if (NULL == root)
        return;
    inorderTraversal(root->left);
    printf("%d, ", root->val);
    inorderTraversal(root->right);
}
// int sumNumbers(struct TreeNode *root)
// {
// }
int main()
{
    int arr[1000];
    TreeNode *root = NULL;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    printf ("Nhap so node [1;1000]: ");
    scanf ("%d",&N);
    if (N < 1 || N > 1000)
    {
        printf ("So nut khong hop le\n");
        printf ("Ket thuc chuong trinh\n");
        return 0;
    }
    printf ("Nhap gia tri vao mang [0:9]: ");
    for (int i=0; i<N; i++)
    {
        scanf ("%d",&arr[i]);
        if (arr[i] >= 10 || arr[i] < 0)
        {
            printf ("Khong hop le\n");
            i--;
            continue;
        }
        InsertNode (&root,makeNode(arr[i]));
    }
    printf ("& root = %d\n",*root);
    // inorderTraversal (root);
    return 0;
}
