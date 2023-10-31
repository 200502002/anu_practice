#include<iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        //fix sign
        int sign = 1;
        if((divisor<0 && dividend <0) ||
            (divisor >0 && dividend >0))
            {
                sign = 1;
            }
        else
        {
            sign = -1;
        }

        while(dividend>)
    }
};
void main()
{
    Solution *s = new Solution();
    cout<<s->divide(7,-3)<<endl;
}