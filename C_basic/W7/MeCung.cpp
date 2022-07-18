#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node
{
    int row, col;
    int step;
    struct Node *next;
    struct Node *parent;
} Node;

int n, m;
int r0, c0;
int A[MAX][MAX];

const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, 1, -1};
Node *finalNode;
int visited[MAX][MAX];

Node *head, *tail;
Node *listNode[MAX * MAX];
int szList = 0;

void input()
{
    FILE *f = fopen("maze.txt", "r");
    fscanf(f, "%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf(f, "%d", &A[i][j]);
        }
    }
    fclose(f);
}

void printCurrMaze()
{
    printf("size %d x %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Node *makeNode(int row, int col, int step, Node *parent)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->next = NULL;
    node->parent = parent;
    node->step = step;
    return node;
}

void initQueue()
{
    head = NULL;
    tail = NULL;
}

int queueEmpty()
{
    return head == NULL && tail == NULL;
}

void pushQueue(Node *node)
{
    if (queueEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

Node *popQueue()
{
    if (queueEmpty())
        return NULL;
    Node *node = head;
    head = node->next;
    if (head == NULL)
        tail = NULL;
    return node;
}

int legal(int row, int col)
{
    return A[row][col] == 0 && !visited[row][col];
}

int target(int row, int col)
{
    return row < 1 || row >= n - 1 || col < 1 || col >= m - 1;
}

void finalize()
{
    for (int i = 0; i < szList; i++)
    {
        free(listNode[i]);
    }
}

void addList(Node *node)
{
    listNode[szList] = node;
    szList++;
}
int main()
{
    printf("MAZE\n");
    input();
    printCurrMaze();

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            visited[r][c]=0;
        }
    }
    r0 = 2;
    c0 = 3;
    initQueue();
    Node *startNode = makeNode(r0, c0, 0, NULL);
    addList(startNode);
    pushQueue(startNode);
    visited[r0][c0] = 1;
    while (!queueEmpty())
    {
        Node *node = popQueue();
        printf("POP (%d,%d)\n", node->row, node->col);

        for (int k = 0; k < 4; k++)
        {
            int nr = node->row + dr[k];
            int nc = node->col + dc[k];
            if (legal(nr, nc))
            {
                visited[nr][nc] = 1;
                Node *newNode = makeNode(nr, nc, node->step + 1, node);
                addList(newNode);
                if (target(nr, nc))
                {
                    finalNode = newNode;
                    break;
                }
                else
                    pushQueue(newNode);
            }
        }
        if (finalNode != NULL)
            break;
    }
    Node *s = finalNode;
    while (s != NULL)
    {
        printf("(%d,%d) ", s->row, s->col);
        s = s->parent;
    }
    printf ("\n%d\n",finalNode->step);
    Node *top=NULL;
    while (finalNode->parent == NULL)
    {
        top = finalNode;
    }
    
    finalize();
    return 0;
}