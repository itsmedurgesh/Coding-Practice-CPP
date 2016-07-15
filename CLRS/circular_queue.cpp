#include <iostream>
#include <array>

using namespace std;

class queue{
    array<int, 10> a;
    int head = -1;
    int tail = -1;

public: 
    void enqueue(int d){
        if(isFull()) return;
        
        if(isEmpty()){
            head = 0;
            a[head] = d;
            tail = 0;
            return;
        }    
        head = increment(head);
        a[head] = d;
    }

    int dequeue(){
        if(isEmpty()) return -1;
        int d = a[tail];
        tail = increment(tail);
        if(increment(head) == tail){
            head = -1;
            tail = -1;
        }
        return d;
    }

    int front(){
        if(isEmpty()) return -1;
        
        return a[head];
    }

    inline int increment(int i){
        return (i+1)%10;
    }
    
    inline int decrement(int i){
        --i;
        if(i<0) i+= 10;

        return i;
    }

    bool isEmpty(){
        return (head == -1 && tail == -1);
    }

    bool isFull(){
        return (tail == increment(head));
    }

    void print(){
        if(isEmpty()) return;
        cout<<"queue is: ";
        for(int i = tail; i!=increment(head); i = increment(i))
            cout<<a[i]<<" ";
    }
};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(23);
    q.enqueue(21);
    q.enqueue(62);
    q.enqueue(77);
    q.print();
    
    cout<<"\n"<<q.dequeue()<<endl;
    cout<<"\n"<<q.dequeue()<<endl;
    cout<<"\n"<<q.dequeue()<<endl;
    cout<<"\n"<<q.dequeue()<<endl;
    cout<<"\n"<<q.dequeue()<<endl;
    cout<<"\n"<<q.dequeue()<<endl;
    q.print();
    q.enqueue(62);
    q.enqueue(77);
    q.print();
    


}
