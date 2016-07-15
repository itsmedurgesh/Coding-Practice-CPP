#include <cstdlib>
#include <iostream>

using namespace std;

void* alignedmalloc(size_t bytes, size_t align){
	void* p1;
	void** p2;
	
	int offset = align -1 + sizeof(void*);
	
	if((p1 = (void*)malloc(bytes+offset)) == NULL)
		return NULL;
	
	p2 = (void**)(((size_t)p1 + offset) & ~(align-1));
	
	p2[-1] = p1;

	return p2;
}

void alignedfree(void* p2){
	void* p1 = ((void**)p2)[-1];
	free(p1);
}

int main(){
	void* p;
	
	p = alignedmalloc(100, 16);

	int q = 5;
	
	cout<<p;
	alignedfree(p);
	
	return 0;
}
