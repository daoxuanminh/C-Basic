#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Thong_tin_SV
{
    char mssv[15];
    char name[30];
    char email[50];
    Thong_tin_SV *next;
} SV;
//-----------------------------------------------------------------------------

void duyet_ds(SV *h)
{
    printf("--------------------------------\n");
    SV *p = h;
    int i = 1;
    do
    {
        printf("Thong tin sinh vien thu %d\n", i);
        printf("MSSV: %s\n", p->mssv);
        printf("Name: %s\n", p->name);
        printf("Email: %s\n", p->email);
        i++;
        printf("--------------------------------\n");
        p = p->next;
    } while (p != NULL);
}
//-----------------------------------------------------------------------------

SV *tao_nut(SV tt)
{
    //char name[30] = {"HaNoi"}, mssv[15] = "001", email[50] = "--@gmail.com";
    SV *new_node = (SV *)malloc(sizeof(SV));
    strcpy(new_node->email, tt.email); //printf ("%s\n",new_node->email);
    strcpy(new_node->mssv, tt.mssv);   //printf ("%s\n",new_node->mssv);
    strcpy(new_node->name, tt.name);   //printf ("%s\n",new_node->name);
    new_node->next = NULL;
    return new_node;
}
//-----------------------------------------------------------------------------

SV *them_cuoids(SV *head, SV tt)
{
    SV *p = head;
    if (p == NULL)
    {
        return tao_nut(tt);
    }
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = tao_nut(tt);
    return head;
}
//-----------------------------------------------------------------------------

// Dung ham fscanf de doc file
SV *doc_file1(char filename[], SV *head, int *so_sv)
{
    FILE *f = fopen(filename, "r");
    fscanf(f, "%d\n", &*so_sv);
    SV thong_tin[(*so_sv)];
    int i = 0;
    while (fscanf(f, "%[^\n]\n", &thong_tin[i].mssv) != EOF)
    {
        fscanf(f, "%[^\n]\n", &thong_tin[i].name);
        fscanf(f, "%[^\n]\n", &thong_tin[i].email);
        // Doc tu file va luu vao cuoi danh sach
        head = them_cuoids(head, thong_tin[i]);
        i++;
    }
    fclose(f);
    return head;
}

//-----------------------------------------------------------------------------
/*
// doc file bang fgets 
SV *doc_file (char filename[], SV *head, int so_sv){
    FILE *f = fopen(filename,"r");
    fscanf (f,"%d\n",&so_sv);   
    SV thong_tin[so_sv];
    int i=0;
    while (fgets (thong_tin[i].mssv,50,f) != NULL)
    {
        fgets(thong_tin[i].name,50,f);
        fgets(thong_tin[i].email,50,f);
        // Doc tu file va luu vao cuoi danh sach
        head = them_cuoids(head,thong_tin[i]);
        i++;
    }
    //head = them_cuoids(head,thong_tin[0]);
    //in_ds1 (thong_tin,so_sv);
    fclose (f);
    return head;
}
*/
//-----------------------------------------------------------------------------

void bosung_ds(SV **head, int *so_sv)
{
    int n; // so sinh vien moi
    printf("Nhap so sinh vien muon bo sung: ");
    scanf("%d", &n);
    *(so_sv) += n;
    SV tt_new[n];
    for (int i = 0; i < n; i++)
    {
        printf("Nhap MSSV: ");
        fflush(stdin);
        gets(tt_new[i].mssv);
        printf("Nhap ten: ");
        fflush(stdin);
        gets(tt_new[i].name);
        printf("Nhap email: ");
        fflush(stdin);
        gets(tt_new[i].email);
        *head = them_cuoids(*head, tt_new[i]);
    }
}
//-----------------------------------------------------------------------------

