#include <iostream>

using namespace std;

int** make2darray(int r, int c);

int** add(int** a, int** b, int rows, int cols){
	int** c = make2darray(rows, cols);
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			c[i][j] = a[i][j]+b[i][j];

	return c;
}

void fillarray(int** a, int r, int c){
	for(int i=0; i<r; ++i)
		for (int j = 0; j < c; ++j)
		{
			a[i][j] = i+1;
		}
}

void displayarray(int** a, int r, int c){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; ++j){
			cout<<a[i][j] <<" ";	
		}		
		cout<<endl;
	}
}

int** make2darray(int r, int c){
	int** a = new int*[r];
	for (int i = 0; i < c; ++i)
	{
		a[i] = new int[c];
	}

	return a;
}


// alright this is one fucked up implementation
// gotta rectify this someday
int** multiply(int** a, int** b, int ars, int are, int acs, int ace, int brs, int bre, int bcs, int bce){
	if(ars == are){
		int** c = make2darray(1,1);
		c[0][0] = a[ars][acs]*b[brs][bcs];
		return c;
	}else{
		int amidr = (ars+are)/2;
		int amidc = (acs+ace)/2;
		int bmidr = (brs+bre)/2;
		int bmidc = (bcs+bce)/2;

		int** c11 = make2darray(amidr-ars+1, amidc-acs+1);
		int** c12 = make2darray(amidr-ars+1, ace-amidc);
		int** c21 = make2darray(are-amidr, amidc-acs+1);
		int** c22 = make2darray(are-amidr, ace-amidc);

		c11 = add(multiply(a, b, ars, amidr, acs, amidc, brs, bmidr, bcs, bmidc), 
			multiply(a, b, ars, amidr, amidc+1, ace, bmidr+1, bre, bcs, bmidc),
			amidr-ars+1, amidc-acs+1);
		
		c12 = add(multiply(a, b, ars, amidr, acs, amidc, brs, bmidr, bmidc+1, bce), 
			multiply(a, b, ars, amidr, amidc+1, ace, bmidr+1, bre, bmidc+1, bce),
			amidr-ars+1, ace-amidc);
		
		c21 = add(multiply(a, b, amidr+1, are, acs, amidc, brs, bmidr, bcs, bmidc), 
			multiply(a, b, amidr+1, are, amidc+1, ace, bmidr+1, bre, bcs, bmidc),
			are-amidr, amidc-acs+1);
		
		c22 = add(multiply(a, b, amidr+1, are, acs, amidc, brs, bmidr, bmidc+1, bce), 
			multiply(a, b, amidr+1, are, amidc+1, ace, bmidr+1, bre, bmidc+1, bce),
			are-amidr, ace-amidc);

		int** c = make2darray(are-ars+1, bce-bcs+1);

		for(int i=0; i<amidr-ars+1; ++i)
			for(int j=0; j<amidc-acs+1; ++j)
				c[i][j] = c11[i][j];

		for(int i=0; i<amidr-ars+1; ++i)
			for(int j=amidc-acs+1; j<ace-acs+1; ++j)
				c[i][j] = c12[i][j-amidc-acs+1];
		
		for(int i=amidr+1; i<are; ++i)
			for(int j=0; j<amidc; ++j)
				c[i][j] = c21[i-amidr-1][j];
		
		for(int i=amidr+1; i<are; ++i)
			for(int j=amidc+1; j<ace; ++j)
				c[i][j] = c22[i-amidr-1][j-amidc-1];		

		return c;	

	}
}

int main(){
	int** a;
	int** b;
	int rows = 4, cols = 4;
	a = make2darray(rows, cols);
	b = make2darray(rows, cols);
	
	fillarray(a, rows, cols);
	fillarray(b, rows, cols);

	// int** c = add(a, b, rows, cols);
	int** c = multiply(a, b, 0, 3, 0, 3, 0, 3, 0, 3);
	displayarray(c, rows, cols);

}
