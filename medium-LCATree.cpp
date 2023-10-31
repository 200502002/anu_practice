// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <map>
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
    void buildLineage(TreeNode* root, vector<TreeNode*> &NodesLineage, TreeNode* a)
    {
        TreeNode* temp = root;
        while(1)
        {
            if(temp!=NULL)
            {
                NodesLineage.push_back(temp);
                if(temp==a)
                {
                    break;
                }
                temp = temp-> left;
            }
            else
            {
                NodesLineage.pop_back();
                if(NodesLineage.size()>1)
                {
                    temp= NodesLineage[NodesLineage.size()-1];
                }
                temp = temp->right;
            }
        }
    }
    void printLineage(vector<TreeNode*> NodesLineage)
    {
        for(int i=0;i<NodesLineage.size();i++)
            cout<<NodesLineage[i]->val<<" ";
        cout<<endl;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pNodes;
        vector<TreeNode*> qNodes;
        buildLineage(root, pNodes, p);
        buildLineage(root, qNodes, q); 
        printLineage(pNodes);
        printLineage(qNodes); 
        int i=pNodes.size(),j=qNodes.size(); 
        while(i>1 && j>1 && pNodes[i-1]!=qNodes[j-1])
        {
            if(i>j)
                i--;
            else
                j--;
        }
        cout<<pNodes[i-1]->val<<endl;
        return pNodes[i-1];
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
    //s->printTreePreOrder(Root);
    //cout<<endl;
    ans = s->lowestCommonAncestor(Root,H,G);
    cout<<ans->val<<endl;
    return 0;
}