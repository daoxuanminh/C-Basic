#include <stdio.h>
#include <string.h>
int n;
int a[10];

int sum (){
	int check=0;
	for (int i = 0; i<n; i++){
		check += a[i];
	}
	return check;
}
int UCV (int k, int i){
	if (k==0 && i == 0) return 0;
	if (a[k-1] <= i ) return 1;
	else return 0; 
}
void in_dapso (){
	for (int i=0;i <n; i++){
		printf ("%d",a[i]);
	}
	printf ("\n");
}
void day_so (int k){
	for (int i=0; i<10; i++){
		if (UCV (k,i) == 1){
			a[k]=i;
			if (k == n-1 ) {
				if (sum() == 9){
					in_dapso ();
				}	
			}
			else day_so (k+1);
		}
	}
}
int main (){
	printf ("n = ");
	scanf ("%d",&n);
	day_so (0);
	return 0;
} 
