#include<iostream>
#include<algorithm>
using namespace std;
string URLify(string s, int length)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            s.replace(i,1,"%20");
        }
    }
    return s;
}
void main()
{
    cout<< URLify("Mr John Smith",13);
}