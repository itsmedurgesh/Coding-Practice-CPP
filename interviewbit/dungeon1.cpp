/** Logic is not correct in this implementation so this does not work
 * check another program which start from bottom right
 */

#include <iostream>
#include <vector>

using namespace std;

int calculateMinimumHP(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<pair<int, int>>> D(A.size(), vector<pair<int, int>>(A.size()));
    D[0][0] = A[0][0] <= 0 ? make_pair(-A[0][0]+1, 1) : make_pair(0, A[0][0]);
    
    //setting first row
    for(int i = 1; i < A.size(); ++i){
        int health = D[0][i-1].second + A[0][i];
        if(A[0][i] < 0 && health <= 0) D[0][i] = make_pair(D[0][i-1].first - health + 1, 1);
        else D[0][i] = make_pair(D[0][i-1].first, health);
    }
    
    
    // setting first column
    for(int i = 1; i < A.size(); ++i){
        int health = D[i-1][0].second + A[i][0];
        if(A[i][0] < 0 && health <= 0) D[i][0] = make_pair(D[i-1][0].first - health + 1, 1);
        else D[i][0] = make_pair(D[i-1][0].first, health);    
    }
    
    //setting remaining table
    for(int i = 1; i < A.size(); ++i){
        for(int j = 1; j < A.size(); ++j){
            
            pair<int, int> a, b;
            int h1 = D[i][j-1].second + A[i][j]; // left pair
            if(A[i][j] < 0 && h1 <= 0) a = make_pair(D[i][j-1].first - h1 + 1, 1);
            else a = make_pair(D[i][j-1].first, h1);    
            
            int h2 = D[i-1][j].second + A[i][j];   //right pair
            if(A[i][j] < 0 && h2 <= 0) b = make_pair(D[i-1][j].first - h2 + 1, 1);
            else b = make_pair(D[i-1][j].first, h2);
            
            if(a.first < b.first) D[i][j] = a;
            else D[i][j] = b;
        }    
    }
    
    return D[A.size()-1][A.size()-1].first;
}

int main(){
    vector<vector<int>> v = {{-3, 5, -7, -100},{-20, -10, -5, 35},{-30, -5, -2, 10},{-40, -40, 20, -20}};
    cout<<calculateMinimumHP(v)<<endl;
}
