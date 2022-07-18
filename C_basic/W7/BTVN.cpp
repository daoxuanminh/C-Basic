#include <iostream>
#include <stack>
#include <string.h>
#define MAX 100

using namespace std;

int m, n;                     // Hàng và cột đọc ra từ file
int A[MAX][MAX], S[MAX][MAX]; //A là ma trận đọc từ file, S là ma trận vừa được dùng để đánh dấu vị trí đã thăm chưa và độ dài đường đi ngắn nhất
int Muc = 0;                  // Đánh dấu độ dài quãng đường ngắn nhất đang được xét
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

typedef struct NODE
{
    int row, col;
} Node;
stack<Node> Queue; // Dùng stack để push vào hàng đợi cho code ngắn gọn và tiện
// Vì bài này ko yêu cầu thứ tự trước sau nên dùng stack đỡ phải viết  lại hàm
void DocFile()
{
    FILE *f = fopen("Input.txt", "r");
    fscanf(f, "%d%d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &A[i][j]);
        }
    }
    fclose(f);
}
// Khởi tạo mảng S để đánh dấu các vị trí đã được thăm hay chưa
void TaoMangDanhDau()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
                //Nếu A[i][j]=1 thì khởi tạo đường đi ngắn nhất là 0
                S[i][j] = 0;
            else
                // Còn các đỉnh chưa thăm thì đánh dấu là -1
                S[i][j] = -1;
        }
    }
}
// In danh sách ma trận
void inDanhSach(int A[][MAX])
{
    printf("========================\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("========================\n");
}
//Tạo 1 node mới
Node MakeNode(int row, int col)
{
    Node newNode;
    newNode.row = row;
    newNode.col = col;
    return newNode;
}
//Danh sách hàng đợi
/*
void DanhSachQueue()
{
    while (!Queue.empty())
    {
        Node temp = Queue.top();
        printf("Hang-Cot: %d-%d\n", Queue.top().row, Queue.top().col);
        Queue.pop();
    }
}
*/
// Dùng stack để cho vào hàng đợi
void PushQueue()
{
    //printf ("Muc = %d\n",Muc);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (S[i][j] == Muc)
                Queue.push(MakeNode(i, j));
        }
    }
}
// Hàm kiểm tra xem ô xung quanh của ô đang được xét đã được thăm hay chưa
int check(int dr, int dc)
{
    int r, c;
    r = Queue.top().row + dr;
    c = Queue.top().col + dc;
    if (S[r][c] == -1)
    {
        // Nếu ô xugn quanh có giá trị bằng -1 thì ô đó chưa được thăm
        return 1;
    }
    return 0;
}

int main()
{

    DocFile();
    TaoMangDanhDau();
    printf("INPUT:\n");
    inDanhSach(A);
    //inDanhSach(S);
    // Đầu tiên ta push vào hàng đợi trước để thỏa mãn điều kiện của vòng lặp
    PushQueue();
    while (!Queue.empty())
    {
        while (!Queue.empty())
        {
            for (int i = 0; i < 4; i++)
            {
                if (check(dr[i], dc[i]) == 1)
                {
                    S[Queue.top().row + dr[i]][Queue.top().col + dc[i]] = Muc + 1;
                }
            }
            Queue.pop();
        }
        Muc++;
        PushQueue();
    }
    printf("OUTPUT:\n");
    inDanhSach(S);
    return 0;
}