void ghi_danhsach(SV *head, char file_name[], int *s)
{
    SV *p = head;
    FILE *f = fopen(file_name, "w+");
    fprintf(f, "%d\n", *s);
    do
    {
        fprintf(f, "%s\n", p->mssv);
        fprintf(f, "%s\n", p->name);
        fprintf(f, "%s\n", p->email);
        p = p->next;
    } while (p != NULL);

    fclose(f);
}
//-----------------------------------------------------------------------------

void timkiem_mssv(SV *head)
{
    SV *p = head;
    if (head == NULL)
    {
        printf("Danh sach trong!\n");
        return;
    }
    printf("Nhap mssv cua sinh vien can tim: ");
    char mssv[15];
    fflush(stdin);
    gets(mssv);
    while (p != NULL)
    {
        if (strcmp(p->mssv, mssv) == 0)
        {
            printf("-------------------------------------------------\n");
            printf("Thong tin sinh vien can tim.\n");
            printf("%-15s %-30s %-30s\n", "MSSV", "Ho va ten", "Email");
            printf("%-15s %-30s %-30s\n", p->mssv, p->name, p->email);
            return;
        }
        p = p->next;
    }
    printf("Khong ton tai!\n");
}
//-----------------------------------------------------------------------------
void main ()
{
    int i=0;
    for (int i=0; i<10; i++)
    {
        if (i != 1)
        {
            printf ("Thang quay cam bi ngu moi nguoi thong cam ");
        }
    }
}                                          
int main()
{
    SV *head = NULL;
    int so_sv = 0;
    char filename[15] = "Danhsach.txt";
    int chon = 0;
    while (chon != 5)
    {
    menu:
        printf("MENU:\n");
        printf("1. Doc danh sach tu file\n");
        printf("2. Bo sung them thong tin sinh vien vao cuoi\n");
        printf("3. Ghi noi dung danh sach hien tai ra file\n");
        printf("4. Tim kiem thong tin theo MSSV\n");
        printf("5. Exit\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chon);
        while (chon <= 0 || chon > 5)
        {
            printf("Khong co chuc nang nay!\n");
            printf("Nhan ENTER de nhap lai!");
            getch();
            system("cls");
            goto menu;
        }

        switch (chon)
        {
        case 1:
            system("cls");
            head = doc_file1(filename, head, &so_sv);
            duyet_ds(head);
            printf("Nhan ENTER de quay lai MENU!\n");
            getch();
            system("cls");
            goto menu;
            break;
        case 2:
            system("cls");
            bosung_ds(&head, &so_sv);
            system("cls");
            duyet_ds(head);
            printf("Nhan ENTER de quay lai MENU!\n");
            getch();
            system("cls");
            goto menu;
            break;
        case 3:
            system("cls");
            if (head == NULL)
            {
                printf("Khong co thong tin de ghi vao file!\n");
                printf("Nhan ENTER de quay lai MENU!\n");
                getch();
                system("cls");
                goto menu;
            }
            ghi_danhsach(head, filename, &so_sv);
            printf("Da ghi thanh cong vao file!\n");
            printf("Nhan ENTER de quay lai MENU!\n");
            getch();
            system("cls");
            goto menu;
        case 4:
            system("cls");
            timkiem_mssv(head);
            printf("Nhan ENTER de quay lai MENU!\n");
            getch();
            system("cls");
            goto menu;
        case 5:
            exit(1);
            break;

        default:
            break;
        }
    }
}



// Danh sach 
/*
3
122334
Nguyen Van A
A@gmail.com
232323
Le Thi B
B_le@gmail.com
202020
Dao Xuan Minh
Minh@gmail.com
*/





/*
int main ()
{
    SV *head=NULL;
    int so_sv=0;
    char filename[15] = "Danhsach.txt";
    //timkiem_mssv (head);
    head = doc_file1 (filename,head,&so_sv);
    duyet_ds (head);
    bosung_ds (&head,&so_sv);
    duyet_ds (head);
    printf ("%d\n",so_sv);
    //char file_name_out[50] = "DanhsachOUTPUT.txt";
    ghi_danhsach (head, filename , &so_sv);
    timkiem_mssv (head);
    return 0;
}
*/