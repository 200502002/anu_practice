#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int getQuotient(int product, int val)
    {
        int ans=0;
        while(product>0)
        {
            product= product-val;
            ans = ans + 1;
        }
        return ans;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int productSoFar = nums[0];
        ans[0]=productSoFar;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<nums.size() && j!=i;j++)
            {
                ans[i]
            }
        }
    }
};
int main()
{
    Solution *s= new Solution();
    vector<int> ans = {-1,1,0,-3,3};
    ans = s->productExceptSelf(ans);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}