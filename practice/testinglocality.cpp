/** this program is to show that memory allcotion is JAVA
 * is not guaranteed to be contigous but in c++ it is and 
 * hence we can utilize caching as there is spatial locality
 * in allocation
 */
#include <iostream>
#include <list>
using namespace std;
class Node{
    int data;
    string name;
    public:
    Node(int d, string n): data(d), name(n) {}
    void increment(int d){ data += d;}
};

int main(){
    list<int> v;
    v.push_back(0);
    for(int i = 1; i< 100000; ++i) v.push_back(v.back()+1);
    long sum = 0;

    for(auto it = v.begin(); it!= v.end(); ++it) sum += *it;

    cout<<sum;

    for(int i = 0; i < 100000; ++i){
        Node *p = new Node(i, i+"");
        p->increment(i);
        delete p;
    }


}
