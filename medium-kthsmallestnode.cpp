#include<iostream>
using namespace std;
#include <vector>
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
    void inOrderTraversal(TreeNode* root, vector<int>& ans)
    {   
        if(!root)
            return;
        if(root->left ==NULL && root->right==NULL)
        {
            ans.push_back(root->val);
            return;
        };
        if(root->left)
        {
            inOrderTraversal(root->left, ans);
        }
        ans.push_back(root->val);
        if(root->right)
        {
            inOrderTraversal(root->right, ans);        
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        ans.clear();
        inOrderTraversal(root, ans);
        for(int i=0;i<ans.size();i++)
        {
            if(i+1==k)
            {
                return ans[i];
            }
        }
        return -1;
    }
};

int main() {
    Solution *s= new Solution();
    /*tree1
    TreeNode* A=new TreeNode(1);
    TreeNode* B=new TreeNode(3);
    TreeNode* C=new TreeNode(6);
    TreeNode* D=new TreeNode(9);
    TreeNode* E=new TreeNode(2,A,B);
    TreeNode* F=new TreeNode(7,C,D);
    TreeNode* Root=new TreeNode(4,E,F);*/
    /*tree2
    TreeNode* A=new TreeNode(1);
    TreeNode* B=new TreeNode();
    TreeNode* C = new TreeNode();
    TreeNode* D=new TreeNode(3,A,B);
    TreeNode* Root = new TreeNode(2,D,C);*/
    TreeNode* C=new TreeNode(2);
    TreeNode* A=new TreeNode(1, NULL, C);
    TreeNode* B=new TreeNode(4);
    TreeNode* Root = new TreeNode(3,A,B);
    int ans;
    //s->printTreePreOrder(Root);
    //cout<<endl;
    ans = s->kthSmallest(Root, 1);
    cout<<ans<<endl;
    return 0;
}