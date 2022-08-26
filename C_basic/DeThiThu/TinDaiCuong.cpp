#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int dem=1;

void find_path(int mt[][MAX],int y, int n, int ketQua[]){
    int *ucv = mt[y];
    for (int i = 0; i < n; i++)
    {
        if (i==y)
            continue;
        if (ucv[i]==1)
        {
            ketQua[dem] = i;
            dem++;
            if (dem == n)
            {
                return ;
            }
            find_path(mt,i,n,ketQua);
            dem--;
        }
    }
    
}


int main()
{
    int n; // Số lượng các bạn trong nhóm
    int t, s;
    scanf("%d", &n);
    int mt[MAX][MAX];
    int ketQua[n];

    for (int i=0; i<n; i++)
    {
        ketQua[i] = -1;
    }
    // ma trận sau sẽ chứa thông số đến các con đường bằng 1 tức là đi được bằng 0 là không đi được
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mt[i][j] = 1;
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }

    while (1)
    {
        scanf("%d", &t);
        if (getchar() == '$')
            break;
        scanf("%d", &s);
        mt[t][s] = 0;
        mt[s][t] = 0;
    }
    // printf ("Ket thuc nhap!\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf ("%d ",mt[i][j]);
    //     }
    //     printf ("\n");
    // }
    int x;
    printf("Nhap x = ");
    scanf("%d", &x);
    int dem = 0, rs[n];
    for (int i = 0; i < n; i++)
    {
        if (mt[x][i] == 0 && x != (i))
        {
            rs[dem] = i;
            dem++;
        }
    }
    if (dem == 0)
    {
        printf("-1\n");
    }
    else
    {
        for (int i = 0; i < dem; i++)
        {
            printf("%d ", rs[i]);
        }
        printf ("\n");
    }
    int y;
    printf("Nhap y = ");
    scanf("%d", &y);
    find_path(mt,y,n,ketQua);
    for (int i=1; i<n; i++)
    {
        printf ("%d ",ketQua[i]);
    }
    return 0;
}


