#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() -1 ;
        int sp = 0 ,fp = 0;
        while(sp!=nums.size()-1)
        {
            fp = sp+1;
            if(fp< nums.size()-1 && nums[sp]==nums[fp] && sp!=fp)
            {
                //found a duplicate
                return nums[sp];
            }
            else
            {
                fp = fp+2;
                sp = sp+1;
            }
        }
        return -1;
    }
};

void main()
{
    Solution *s = new Solution();
    vector<int> nums = {1,3,4,2,2};
    cout<<s->findDuplicate(nums);
}