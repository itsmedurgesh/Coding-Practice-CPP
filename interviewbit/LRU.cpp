#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;
class LRUcache{

    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> used;
    int capacity;
    public:
    LRUcache(int _capacity);
    void set(int key, int value);
    int get(int key);
};

LRUcache::LRUcache(int _capacity){
    used.clear();
    cache.clear();
    capacity = _capacity;
}

void LRUcache::set(int key, int value){
    if(cache.find(key) != cache.end()){
        auto ans = cache[key];
        used.erase(ans.second);
        cache.erase(key);

        used.push_front(key);
        cache[key] = make_pair(value, used.begin());
    }
    else{
        if(used.size() == capacity){
            cache.erase(used.back());
            used.pop_back();
        }

        used.push_front(key);
        cache[key] = make_pair(value, used.begin());   
    }
}

int LRUcache::get(int key){
    if(cache.find(key) == cache.end()) return -1;

    auto ans = cache[key];
    used.erase(ans.second);
    cache.erase(key);

    used.push_front(key);
    cache[key] = make_pair(ans.first, used.begin());
    return ans.first;
}

int main(){
    LRUcache l(4);
    l.set(5, 13);
    l.set(9,6);
    l.set(4,1);
    cout<<l.get(4)<<" ";
    l.set(6,1);
    l.set(8,11);
    cout<<l.get(13)<<" ";
    cout<<l.get(1)<<" ";
    l.set(12,12);
    cout<<l.get(10)<<" ";
    l.set(15,13);
    l.set(2,13);
    l.set(7,5);
    l.set(10,3);
    cout<<l.get(6)<<" ";
    cout<<l.get(10)<<" ";		
    l.set(15,14);
    l.set(5,12);
    cout<<l.get(5)<<" ";
    cout<<l.get(7)<<" ";
}

