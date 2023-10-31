#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1, i=0, j=0;
        for(i=0;i<s.length() && ans==-1;i++)
        {
            ans = i;
            for(j=0;j<s.length();j++)
            {
                if(s[i]==s[j] && i!=j)
                {
                    ans = -1;
                    break;
                }
            }
        }
        return ans;
    }
};
void main()
{
    Solution* s= new Solution();
    cout<<s->firstUniqChar("leetcode")<<endl;
    cout<<s->firstUniqChar("loveleetcode")<<endl;
    cout<<s->firstUniqChar("aabb")<<endl;
}