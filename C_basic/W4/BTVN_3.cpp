#include <stdio.h>
#include <string.h>
char s[20];
char a[20];
int dem[26]={0}; 
void fre (int *dem){
	for (int i=0; i < strlen(s); i++){
		if (s[i] >= 'a' && s[i] <= 'z'){
			dem[s[i]-'a']++;
//			printf ("%d - %d\n",s[i]-'a',dem[s[i]-'a']);
		} 
//		if (s[i] >= 'A' && s[i] <= 'Z') dem[i-'A']++;
	}
}
void in (){
	for (int i=0; i<strlen(a); i++){
		printf ("%c",a[i]);
	}
	printf ("\n");
}
void loi_giai (int k){
	/*
	for (int i=0; i<26; i++){
		if (dem[i]>0) printf ("%d - %d\n",i,dem[i]);
	}
	*/
	for (int i=0; i < 26; i++){
		if (dem[i] != 0){
			a[k] = (char)i+97;
			dem[i]--;
			if (k==(strlen(s)-1)) in();
			else loi_giai (k+1);
			++dem[i];
		}
	}
}
int main (){
	scanf ("%s",&s);
	fre (dem);
	loi_giai (0);
}
