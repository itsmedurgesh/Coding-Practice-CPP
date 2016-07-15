#include <iostream>

using namespace std;

void add(int a[][4], int b[][4], int c[][4], int ra, int ca){
	for(int i=0; i<ra; i++)
		for(int j=0; j<ca; j++)
			c[i][j] = a[i][j] + b[i][j];
}

// we have to use pointers because these arrays motherfuckers dont work with dynamic ranfes
void multiply(int a[][4], int b[][4], int c[][4], int s, int e){
	if(s == e){

	}else{
		int mid = (s+e)/2;
		int *a11 = new int[(mid-s+1)*(mid-s+1)];
		
		multiply(a, b, a11, s, mid);
	}
}


int main(){
	int a[][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}}; 
	int b[][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}}; 


	int ra = sizeof(a)/sizeof(a[0]);
	int ca = sizeof(a[0])/sizeof(int);

	int c[ra][4];

	add(a, b, c, ra, ca);


	for(int i=0; i<ra; i++){
		for(int j=0; j<ca; j++)
			cout<<c[i][j];
		cout<<endl;
	}

}