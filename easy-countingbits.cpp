#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int val;
        if(n>=0)
            ans.push_back(0); // for 0
        if(n>=1)
            ans.push_back(1); // for 1
        if(n>=2)
            ans.push_back(1); // for 1
        val = 2;
        for(int i=3;i<n;i++)
        {
            val = val ^ i;
            if(val == pow(2,i)-1)
            {
                //xor is equal to 2 power i - 1
            }
        }
    }
};

void main()
{
    Solution *s = new Solution();
    vector<int> ans;
    ans = s->countBits(5);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}

