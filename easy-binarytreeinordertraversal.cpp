// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>
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
   void inOrderTraversalFill(TreeNode* root, vector<int>& ans)
   {
        if(root==NULL)
            return;
        inOrderTraversalFill(root->left, ans);
        ans.push_back(root->val);
        inOrderTraversalFill(root->right, ans);
   }
   vector<int> inorderTraversalRecursive(TreeNode* root) {
        vector<int> ans;
        inOrderTraversalFill(root, ans);
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> helper;
        if(!root)
            return ans;
        while(root || helper.empty() == false)
        {
            while(root)
            {
                helper.push(root);
                root= root->left;
            }
            root = helper.top();
            helper.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
    
};

int main() {
    Solution *s= new Solution();
    TreeNode* A = new TreeNode(7);
    TreeNode* B = new TreeNode(4);
    TreeNode* C = new TreeNode(2,A,B);
    TreeNode* D = new TreeNode(6);
    TreeNode* E = new TreeNode(0);
    TreeNode* F = new TreeNode(8);
    TreeNode* G = new TreeNode(1,E,F);
    TreeNode* H = new TreeNode(5,D,C);
    TreeNode* Root = new TreeNode(3,H,G);
    TreeNode* ans;
    vector<int> inOrder;
    inOrder = s->inorderTraversal(Root);
    for(int i=0;i<inOrder.size();i++)
    {
        cout<<inOrder[i]<<" ";
    }
    return 0;
}