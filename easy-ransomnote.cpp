#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> magazineLetters;
        map<char,int> ransomNoteLetters;
        bool isPossible = true;
        if(ransomNote.length()> magazine.length())
            return false;
        for(auto ch : magazine)
        {
            if(magazineLetters.find(ch)== magazineLetters.end())
                magazineLetters.insert(pair<char,int>(ch,0));
            else
            {
                auto it = magazineLetters.find(ch);
                it->second = it->second + 1;
            }
        }
        for(auto ch : ransomNote)
        {
            if(ransomNoteLetters.find(ch)== ransomNoteLetters.end())
                ransomNoteLetters.insert(pair<char,int>(ch,0));
            else
            {
                auto it = ransomNoteLetters.find(ch);
                it->second = it->second + 1;
            }
        }
        cout<<ransomNoteLetters.size()<<" "<<magazineLetters.size()<<endl;
        for(auto it= ransomNoteLetters.begin();it!=ransomNoteLetters.end();it++)
        {
            auto it2= magazineLetters.find(it->first);
            if(it2 == magazineLetters.end())
            {
                isPossible = false;
                break;
            }
            if(it->second > it2->second)
            {
                isPossible = false;
                break;
            }
        }
        return isPossible;
    }
};
int main()
{
    Solution *s = new Solution();
    cout<<s->canConstruct("","abcdefgh");
}