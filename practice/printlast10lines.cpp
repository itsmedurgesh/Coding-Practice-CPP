#include <iostream>
#include <fstream>

using namespace std;

void printlast10lines(const char* filename){
	const int K = 10;
	
	ifstream file(filename);
	string L[K];
	
	int size = 0;
	
	while(file.good()){
		getline(file, L[size%K]);
		size++;
	}
	
	int start = size>K ? size%K : 0;
	int count = min(K, size);
	
	for(int i=0; i<count; i++){
		cout<<L[(start+i)%K]<<endl;
	}
}

int main(){
	const char* filename = "classexample.cpp";
	printlast10lines(filename);
	
	return 0;
}
