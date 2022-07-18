#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void TongTienHang (unordered_map<string, int> List)
{
    int Sum=0;
    for (auto x : List)
    {
        Sum += x.second;
    }
    printf ("Tong tien = %d\n",Sum);
    printf ("So tien phai tra la: %d\n",Sum*=1.1);
}

void InDS (unordered_map<string, int> List)
{
    for (auto x : List)
    {
        cout << x.first << " : " << x.second << endl;
    }
}

int main ()
{
    unordered_map<string, int> List;
    unordered_map<string, int>::iterator p;
    int soluong,gia;
    char ten[30];
    FILE *f = fopen("Input5.txt","r");
    fscanf (f,"%d\n",&soluong);
    while (!feof(f))
    {
        fscanf (f,"%s %d\n",&ten,&gia);
        p = List.find(ten);
        if (p==List.end())
        {
            List[ten] = gia;
        }
    }
    fclose (f);
    //In ds
    InDS(List);
    //Tinh tien hang
    TongTienHang (List);
    char choice;
    char tenmoi[30];
    int giamoi;
    do
    {
        printf ("Nhap them hang!\n");
        printf ("Nhap ma sp: ");
        scanf("%s",&tenmoi);
        fflush(stdin);
        printf ("Nhap gia sp: ");
        scanf ("%d",&giamoi);
        fflush(stdin);
        p = List.find(tenmoi);
        if (p==List.end())
        {
            List[tenmoi] = giamoi;
            soluong++;
            printf ("Them thanh cong!\n");
            printf ("Ban co muon nhap tiep khong(y/n): ");
            scanf ("%c",&choice);
            fflush(stdin);
            continue;
        }
        else
        {
            printf ("Da co mat hang nay!\n");
            printf ("Ban co muon nhap tiep khong(y/n): ");
            scanf ("%c",&choice);
            fflush(stdin);
            continue;
        }
    } 
    while (choice == 'y' || choice =='Y');
    InDS(List);
}