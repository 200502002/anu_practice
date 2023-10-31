#include<iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if((p && !q) || (q && !p))
            return false;
        return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));    
    }
};

void main()
{
    Solution *s = new Solution();
    TreeNode* A = new TreeNode(3);
    TreeNode* B = new TreeNode(4);
    TreeNode* Root1 = new TreeNode(2,A,B);
    TreeNode* C = new TreeNode(3);
    TreeNode* Root2 = new TreeNode(2,C,NULL);
    cout<<s->isSameTree(Root1, NULL);
}