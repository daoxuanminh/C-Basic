#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void tesst(int arr[]){
    arr[0]=1;
    arr[1]=2;
}
int main()
{
    char str1[10] = "01:02:12";
    char *str2;
    str2 = &str1[3];
    int arr[] = {0,0};
    // strcpy(str1,&str1[3]);
    tesst(arr);
    printf ("%d %d\n",arr[0],arr[1]);
}