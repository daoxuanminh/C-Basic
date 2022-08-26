#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500
struct path
{
    char path[MAX];


    
    double time;
};
typedef struct path path;

int main()
{
    double total_time = 0;

    char strInput[MAX]="";
    path list[MAX];
    int n = -1;
    do
    {
        n++;
        // nhap duong dan va thoi gian
        gets(strInput);
        if (strcmp(strInput,"$")==0)
        {
            break;
        }
        int i = 0;
        while (strInput[i]!=' ')
        {
            list[n].path[i] = strInput[i];
            // printf ("i=%d\n",i);
            i++;
        }
        
        list[n].time = atof(&strInput[i+1]);
        // printf("%s %.2lf\n", list[n].path, list[n].time);
    }
    while(1);

    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            if (strcmp(list[j - 1].path, list[j].path) > 0)
            {
                path temp;
                temp = list[j - 1];
                list[j - 1] = list[j];
                list[j] = temp;
            }
        }
    printf("%d %lf\n", n, total_time);
    for (int i = 0; i < n; i++)
    {
        printf("%s \t%.2lf\n", list[i].path, list[i].time);
    }
}