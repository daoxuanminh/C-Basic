#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
typedef struct DB
{
	char sdt[15];
	char name[100];
	int type; // type = 0: So ca nhan Type =1: So cong ty
}DanhBa;

void DocDanhBa (DanhBa **list, int *size)
{
	int n;
	DanhBa *ls;
	printf ("Nhap so danh ba muon nhap vao: ");
	scanf ("%d",&n);
	*size += n;
	printf ("%d",*size);
	ls = (DanhBa*) calloc(n,sizeof(DanhBa));
	for (int i = 0; i < n; i++)
	{
		printf ("Nguoi thu %d:\n",i+1);
		printf ("Nhap Ho va ten: ");
		fflush (stdin);
		gets (ls[i].name);
		printf ("Nhap SDT: ");
		fflush (stdin);
		gets (ls[i].sdt);
		printf ("Type SDT (Nhap 0 neu la so ca nhan, 1 neu la so cong ty): ");
		scanf ("%d",&ls[i].type);
	}
	*list = ls;
}

void GhiFileNhiPhan (DanhBa **list, int *size, char fileName[])
{
	FILE *f;
	int n;
	if ((f = fopen (fileName,"w+b")) == NULL)
	{
		printf ("Khong mo duoc File!");
		return;
	}
	n = fwrite(size, sizeof(int), 1, f);
	printf ("Doc thanh cong %d phan tu vao file\n",n);
	n = fwrite(*list,sizeof(DanhBa),*size,f);
	printf ("Doc thanh cong %d phan tu vao file\n",n);
	fclose (f);
}

void DocFile (char fileName[], DanhBa **list, int *size)
{
	DanhBa *ls;
	FILE *f;
	int n,a;
	f = fopen (fileName,"rb");
	a = fread (&n,sizeof (int),1,f);
	ls = (DanhBa*) calloc(n,sizeof(DanhBa));
	printf ("Doc Thanh  cong %d phan tu tu file\n",a);
	printf ("Phan tu doc duoc n = %d\n",n);
	a = fread (ls,sizeof (DanhBa),n,f);
	*size = n;
	for (int i = 0; i < n; i++){
		printf ("%s  %s  %d\n",ls[i].name,ls[i].sdt,ls[i].type);	
	}
	fclose (f);
	*list = (DanhBa*) calloc(n,sizeof(DanhBa));
	*list = ls;
	
}
void TraCuuThongTinTheoSDT (DanhBa **list, int *size)
{
	char SDT[15];
	int check=-1,n;
	n=*size;
	DanhBa *ls;
	ls = *list;
	printf ("Nhap SDT can tim: ");
	fflush (stdin);
	scanf ("%s",&SDT);
	int i=0;
	for (i=0; i<n; i++)
	{
		if (strcmp (ls[i].sdt,SDT) == 0)
		{
			check = i;
			break;
		}
	}
	if (check != -1)
	{
		printf ("Thong tin SDT: %s\n",SDT);
		printf ("%-30s %-5s\n","Ho va ten","Loai Contact");
		printf ("%-30s %-5d\n",&ls[check].name,ls[check].type);
	}
	else
	{
		printf ("Khong tin thay thong tin SDT!\n");
	}
}

int main()
{
	DanhBa *db;
	int Size;
//	DocDanhBa (&db,&Size);
//	GhiFileNhiPhan (&db, &Size,"Danhba.dat");
	system ("cls");
	DocFile ("Danhba.dat",&db, &Size);
	getch ();
	system ("cls");
	TraCuuThongTinTheoSDT (&db,&Size);
}

