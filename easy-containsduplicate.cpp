#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> countMap;
        bool isDuplicate = false;
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            auto it = countMap.find(nums[i]);
            if (it==countMap.end())
            {
                countMap.insert(pair<int,int> (nums[i],0));                
            }
            else
            {
                it->second ++;
                isDuplicate = true;
                break;
            }            
        }
        if(i==nums.size())
        {
            isDuplicate = false;
        }
        return isDuplicate;
    }
};
int main()
{
    Solution *s = new Solution();
    vector<int> nums = {1,2,3,4,5,6,1};
    cout<<s->containsDuplicate(nums);
    return 0;
}