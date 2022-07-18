#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

void LoadFile(const char *filename, char *s)
{
    FILE *f = fopen(filename, "r");
    fgets(s, 1000, f);
    fclose(f);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.' || s[i] == ',' || s[i] == '\n')
        {
            s[i] = ' ';
        }
    }
}

char *List[500];
int dem = 0;

void PrintList()
{
    for (int i = 0; i < dem; i++)
    {
        printf("%d-%s-\n", i, List[i]);
    }
}

void ThemListWord(char *str)
{
    int size = strlen(str);
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ')
            str[i] = '\0';
    }
    for (int i = 0; i < size; i++)
    {
        if (str[i] != '\0')
        {
            List[dem] = &str[i];
            dem++;
            i += strlen(List[dem - 1]);
        }
    }
}

int main()
{
    char str[1000];
    LoadFile("InputBai1.txt", str);
    ThemListWord(str);
    string s = List[0];
    // PrintList ();
    // printf ("%d ",count);
    unordered_map<string, int> Hlist;
    unordered_map<string, int>::iterator p;

    string word;
    int lenmax=0;

    for (int i = 0; i < dem; i++)
    {
        p = Hlist.find(List[i]);
        if (p != Hlist.end())
        {
            p->second++;
        }
        else
        {
            Hlist[List[i]] = 1;
            if (strlen(List[i]) > lenmax)
            {
                word = List[i];
                lenmax = strlen(List[i]);
            }
        } 
    }
    int fMax = -1;
    
    for (auto x : Hlist)
    {
        cout << x.first << " : " << x.second << endl;
        if (x.second > fMax)
        {
            fMax = x.second;
        }
    }
    printf ("Tan so Max = %d\n",fMax);
    cout << "Tu dai nhat la: " << word << " - " << lenmax << endl;
}
