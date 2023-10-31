#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
    vector<string> tokens;
    string reverseWords(string s) {
         string temp_str;
         string finalAns= "";
        stringstream ss(s); //convert s into string stream
        while(getline(ss, temp_str,' ')){ //use space as delim for cutting string
        temp_str.erase(remove(temp_str.begin(), temp_str.end(),' '), temp_str.end());
        if(temp_str.length()!=0)
            tokens.push_back(temp_str);
        }
        //cout<<tokens.size()<<endl;
        if(tokens.size()==0)
        {
          //  cout<<finalAns<<endl;
            return finalAns;
        }
        if(tokens.size()==1)
        {
            //cout<<finalAns<<endl;
            return tokens.at(0);
        }
        for(int i=tokens.size()-1;i>=0;i--)
        {
            string s = tokens.at(i);
            if(i==tokens.size()-1)
                finalAns = s;
            else
               finalAns = finalAns +' '+s;
        }
        //cout<<finalAns<<endl;
        return finalAns;
    }
};
void main()
{
    Solution *s = new Solution();
    cout<<s->reverseWords(" hello world ");
}