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
    void printTreePreOrder(TreeNode* root)
    {
        //Pre order traversal
        if(root==NULL)
        {
            //cout<<endl;
            return;
        }
        cout<<root->val<<" ";
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        return 1 + max(maxDepth(root->left), maxDepth(root->right)); 
    }  
    void calculateDiameter(TreeNode* root, int* currentDiameter)
    {
        if(root==NULL)
        {
            return;
        }
        *currentDiameter = max(*currentDiameter, maxDepth(root->left)+maxDepth(root->right));
        calculateDiameter(root->left, currentDiameter);
        calculateDiameter(root->right, currentDiameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0;
        calculateDiameter(root, &ans);
        return ans;
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
    s->printTreePreOrder(Root);
    cout<<endl;
    ans = s->diameterOfBinaryTree(Root);
    cout<<ans<<endl;
    return 0;
}