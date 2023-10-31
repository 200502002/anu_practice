#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        bool f=false;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    f=true;
                    break;
                }
            }
            if(f==true)
                break;
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> twoSumVector;
        vector<vector<int>> finalAns;
        vector<int> threeSumVector;
        vector<int> newNums;
        for(int i=0;i<nums.size();i++)
        {
            newNums.clear();
            newNums.assign(nums.begin()+i+1, nums.end());
            twoSumVector = twoSum(newNums, 0-nums[i]);
            if(twoSumVector.size()!=0)
            {
                threeSumVector.assign(twoSumVector.begin(),twoSumVector.end());
                threeSumVector.push_back(nums[i]);  
                finalAns.push_back(threeSumVector);              
            }
            threeSumVector.clear();
            twoSumVector.clear();
        }
        return finalAns;
    }
    void printThreeSum(vector<vector<int>> nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                cout<<nums[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

void main()
{
    Solution *s = new Solution();
    vector<vector<int>> ans;
    vector<int> nums = {1,0,1,2,-1,-4};
    ans = s->threeSum(nums);
    s->printThreeSum(ans);
}