#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> countMap;
        int ans = -1;
       // int half = nums.size()%2==1? (nums.size()/2)+1: nums.size()/2;
        for(int i=0;i<nums.size();i++)
        {
            auto it = countMap.find(nums[i]);
            if(it==countMap.end())
            {
                countMap.insert(pair<int,int>(nums[i],1));
            }
            else
            {
                it->second++;
            }
        }
        for(auto it=countMap.begin();it!=countMap.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
            if(it->second > nums.size()/2)
            {
                ans = it->first;
            }            
        }
        return ans;
    }
    int majorityElementWithoutMap(vector<int> nums)
    {
        int count =1;
        int ans = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==ans)
            {
                count++;
            }
            else
            {
                count--;
                if(count==0)
                {
                    ans = nums[i];
                    count = 1;
                }
            }
        }
        cout<<ans<<endl;
        return ans;
    }
};
int main()
{
    Solution *s = new Solution();
    vector<int> nums = {3,2,3};
    cout<<s->majorityElementWithoutMap(nums);
}