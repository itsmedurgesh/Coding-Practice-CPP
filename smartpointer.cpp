#include <iostream>
#include <stdio.h>
using namespace std;

template <class T> class SmartPointer{
	T* ref;
	unsigned* refcount;
	
	public:

	SmartPointer(T* ptr){
		ref = ptr;
		refcount = new unsigned;
		*refcount = 1;
	}
	
	SmartPointer(SmartPointer<T> &sptr){
		ref = sptr.ref;
		refcount = sptr.refcount;
		++(*refcount);
	}
	
	SmartPointer<T> & operator=(SmartPointer<T> &sptr){
		if(this == sptr)
			return this;
			
		if(refcount > 0)
			remove();
			
		ref = sptr.ref;
		refcount = sptr.refcount;
		++(*refcount);
		return *this;
	}
	
	~SmartPointer(){
		remove();
	}
	
	T getvalue(){
		return *ref;
	}
	
	unsigned int getrefcount(){
		return *refcount;
	}
	
	protected:
	void remove(){
		--(*refcount);
		if(*refcount == 0){
			delete ref;
			delete refcount;
			ref = NULL;
			refcount = NULL;
		}
	}	
};

int main(){
	int p = 5;
	int *q = &p;
	
	SmartPointer<int>* r = new SmartPointer<int>(q);
	
	SmartPointer<int>* s = new SmartPointer<int>(*r);
	
	SmartPointer<int>* t = s;
	
	delete s, t;
	//delete r;
	
	cout<<r->getvalue()<<": "<<r->getrefcount()<<endl;
	
}
	
