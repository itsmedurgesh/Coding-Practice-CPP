#include <iostream>
#include <array>

using namespace std;

#define N 10

class stack{

    array<int, 10> a;
    int stack1 = 0, stack2 = 9;
    
    public:

    int push(int d, int stack){
        
        if(isFull()) return -1;
        
        if(stack == 1) a[stack1++] = d;
        else a[stack2--] = d;
        return d;
    }
    
    int pop(int stack){
        if(isEmpty()) return -1;
        
        int d;
        if(stack == 1){
           if(stack1 > 0) d = a[--stack1];
           else return -1;
        }
        else{
            if(stack2 < 9) d = a[++stack2];
            else return -1;
        }

        return d;
    }
    
    int top(int stack){
        if(isEmpty()) return -1;

        if(stack == 1) {
            if(stack1 > 0) return a[stack1-1];
            else return -1;
        }
        else{ 
            if(stack2 < 9) return a[stack2+1];
            else return -1;
        }
    }
    
    bool isEmpty(){
        return (stack1==0 && stack2==9);
    }

    bool isFull(){
        return stack1 > stack2;
    }

    void print(){

        cout<<endl;
        cout<<"stack 1: ";
        for(int i = stack1-1; i>-1; --i)
            cout<<a[i]<<" ";

        cout<<"\n"<<"stack 2: ";
        for(int i = stack2+1; i<=9; i++)
            cout<<a[i]<<" ";
    }
};


int main(){

    stack s;
    
    s.print();
    s.push(1,1);
    s.push(23, 2);
    s.push(41,1);
    s.push(21,1);
    s.print();
    cout<<"\n top 1 "<<s.top(1);
    cout<<"top 2 "<<s.top(2);
    cout<<"pop 1 "<<s.pop(1);
    cout<<"pop 2 "<<s.pop(2);
    cout<<"pop 2 "<<s.top(2);
}
