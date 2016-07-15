#include <iostream>
#include <vector>

using namespace std;

double getmedian(const vector<int> &A){
    int mid = (A.size()-1)/2;
    if(A.size()%2) return (double)A[mid];
    else ((double)A[mid] + (double)A[mid+1])/(double)2;
}

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() == 0) return getmedian(B);
    if(B.size() == 0) return getmedian(A);


    int total = A.size() + B.size();
    bool isodd = total%2;

    int s1 = 0, e1 = A.size()-1;
    int s2 = 0, e2 = B.size()-1;

    while(s1 < e1 && s2 < e2){
        int mid1 = (s1+e1)/2;
        int mid2 = (s2+e2)/2;
        if(isodd){
            if(A[mid1] >= B[mid2] && A[mid1] <= B[mid2+1]) return (double)A[mid1];
            if(B[mid2] >= A[mid1] && B[mid2] <= A[mid1+1]) return (double)B[mid2];
        }
        else{
            if(A[mid1] >= B[mid2] && A[mid1] <= B[mid2+1]) {
                if(A[mid1+1] >= B[mid2] && A[mid1+1] <= B[mid2+1])
                    return ((double)A[mid1] + (double)A[mid1+1])/(double)2;
                if(A.size()%2) 
                    return ((double)A[mid1] + (double)B[mid2])/(double)2;
                else
                    return ((double)A[mid1] + (double)B[mid2+1])/(double)2;
            }

            if(B[mid2] >= A[mid1] && B[mid2] <= A[mid1+1]) {
                if(B[mid2+1] >= A[mid1] && B[mid2+1] <= A[mid1+1])
                    return ((double)B[mid2] + (double)B[mid2+1])/(double)2;
                if(A.size()%2) 
                    return ((double)A[mid1] + (double)B[mid2])/(double)2;
                else
                    return ((double)B[mid2] + (double)A[mid1+1])/(double)2;
            }
        }
        if(A[mid1]>=B[mid2+1]){
            e1 = mid1;
            s2 = mid2+1;
        }
        else{
            s1 = mid1+1;
            e2 = mid2;
        }
    }

    return ((double)A[e1]+(double)B[e2])/(double)2;
}

int main(){
    vector<int> A = {-50, -47, -36, -35, 0, 13, 14, 16};
    vector<int> B = {-31, 1, 9, 23, 30, 39};

    cout<<findMedianSortedArrays(A, B)<<endl;
}
