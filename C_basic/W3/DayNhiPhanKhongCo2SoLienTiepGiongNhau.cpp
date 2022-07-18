#include <stdio.h>

int a[10];

int UCV (int k, int i){
	if (a[k-1] == i){
		return 0;
	}
	return 1;
}
void doc_loigiai (int n){
	for (int i=0; i<n; i++){
		printf ("%d ",a[i]);
	}
	printf ("\n");
}
void sinh_daynhiphan (int k, int n){
	for (int i = 0; i < 2; i++){
		if (k==0){
			a[k] = i;
			sinh_daynhiphan (k+1,n);
		}
		if (UCV (k,i) == 1 && k != 0){
			a[k] = i;
			if (k == n-1){
				doc_loigiai (n);
			}
			else {
				sinh_daynhiphan(k+1,n);
			}
		}
	}
}
int main (){
	int n=8;
	printf ("Nhap n (n<10): \n");
	//scanf ("%d",&n);
	sinh_daynhiphan (0,n);
	return 0;
} 
