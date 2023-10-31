#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int palindromeLength =0;
        bool roomForExtra = false;
        map<char,int> letterMap;
        for(auto ch: s)
        {
            if(letterMap.find(ch) == letterMap.end())
                letterMap.insert(pair<char,int>(ch,1));
            else
            {
                auto it = letterMap.find(ch);
                it->second = it->second + 1;
            }
        }
        for(auto it = letterMap.begin();it!=letterMap.end();++it)
        {
            if((it->second) >=2)
            {
                cout<<"inside increment loop for "<<it->first<<" "<<it->second<<endl;
                palindromeLength = palindromeLength + ((it->second)/2)*2;
                if((it->second)%2 ==1)
                {
                    roomForExtra = true;
                } 
            }
            else
            {
                cout<<"inside room for extra loop "<<it->first<<" "<<it->second<<endl;
                roomForExtra = true;
            }
        }
        if(roomForExtra == true)
         palindromeLength = palindromeLength +1;
        return palindromeLength;
    }
};
int main()
{
    Solution *s = new Solution();
    cout<<s->longestPalindrome("");
}