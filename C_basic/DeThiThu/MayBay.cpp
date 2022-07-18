#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct ThanhPho
{
    char str[10];
    int sld;
}Node;

int SoLuongTP;

void XuLyXau (char *str)
{
    int i=0;
    while (str[i]>='0' && str[i] <= '9')
    {
        i++;
    }
    str[i] = '\0';
}

void capNhatSLchuyenbay (Node X[])
{
    for (int i=1; i<=SoLuongTP; i++)
    {
        X[i].sld = strlen(X[i].str);
    }
}

void LoadFile (const char *filename, Node X[])
{
    FILE *f = fopen (filename,"r");
    fscanf (f,"%d\n",&SoLuongTP);
    char str[30];
    int tp, dich;
    while (!feof(f))
    {
        fscanf (f,"%d",&tp);
        fgets (str,30,f);
        dich = 0;
        for (int i=0; i<strlen(str); i++)
        {
            if (str[i] <= '9' && str[i] >= '0')
            {
                X[tp].str[dich] = str[i];
                dich++;
            }
        }
        XuLyXau (X[tp].str);
        tp++;
    }
    capNhatSLchuyenbay(X);
    fclose (f);
}

void Inds (Node X[])
{
    for (int i=1; i<=SoLuongTP; i++)
    {
        printf ("%d\t",i);
        for (int j=0; j<strlen(X[i].str); j++)
        {
            printf ("%c,",X[i].str[j]);
        }
        printf ("\tSlChuyenBay:%d\n",X[i].sld);
    }
}

int slChuyenBay (Node X[])
{
    int sl=0;
    for (int i=1; i<=5; i++)
    {
        sl += X[i].sld;
    }
    return sl;
}

void Xoa (char *str, int index, int last)
{
    for (int i=index; i<last; i++)
    {
        str[i] = str[i+1];
    }
}

void XoaDichDen (Node X[])
{
    printf ("Chon dich den muon xoa!\n");
    char tp;
    fflush(stdin);
    scanf ("%c",&tp);
    fflush(stdin);
    if (tp < '0' || tp > '9')
    {
        printf ("Khong tim thay thanh pho thoa man de xoa!\n");
        return;
    }
    int check = 0;
    for (int i=1; i<=SoLuongTP; i++)
    {
        for (int j=0; j<=strlen(X[i].str); j++)
        {
            if (X[i].str[j] == tp)
            {
                Xoa (X[i].str,j,strlen(X[i].str));
                check++;
            }
        }
    }
    if (check == 0)
    {
        printf ("Khong tim thay thanh pho thoa man de xoa!\n");
        return;
    }
    printf ("Da xoa!\n");
    capNhatSLchuyenbay (X);
}

void ThemDichDen (Node X[])
{
    printf ("Nhap thanh pho muon them vao: ");
    char tpmt;
    fflush(stdin);
    scanf ("%c",&tpmt);
    fflush(stdin);
    printf ("Nhap dich den: ");
    fflush(stdin);
    char dd;
    fflush(stdin);
    scanf ("%c",&dd);
    fflush(stdin);
    if (tpmt < '1' || tpmt >'5')
    {
        printf ("Khong tim thay thanh pho thoa man!\n");
        return;
    }
    // kiem tra xem da co duong di giua 2 tp chua
    for (int i=0; i<strlen(X[tpmt-48].str); i++)
    {
        if (dd == X[tpmt-48].str[i])
        {
            printf ("Da co chuyen bay giua 2 thanh pho nay!\n");
            return;
        }
    }
    X[tpmt-48].str[X[tpmt-48].sld] = dd;
    X[tpmt-48].sld++;
    X[tpmt-48].str[X[tpmt-48].sld+1] = '\0';
}

int main ()
{
    Node X[10];
    
    //Inds (X);
    printf ("%d",slChuyenBay(X));
    //XoaDichDen (X);
    //Inds (X);
    int n; 
    while (1)
    {
        printf("\n====Nhap vao so bat ky de thuc hien chuc nang====\n");
        printf("*  1) Xac dinh so luong cac chuyen bay cua hang       *\n");
        printf("*  2) Xoa di cac tuyen duong bay cua 1 hang     *\n");
        printf("*  3) Them ca tuyen duong bay cua 1 hang          *\n");
        printf("*  4) Tinh toan chi phi di lai   *\n");
        printf("*  5) Thoat.									   *\n");
        printf("*--------------------------------------------------*\n");
        printf("\n\n Nhap lua chon cua ban:   ");
        scanf("%d", &n);
        system("cls");
        if (n == 5)
        {
            printf("\nChuong trinh da ket thuc ");
            exit(0);
        }
        else
        {
            switch (n)
            {
            case 1:
                LoadFile ("X.txt", X);
                printf ("So luong chuyen bay la: %d\n",slChuyenBay(X));
                Inds (X);
                getch();
                fflush(stdin);
                system("cls");
                break;
            case 2:
                XoaDichDen (X);
                Inds (X);
                fflush(stdin);
                getch();
                fflush(stdin);
                system("cls");
                break;
            case 3:
                ThemDichDen (X);
                Inds (X);
                fflush(stdin);
                getch();
                fflush(stdin);
                system("cls");
                break;
            case 4:
                break;
            default :
                printf("\nLua chon khong hop le nhap lai: ");
                fflush(stdin);
                getch();
                fflush(stdin);
                system("cls");
                break;
            }
        }
    }
}
/*
int main ()
{
    Node X[10];
    LoadFile ("X.txt", X);
    Inds (X);
    printf ("%d",slChuyenBay(X));
    XoaDichDen (X);
    //ThemDichDen (X);
    Inds (X);
}
*/