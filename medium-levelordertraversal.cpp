// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> thisLevelNodes;
        vector<TreeNode*> nextLevelNodes;
        vector<int> thisLevel;
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        thisLevelNodes.push_back(root);
        while(thisLevelNodes.empty() == false)
        {
            for(int i=0;i<thisLevelNodes.size();i++)
            {
                thisLevel.push_back(thisLevelNodes[i]->val);
                if(thisLevelNodes[i]->left)
                    nextLevelNodes.push_back(thisLevelNodes[i]->left);
                if(thisLevelNodes[i]->right)
                    nextLevelNodes.push_back(thisLevelNodes[i]->right);                               
            }
            ans.push_back(thisLevel);
            thisLevel.clear();
            thisLevelNodes = nextLevelNodes;
            nextLevelNodes.clear();
        }
        return ans;
    }
};

int main() {
    Solution *s= new Solution();
    vector<vector<int>> listOfNodes;
    /*tree1
    TreeNode* A=new TreeNode(1);
    TreeNode* B=new TreeNode(3);
    TreeNode* C=new TreeNode(6);
    TreeNode* D=new TreeNode(9);
    TreeNode* E=new TreeNode(2,A,B);
    TreeNode* F=new TreeNode(7,C,D);
    TreeNode* Root=new TreeNode(4,E,F);*/
    /*tree2*/
    // TreeNode* A=new TreeNode(1);
    // TreeNode* B=new TreeNode();
    // TreeNode* C = new TreeNode();
    // TreeNode* D=new TreeNode(3,A,B);
    // TreeNode* Root = new TreeNode(2,D,C);
        /*tree3*/
    TreeNode* A=new TreeNode(15);
    TreeNode* B=new TreeNode(7);
    TreeNode* D=new TreeNode(9);
    TreeNode* F=new TreeNode(20,A,B);
    TreeNode* Root=new TreeNode(3,D,F);
    listOfNodes = s->levelOrder(Root);
    for(int i=0;i<listOfNodes.size();i++)
    {
        for(int j=0;j<listOfNodes[i].size();j++)
        {
            cout<<listOfNodes[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}