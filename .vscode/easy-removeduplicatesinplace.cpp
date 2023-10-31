#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int hypindex = -1;
        int lastnum = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j< nums.size();j++)
            {
                cout<<nums[j]<<" ";
            }
            cout<<endl;
            if(i+1==nums.size())
            {
                if(nums[i]!=lastnum && hypindex!=-1)
                {
                    //swap
                    int temp = nums[hypindex];                    
                    nums[hypindex] = nums[i];
                    nums[i] = temp;                    
                }
                continue;
            }
            if(nums[i]==nums[i+1])
            {
                nums[i+1] = '~';
                hypindex = i+1;
                lastnum = nums[i];
            }
            else{
                if(nums[i+1] == lastnum)
                {
                    nums[i+1]='~';
                }
                else
                {
                    //swap if there was a duplicate before
                    if(hypindex!=-1)
                    {
                        int temp = nums[hypindex];
                        lastnum = nums[i+1];
                        nums[hypindex] = nums[i+1];
                        nums[i+1] = temp;
                        hypindex ++;
                    }
                }
            }
        }
        auto it = find(nums.begin(), nums.end(),'~');
        return ( it-nums.begin());
    }
};

void main()
{
    Solution *s= new Solution();
    vector<int> nums = {-50,-50,-49,-48,-47,-47,-47,-46,-45,-43,-42,-41,-40,-40,-40,-40,-40,-40,-39,-38,-38,-38,-38,-37,-36,-35,-34,-34,-34,-33,-32,-31,-30,-28,-27,-26,-26,-26,-25,-25,-24,-24,-24,-22,-22,-21,-21,-21,-21,-21,-20,-19,-18,-18,-18,-17,-17,-17,-17,-17,-16,-16,-15,-14,-14,-14,-13,-13,-12,-12,-10,-10,-9,-8,-8,-7,-7,-6,-5,-4,-4,-4,-3,-1,1,2,2,3,4,5,6,6,7,8,8,9,9,10,10,10,11,11,12,12,13,13,13,14,14,14,15,16,17,17,18,20,21,22,22,22,23,23,25,26,28,29,29,29,30,31,31,32,33,34,34,34,36,36,37,37,38,38,38,39,40,40,40,41,42,42,43,43,44,44,45,45,45,46,47,47,47,47,48,49,49,49,50};
    cout<<s->removeDuplicates(nums);
}