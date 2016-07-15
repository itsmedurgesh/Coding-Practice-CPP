#include <iostream>
#include <set>
#include <functional>
// #include <iterator>
#include <vector>
#include <algorithm>	// contains for_each

using namespace std;

class Lsb_less{
public:
	bool operator() (int x, int y){
		return (x%10) < (y%10);
	}
};

int main(){
	set<int, Lsb_less> s = {3,1,25,7,12};

	for(int i:s) cout<<i<<" ";

	cout<<endl;
	for_each(s.begin(), s.end(), [](int s){ cout<<s<<" ";});
}