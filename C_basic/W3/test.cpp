#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
typedef struct Danhba{
	char sdt[15];
	char name[100];
	int type;
}DB;
int main ()
{
	DB *ls;
	FILE *f;
	int n,a;
	f = fopen ("DanhBa.dat","rb");
	a = fread (&n,sizeof (int),1,f);
	ls = (DB*) calloc(n,sizeof(DB));
	printf ("Doc Thanh  cong %d phan tu tu file\n",a);
	printf ("Phan tu doc duoc n = %d\n",n);
	a = fread (ls,sizeof (DB),n,f);
	printf ("%s\n%s\n%d",ls[0].name,ls[0].sdt,ls[0].type);	fclose (f);
}
