// Bai tap xau doi xung lam bang ngan xep

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #define maxlen 20
typedef struct List
{
	char s[30];
	int ngay,thang,nam;
	char ten1[20],ten2[20];
	float dungLuong;
	int check;
	
	struct List *next;
} Node;

Node *make_node(char *s)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->next = NULL;
	strcpy(p->s, s);
	char ngay[5],thang[5],nam[5]="";
	char ten1[20],ten2[20];
	char dungLuong[5];
	char check[5];
	strncat(ngay,s+0,2);
	p->ngay = atoi(ngay);
	strcpy(thang,"");
	strncat(thang,s+3,2);
	p->thang = atoi(thang);
	strncat(nam,s+6,4);
	p->nam = atoi(nam);
	return p;
}
// Them vao dau danh sach
Node *insertNode(Node *top, Node *newNode)
{
	Node *p = top;
	if (p == NULL)
	{
		return newNode;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = newNode;
	return top;
}
// checkDateTime tra ve 0 la thoi gian dung, tra ve 1 la thoi gian sai
int checkDateTime (int d,int m)
{
	switch (m)
	{
	case 1:
		if (0<d<31)
		return 0;
		break;
	case 2:
		if (0<d<28)
		return 0;
		break;
	case 3:
		if (0<d<31)
		return 0;
		break;
	case 4:
		if (0<d<30)
		return 0;
		break;
	case 5:
		if (0<d<31)
		return 0;
		break;
	case 6:
		if (0<d<30)
		return 0;
		break;
	case 7:
		if (0<d<31)
		return 0;
		break;
	case 8:
		if (0<d<31)
		return 0;
		break;
	case 9:
		if (0<d<30)
		return 0;
		break;
	case 10:
		if (0<d<31)
		return 0;
		break;
	case 11:
		if (0<d<30)
		return 0;
		break;
	case 12:
		if (0<d<31)
		return 0;
		break;
	default:
		return 1;
		break;
	}
}

int main()
{
	Node *top = NULL;
	char str[30];
	int loop = 1;
	while (loop == 1)
	{
		printf("Nhap xau: ");
		fflush(stdin);
		gets(str);
		fflush(stdin);
		top = insertNode(top, make_node(str));
		printf ("%d-%d-%d\n",top->ngay,top->thang,top->nam);
		printf ("Continue ??\n");
		scanf ("%d",&loop);
		
	}

	printf("Check = %d\n",checkDateTime(top->ngay,top->thang));
	return 0;
}
