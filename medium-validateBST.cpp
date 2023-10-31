// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
#include<map>
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
    void InOrderTraversal(TreeNode* root, vector<int>& nodesInOrder)
    {
        if(root==NULL)
        {
            return;
        }
        InOrderTraversal(root->left,nodesInOrder);
        nodesInOrder.push_back(root->val);
        InOrderTraversal(root->right,nodesInOrder);
    }
    bool isValidBST(TreeNode* root)
    {
        if(root==NULL)
        {
            return false;
        }
        vector<int> nodesInOrder;
        InOrderTraversal(root, nodesInOrder);
        if(nodesInOrder.size()==1)
        {
            return true;
        }
        int comp = nodesInOrder[0];
        for(int i=1;i<nodesInOrder.size();i++)
        {
            if(nodesInOrder[i]>comp)
            {
                comp = nodesInOrder[i];
            }
            else
            {
                return false;
            }
        }
        return true;        
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
    TreeNode* A = new TreeNode(3);
    TreeNode* B = new TreeNode(5);
    TreeNode* C = new TreeNode(0);
    TreeNode* D = new TreeNode(7);
    TreeNode* E = new TreeNode(9);
    TreeNode* F = new TreeNode(4,A,B);
    TreeNode* G = new TreeNode(8,D,E);
    TreeNode* H = new TreeNode(2,C,F);
    TreeNode* Root = new TreeNode(6,H,G);
    int ans;
    //s->printTreePreOrder(Root);
    //cout<<endl;
    ans = s->isValidBST(Root);
    cout<<ans<<endl;
    return 0;
}