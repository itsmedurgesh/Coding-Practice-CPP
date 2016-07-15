#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    vector<int> A = {-6, 5, -18, 2, 5, -2};
    vector<int> B = {-17, -16, -17, -4, -13, 20};
    unordered_map<float, int> hash;
    int max = 2;
    
    for(int i = 0; i < A.size()-1; ++i){
        
        for(int j = i+1; j < A.size(); ++j){
            float slope;
            if(A[i] == A[j]) slope = 1E30;
            else{
                slope = (B[j]-B[i])/(A[j]-A[i]);
                long sl = (long)(slope*1000000);
                slope  = (float)sl/1000000;  
            } 
            
            if(hash.find(slope) != hash.end()){
                hash[slope]++;
                if(hash[slope] > max) max = hash[slope];
            }
            else hash[slope] = 2;
        }
        
        hash.clear();
    }
    cout<<max;
}
