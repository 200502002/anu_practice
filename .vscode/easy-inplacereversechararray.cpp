#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()/2;i++)
        {
            char temp = s[i];
            s[i]=s[s.size()-i-1];
            s[s.size()-i-1]=temp;
        }   
    }
};
void main()
{
    Solution *p = new Solution();
    vector<char> s={'h','e','l','l','o'};
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    p->reverseString(s);
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<" ";
    }
    
}