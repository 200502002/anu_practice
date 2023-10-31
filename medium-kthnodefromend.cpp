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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prevToN, *nPtr, *thisPtr, *copyPrevToN;
        if(!head)
        {
            return NULL;
        }
        prevToN = new ListNode(-1,head);
        copyPrevToN = prevToN;
        nPtr = head;
        thisPtr = head;
        //First put thisPtr n places ahead
        int count = 0;
        while(count<n && thisPtr!=NULL)
        {
            thisPtr = thisPtr->next;
            count++;
        }
        if(count!=n && thisPtr == NULL)
        {
            //able to reach NULL before going to nth node
            return head;
        }
        while(thisPtr!=NULL)
        {
            thisPtr= thisPtr->next;
            nPtr = nPtr->next;
            copyPrevToN = copyPrevToN->next;
        }
        copyPrevToN->next = nPtr->next;
        return prevToN->next;        
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
    ListNode* D=new ListNode(4,E);
    ListNode* C=new ListNode(3,D);
    ListNode* B=new ListNode(2,C);
    ListNode* head=new ListNode(1,B);
    /*testcase 2
    ListNode* head = new ListNode(1,NULL);*/
    s->printList(head);
    head=s->removeNthFromEnd(head,2);
    s->printList(head);
}