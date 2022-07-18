#include <stdio.h>
int a[4];
int sum (){
	int check = 0;
	check = a[1]+a[2]+a[3];
	return check;
}
int ghi_loigiai (){
	for (int i=1; i<4; i++){
		printf ("%d  ",a[i]);
	}
	printf ("\n");
}
int UCV (int k, int i){
	if (k==2) return 1;
	if (i < a[k-1]) return 1;
	else return 0;
}
void tim_x (int k){
	for (int i=0; i<=50; ++i){
		if (UCV (k,i) == 1){
			a[k] = i;
			if (k==2) a[k-1] = a[k]*2;
			if (k==3 && sum() == 50) ghi_loigiai ();
			else tim_x (k+1);
		}
	}
}
int main (){
	tim_x (2);
	return 0;
}
