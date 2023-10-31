#include<iostream>
using namespace std;
string substringHasChar(string s, char c)
{
    cout<<"substringHasChar "<<s<<" "<<c<<endl;
    string finalStr;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==c)
        {
            finalStr = s.substr(i+1,s.length()-i-1);
            cout<<"substringHasChar returning "<<finalStr<<endl;
            return finalStr;
        }
    }
    cout<<"substringHasChar returning "<<s<<endl;
    return s;
}
int lengthOfLongestSubstring(string s) {
    string longestSoFar, ans, temp;
    int i;
    for(i=0;i<s.length();i++)
    {
        temp = substringHasChar(longestSoFar, s[i]);
        cout<<"temp is "<<temp<<" longestSoFar is "<<longestSoFar<<endl;
        if(temp == longestSoFar)
        {
            ans= temp.length()>ans.length()? temp:ans;
            cout<<"new ans is "<< ans <<endl;
        }
        longestSoFar = temp + s[i];
    }
    return(ans.length());
}   

int main()
{
    cout<<lengthOfLongestSubstring("pwwkew");
    return 0;
}