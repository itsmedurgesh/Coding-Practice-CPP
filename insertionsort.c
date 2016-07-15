#include <stdio.h>
/* this is insertion sort
*/
int main(){
	int a[] = {1,5,2,8,4,2,6};

	int length = (int)sizeof(a)/sizeof(int);

	for(int i=1; i<length; i++){
		int j = i-1;
		int key = a[i];
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = key;

	}

	for(int i=0; i<length; i++){
		printf("%d ", a[i]);
	}

}