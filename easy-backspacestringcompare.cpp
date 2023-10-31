#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string analyze(string s)
    {
        stack<char> finalstrstack;
        string finalstr;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='#')
            {
                if(finalstrstack.empty() !=true)
                    finalstrstack.pop();
            }
            else
            {
                finalstrstack.push(s[i]);
            }
        }
        while(finalstrstack.empty()!= true)
        {
            finalstr = finalstr + finalstrstack.top();
            finalstrstack.pop();
        }
        reverse(finalstr.begin(), finalstr.end());
        return finalstr;
    }
    bool backspaceCompare(string s, string t) {
        string news= analyze(s), newt = analyze(t);
        return news==newt;
    }
};

void main()
{
    Solution *s= new Solution();
    cout<<s->backspaceCompare("","###");
}