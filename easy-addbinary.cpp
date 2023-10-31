#include<iostream>
using namespace std;
class Solution {
public:
    char getCarry(char a, char b, char c)
    {
        cout<<"getCarry a is "<<a<<" b is "<<b<<" c is "<<c<<endl;
        if((a=='1' && b=='1' && c=='0') ||
            (a=='1' && b=='0' && c=='1') ||
            (a=='0' && b=='1' && c=='1') ||
            (a=='1' && b=='1' && c=='1'))
            return '1';
        else
            return '0';
    }
    string getOnesSum(char a, char b, char c)
    {
        cout<<"getOneSum a is "<<a<<" b is "<<b<<" c is "<<c<<endl;
        if((a=='1' && b=='1' && c=='0') ||
            (a=='1' && b=='0' && c=='1') ||
            (a=='0' && b=='1' && c=='1') ||
            (a=='0' && b=='0' && c=='0'))
            return "0";
        else
        {
            return "1";
        }
    }
    string addBinary(string a, string b) {
        char carry ='0';
        int i = a.length()-1;
        int j = b.length()-1;
        string ans, reverseAns;
        while(1)
        {
            cout<<"ans "<<ans<<" carry "<<carry<<endl;
            if(i<0&&j<0)
            {
                break;
            }
            else if(i<0)
            {
                cout<<"handling b ans "<<ans<<" carry "<<carry<<endl;
                ans= ans+getOnesSum('0',b[j],carry);
                carry = getCarry('0',b[j],carry);
                j--;
                
            }
            else if(j<0)
            {
                cout<<"handling a ans "<<ans<<" carry "<<carry<<endl;
                ans= ans+getOnesSum(a[i],'0',carry);
                carry = getCarry(a[i],'0',carry);
                i--;
                cout<<"handling a ans "<<ans<<" carry "<<carry<<endl;
            }
            else{
                                cout<<"handling both ans "<<ans<<" carry "<<carry<<endl;
                ans= ans+getOnesSum(a[i],b[j],carry);
                carry = getCarry(a[i],b[j],carry);
                i--;
                j--;
            }

        }
        cout<<"handling carry ans "<<ans<<" carry "<<carry<<endl;
        if(carry!='0')
            ans = ans + carry;
        cout<<"final ans "<<ans<<" carry "<<carry<<endl;
        reverse(ans.begin(), ans.end());
        return ans;   
    }
};
int main()
{
    Solution *s = new Solution();
    string a = "1111";
    string b= "1111";
    cout<<s->addBinary(a,b);
}