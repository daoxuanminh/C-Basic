#include <stdio.h>
#include <string.h>

char *List[50];
int dem=0;

int main ()
{
    char str[] = "  Dao  Xuan    Minh ";
    int size = strlen(str);
    for (int i=0; i<size; i++)
    {
        if (str[i] == ' ')
            str[i] = '\0';
    }
    for (int i=0; i<size; i++)
    {
        if (str[i]!='\0')
        {
            List[dem] = &str[i];
            dem ++;
            i+=strlen(List[dem-1]);
        }
    }
    printf ("-%s-",List[0]);
    printf ("-%s-",List[1]); 
    printf ("-%s-",List[2]); 
    
}