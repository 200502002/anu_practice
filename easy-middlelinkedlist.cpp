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
    ListNode* middleNode(ListNode* head) {
        stack<ListNode*> nodeStack;
        int count = 0;
        ListNode* temp = head;
        while(head)
        {
            nodeStack.push(head);
            count++;
            head = head->next;
        }
        int mid = (count%2==0)?(count/2)+1:(count/2);
        //1,2,3,4,5 mid=3 j =count - (count/2)-1 j=5-2-1
        //1,2,3,4,5,6 mid=4 j=count - (count/2)-1 j=6-3-1
        int j=0;
        while(j<count-(count/2)-1)
        {
            nodeStack.pop();
            j++;
        }
        if(j==count - (count/2) -1)
        {
            return nodeStack.top();
        }
        else{
            return head;
        }
    }
 
    ListNode* makeList()
    {
        ListNode* F = new ListNode(6);
        ListNode* E = new ListNode(5,F);
        ListNode* A = new ListNode(4,E);
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
    s->Root = s->makeList();
    s->printList();
    cout<<s->middleNode(s->Root)->val<<endl;
}