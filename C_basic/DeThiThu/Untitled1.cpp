#include <stdio.h>

int main ()
{
	for (int i=0; i<113; i++)
	{
		if ((16*i)%113==1)
		{
			printf ("%d",i);
		}
	}
}
