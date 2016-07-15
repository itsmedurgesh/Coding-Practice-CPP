#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


class node{
    public:
        string word;
        node *parent;
        node(string w): word(w), parent(NULL){ }
};


vector<vector<string> > findLadders(string start, string end, vector<string> &dictV) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<string>> ans;
    if(start == end) return ans;

    node *root = new node(start);

    bool found = false;

    unordered_set<string> dict(dictV.begin(), dictV.end());

    unordered_set<string> visited;
    visited.insert(start);

    queue<node*> q;
    q.push(root);

    int width = start.size();
    int minlength = INT_MAX;

    while(!q.empty()){
        node *t = q.front();
        q.pop();
        // visited.erase(t->word);
        for(int i = 0; i < width; ++i){
            for(int j = 0; j < 26; ++j){
                string newword = t->word;
                newword[i] = 'a' + j;
                if(newword == end){
                    vector<string> res1;
                    res1.push_back(newword);
                    node *t2 = t;
                    while(t2){
                        res1.push_back(t2->word);
                        t2 = t2->parent;
                    }
                    if(res1.size() < minlength){
                        reverse(res1.begin(), res1.end());
                        ans.clear();
                        minlength = res1.size();
                        ans.push_back(res1);
                    }
                    else if(res1.size() == minlength){
                        reverse(res1.begin(), res1.end());
                        ans.push_back(res1);
                    }
                }
                else{
                    if(dict.find(newword) != dict.end() && visited.find(newword) == visited.end()){
                        node *t1 = new node(newword);
                        t1->parent = t;
                        visited.insert(newword);
                        q.push(t1);
                    }
                }
            }
        }

    }

    return ans;
}

int main(){
    vector<string> dict{"baba", "abba", "aaba", "bbbb", "abaa", "abab", "aaab", "abba", "abba", "abba", "bbba", "aaab", "abaa", "baba", "baaa"};
    // dict.push_back("ab")

    vector<vector<string> > ans = findLadders("bbaa", "babb", dict);

    for(auto i: ans){
        for(auto j : i) cout<<j<<", ";
        cout<<endl;
    }
}
