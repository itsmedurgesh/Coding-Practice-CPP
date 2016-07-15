#include <iostream>

using namespace std;

struct res
{
	int s;
	int e;
	int sum;
};

res findmaxarrayAcross(int *a, int low, int mid, int high){
	int lsum = -9999, rsum = -9999;
	int lmax =-1, rmax =-1;
	int sum = 0;
	for(int i = mid; i>= low; --i){
		sum += a[i];
		if(sum > lsum){
			lsum = sum;
			lmax = i;
		}
	}

	sum = 0;
	for (int i = mid+1; i <= high; ++i)
	{
		sum += a[i];
		if(sum > rsum){
			rsum = sum;
			rmax = i;
		}
	}

	res r;
	r.sum = lsum + rsum;
	r.s = lmax;
	r.e = rmax;

	return r;
}


res findmaxarray(int *a, int low,  int high){
	if(low == high){
		res r;
		r.s = low;
		r.e = high;
		r.sum = a[low];
		return r;
	}
	else{
		int mid = (low+high)/2;
		res r1 = findmaxarray(a, low, mid);
		res r2 = findmaxarray(a, mid+1, high);
		res r3 = findmaxarrayAcross(a, low, mid, high);

		if(r1.sum >= r2.sum && r1.sum >= r3.sum)
			return r1;
		else
			if(r2.sum >= r1.sum && r2.sum >= r3.sum)
				return r2;
			else
				return r3;
	}


}



int main(){

	int a[] = {-1, 2, 3, 4, -3, 2, -31};

	res r = findmaxarray(a, 0, 6);

	cout<<r.sum<<endl<<r.s<<endl<<r.e;


}
