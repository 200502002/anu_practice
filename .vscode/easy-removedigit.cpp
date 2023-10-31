#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    string removeDigit(string number, char digit) {
        stringstream ss;
        string temp;
        int num, max=INT_MIN;
        int i=number.find(digit);
        while(i<number.length()&& i!=string::npos)
        {
           // cout<<i<<endl;
            if(i==0)
            {
                //cout<<i<<" "<<number.substr(i+1)<<endl;
                temp = number.substr(i+1);
            }
            else
            {
                //cout<<i<<" "<<number.substr(0,i)<<" "<<number.substr(i+1, number.length())<<endl;
                temp= number.substr(0,i)+number.substr(i+1, number.length());
            }
            ss.str("");
            ss.clear();
            ss<<temp;
            ss>>num;
            if(num>max)
            {
                max= num;
            }
            i= number.find(digit, i+1);
        }
        ss.str("");
        ss.clear();
        ss<<max;
        return ss.str();
    }
};

void main()
{
    Solution *s = new Solution();
    cout<<s->removeDigit("2998589353917872714814599237991174513476623756395992135212546127959342974628712329595771672911914471",'3');
}