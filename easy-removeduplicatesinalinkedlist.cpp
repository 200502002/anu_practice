#include<iostream>
#include<vector>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while(curr)
        {
            if(curr->next && curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }

    void printList(ListNode* head)
    {
        while(head)
        {
            cout<<head->val<<"->";
            head = head->next;
        }
        cout<<endl;
    }
};  
void main()
{
    Solution *s = new Solution();
    /* testcase 1*/
    ListNode* E=new ListNode(5);
    ListNode* D=new ListNode(5,E);
    ListNode* C=new ListNode(3,D);
    ListNode* B=new ListNode(2,C);
    ListNode* head=new ListNode(1,B);
    /*testcase 2
    ListNode* head = new ListNode(1,NULL);*/
    s->printList(head);
    head=s->deleteDuplicates(head);
    s->printList(head);
}