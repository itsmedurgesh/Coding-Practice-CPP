#include <iostream>
#include <vector>

using namespace std;

/* this uses counting sort on alphabets at a given index
 *
 */

void counting_sort(vector<string> & ss, int idx){
    int c[27] = {0};
    vector<string> ss1(ss.size());
    
    for(int i=0; i<ss.size(); ++i)
        if(idx < ss[i].length())
            ++c[(int)ss[i].at(idx)-(int)'a' + 1];
        else
            ++c[0];

    for(int i=1; i<27; ++i)
        c[i] += c[i-1];
    
    for(int i = ss.size()-1; i>-1; --i){
        if(idx < ss[i].length()){
            ss1[c[(int)ss[i].at(idx)-(int)'a' +1]-1] = ss[i];
            --c[(int)ss[i].at(idx)-(int)'a' +1];
        }
        else{
            ss1[c[0] -1] = ss[i];
            --c[0];
        }
    }
    
    ss = ss1;
    //return ss1;

}
void sort(vector<string> & ss, int width){
    for(int i = width-1; i>-1; --i)
        counting_sort(ss, i);
    
    //return ss;
}
int main(){

    vector<string> ss = {"ab", "a", "b","aaa", "aa", "dfes", "baaa"};
    
    sort(ss, 4);

    for(string s: ss)
        cout<<s<<endl;


}
