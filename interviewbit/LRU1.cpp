#include <iostream>
#include <unordered_map>
#include <map>


using namespace std;
class LRUCache{
public:
	LRUCache(int capacity);
	int get(int key);
	void set(int key, int value);
};

unordered_map<int, pair<int, int>> cache1;
map<int, int> cache2;
int msize;
int timer = 0;

LRUCache::LRUCache(int capacity) {
    msize = capacity;
    cache1.clear();
    cache2.clear();
}

int LRUCache::get(int key) {
    if(cache1.find(key) == cache1.end()) return -1;
    else{
    	int t = timer++;
    	pair<int, int> ans = cache1[key];
    	cache2.erase(ans.second);
        cache2[t] = key;
        cache1[key] = make_pair(ans.first, t);
        return ans.first;
    }
}

void LRUCache::set(int key, int value) {
    if(cache1.size() < msize){
    	int t = timer++;
    	if(cache1.find(key) == cache1.end()){
    		cache1[key] = make_pair(value, t);
    		cache2[t] = key;
    	}
    	else{
    		pair<int, int> ans = cache1[key];
    		cache2.erase(ans.second);
    		cache1[key] = make_pair(value, t);
    		cache2[t] = key;
    	}
    }else{
    	int t = timer++;
        if(cache1.find(key) != cache1.end()){
        	pair<int, int> ans = cache1[key];
    		cache2.erase(ans.second);
    		cache1[key] = make_pair(value, t);
    		cache2[t] = key; 
        }
        else{
        	int oldtime = cache2.begin()->first;
        	int oldkey = cache2[oldtime];
        	cache1.erase(oldkey);
        	cache2.erase(oldtime);
        	cache1[key] = make_pair(value, t);
        	cache2[t] = key;
        }
    }
}

int main(){
	LRUCache l(4);
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
