#include <iostream>
#include <cstdlib>
using namespace std;

/* this function allocates first rows int* and then for each int* allocates cols*int for storing all
	colums
	*/
int** _2Dmalloc(int rows, int cols){

	int** rowptr = (int**)malloc(rows*sizeof(int*));
	for(int i=0;i<rows;i++){
		rowptr[i] = (int*)malloc(cols*sizeof(int));
	}
	return rowptr;
}

/* we can not simply call free(rowptr) because our array is fragmented and we only have location of starting of
each row in rowptr array
*/
void _2Dfree(int** rowptr, int rows, int cols){
	for(int i=0; i<rows; i++)
		free(rowptr[i]);
	free(rowptr);
}


/* this implementation helps as we can call free(rowptr) as memory is not fragmented and we can free all
location from rowptr
*/

int** _2Dallocnew(int rows, int cols){
	int** rowptr = (int**)malloc(rows*sizeof(int*) + rows*cols*sizeof(int));
	for(int i=0; i<rows; i++)
		// rowptr + rows typecasted to int* because first rows spaces are of int* type in memory
		rowptr[i] = (int*)(rowptr + rows) + cols*i;
	return rowptr;
}

void fillarray(int** a, int rows, int cols){
	int k=0;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++)
			a[i][j] = k++;
	}
}

void printarray(int** a, int rows, int cols){
	for(int i=0; i<rows; i++){
		cout<<"\n";
		for(int j=0; j<cols; j++)
			cout<<a[i][j]<<" ";
	}
}

		
int main(){
	int rows = 5, cols = 3;
	
	int** a = _2Dmalloc(rows, cols);
	
	fillarray(a, rows, cols);
	printarray(a, rows, cols);
	
	if(a){
		cout<<"memory address: "<<a;
		_2Dfree(a, rows, cols);
	}
	
	int** b = _2Dallocnew(rows, cols);
	
	cout<<"\n-------------------------------\n";
	fillarray(b, rows, cols);
	printarray(b, rows, cols);
	if(b){
		cout<<"memory address: "<<b;
		free(b);
	}
	
	return 0;
}
	
	
