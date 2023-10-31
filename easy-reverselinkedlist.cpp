#include<iostream>
#include <stack>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
    ListNode* Root;
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> tempStack;
        ListNode* temp = head, *latestNode;
        while(temp&&temp->next)
        {
            tempStack.push(temp);
            temp = temp->next;
        }
        //cout<<tempStack.size()<<endl;
        //temp has the last node
        head = temp;
        while(tempStack.empty() != true)
        {
           // cout<<"temp val now is "<< temp->val<<endl;
            while(temp->next!=NULL)
            {
                //cout<<"temp val now is "<< temp->val<<endl;
                temp = temp->next;
            }
            //cout<<"temp val now is "<< temp->val<<endl;
            temp->next = tempStack.top();
            temp->next->next = NULL;
            //cout<<"temp val now is "<< temp->val<<endl;
            tempStack.pop();
           // cout<<"size now "<<tempStack.size()<<endl;
            temp = head;
           // cout<<"temp val now is "<< temp->val<<endl;
        }
        //Root= temp;
        //printList();
        return head;
    }
    ListNode* makeList()
    {
        ListNode* A = new ListNode(4);
        ListNode* B = new ListNode(3,A);
        ListNode* C = new ListNode(2,B);
        ListNode* D = new ListNode(1,C);
        Root = D;
        //printList();
        return Root;
    }
    void printList()
    {
        ListNode* temp = Root;
        while(temp)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Solution *s = new Solution();
    s->reverseList(s->makeList());
    s->printList();
}