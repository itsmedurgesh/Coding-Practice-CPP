/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {

    // Do not write main() function.

    // Do not read input, instead use the arguments to the function.

    // Do not print the output, instead return values as specified

    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    

    map<int, vector<ListNode*>*> hash;

    

    for(int i = 0; i < A.size(); ++i){

        if(A[i] != NULL){

            if(hash.find(A[i]->val) != hash.end()){

                vector<ListNode*> *tmp = hash[A[i]->val];

                tmp->push_back(A[i]);

            }

            else{

                vector<ListNode*> *tmp = new vector<ListNode*>();

                tmp->push_back(A[i]);

                hash[A[i]->val] = tmp;

            }

        }

    }

    

    ListNode *res= NULL, *r = NULL;

    

    while(true){

        if(hash.size() == 0) break;

        

        int val = hash.begin()->first;

        vector<ListNode*> *tmp = hash[val];

        

        ListNode *t = (*tmp)[tmp->size()-1];

        ListNode *next = t->next;

        

        tmp->pop_back();

        if(tmp->size() == 0) hash.erase(val);

        

        if(next != NULL){

            if(hash.find(next->val) != hash.end()){

                vector<ListNode*> *tmp1 = hash[next->val];

                tmp1->push_back(next);

            }

            else{

                vector<ListNode*> *tmp1 = new vector<ListNode*>();

                tmp1->push_back(next);

                hash[next->val] = tmp1;

            }

        }

        

        if(res == NULL){

            r = t;

            r->next = NULL;

            res = r;

        }

        else{

            r->next = t;

            r = r->next;

            r->next = NULL;

        }

    }

    

    return res;

}
