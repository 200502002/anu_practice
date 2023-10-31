#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int i =0;
        int maxLength= 0;
        int len =0;
        int oldMod = INT_MIN;
        while(i<nums.size())
        {
            if(nums[i]> threshold)
            {
                i++;
                len =0;
                oldMod = INT_MIN;
                continue;
            }
            else{
                if(oldMod == INT_MIN)
                {
                    if(nums[i]%2==0)
                    {
                        oldMod =0;
                        len++;
                        if(len>maxLength)
                        {
                            maxLength = len;
                        }
                    }
                }
                else{
                    if(nums[i]%2!=oldMod)
                    {
                        oldMod = nums[i]%2;
                        len++;
                        if(len>maxLength)
                        {
                            maxLength = len;
                        }
                    }
                    else
                    {
                        len =0;
                        oldMod = INT_MIN;
                    }
                }
                i++;
            }
        }
        return maxLength;
    }
};
void main()
{
    Solution *s = new Solution();
    vector<int> nums = {4,10,3};
    cout<<s->longestAlternatingSubarray(nums, 10);
}