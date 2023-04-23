#include<bits/stdc++.h>
using namespace std;



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class solution{
public:
   vector<int> printlist(ListNode* head){
    vector<int> v;
    while (head)
    {
        v.push_back(head->val);
        head=head->next;
        /* code */
    }
    reverse(v.begin(),v.end());//反转

   }

};


class Solution {
public:
    vector<int> v;//设成全局变量更方便

    void print(ListNode* cur) {
        //非尾部递归
        //非尾部递归是逆序的，把输出语句放到递归语句的后面。
        if (cur == NULL) return;
        print(cur->next);
        v.push_back(cur->val);
    }

    vector<int> printListReversingly(ListNode* head) {
        print(head);
        return v;
    }
};

//尾递归正序
void print(ListNode* cur) {
    if (cur == NULL) return;
    v.push_back(cur->val);
    print(cur->next);
}