#include<iostream>
using namespace std;
#include<vector>
#include<bitset>
class Solution {
public:
    vector<int> makeSubsetFromBits(int mask, vector<int>& nums)
    {
        vector<int> ans;
        int size = nums.size();
        int c=0;
        while(c<size)
        {
            if(mask&1)
            {
                ans.push_back(nums[c]);
            }
            mask = mask >> 1;
            c++;
        }
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(nums.size()==0)
        {
            return ans;
        }
        int mask = pow(2,nums.size())-1;
        cout<<bitset<8>(mask)<<endl;
        while(mask<0 == false)
        {
            ans.push_back(makeSubsetFromBits(mask, nums));
            mask = mask -1;
        }
        return ans;         
    }
};

void main()
{
    Solution* s= new Solution();
    vector<int> nums = {1,2};
    vector<vector<int>> ans;
    ans = s->subsets(nums);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"(";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j];
        }
        cout<<")"<<endl;
    }
}