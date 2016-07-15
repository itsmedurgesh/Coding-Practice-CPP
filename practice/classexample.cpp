#include <iostream>

using namespace std;

#define NAME_SIZE 40

class Person{
	char name[NAME_SIZE];

	public:
	
	
	Person(){ cout<<"creating person..\n";}
	virtual ~Person(){ cout<<"destructing person..\n";}
	
	/* making this virtual helps to mimic dynamic dispath as in java
	* and this makes this class abstract
	*/
	virtual void aboutMe(){ cout<<"I am a person..";}
};
	
class Student: public Person{

	public: 
	
	Student(){ cout<<"creating student..\n";}
	~Student(){ cout<<"destructing student..\n";}
	void aboutMe(){ cout<<"I am a student..";}
	
};

int main(){
	Person *p = new Student();
	p->aboutMe();
	delete p;
	return 0;
}
