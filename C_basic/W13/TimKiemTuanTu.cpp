#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int MAX_VAL = 20000;
// sinh ra mang size phan tu KHONG trung nhau
// dung tim kiem tuan tu de check trung ==> chi phu hop voi size nho
int *generateArr(int size)
{
    int x, check;
    srand(time(NULL));
    int *A = (int *)calloc(sizeof(int), size);
    // sinh ngau nhien va check xem da co phan tu hay chua
    A[0] = rand() % MAX_VAL;
    int numEle = 1;
    while (numEle < size)
    {
        x = rand() % MAX_VAL;
        // check bang tim kiem tuan tu
        check = 0;
        for (int i = 0; i < numEle; i++)
            if (A[i] == x)
            {
                check = 1;
                break;
            }
        if (check == 0)
        // neu khong bi trung --> them vao
        {
            A[numEle] = x;
            numEle++;
        }
    }
    return A;
}
// tim xem trong day co ton tai 2 sô a+b=b
// thuạt toan dung tim kiem tuan tu
void checkExist(const int *A, int size, int k, int *a, int *b)
{
    int dem = 0;
    for (int i = 2; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] + A[j] == k)
            {
                printf("%d + %d = %d\n", A[i], A[j], k);
            }
        }
    }
}
void printArr(const int *A, int size)
{
    printf("Mang hien tai:\n");
    for (int i = 0; i < size; i++)
        printf("%d, ", A[i]);
    printf("\n");
}


int main()
{
    int *A = NULL;
    int size = 10000, k, a, b;
    printf("Nhap k = ");
    scanf("%d", &k);
    if (size >= MAX_VAL || k > 2 * MAX_VAL)
    {
        printf("Check lai tham so!");
        return -1;
    }
    printf("Sinh ra cac so khong lap!\n");
    A = generateArr(size);

    // printArr(A,size);
    printf("Tim kiem so thoa man!\n");
    checkExist(A, size, k, &a, &b);
}