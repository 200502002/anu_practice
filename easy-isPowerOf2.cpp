#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        else
        {
            return((n & n-1) ==0);
        }
    }
    int hammingWeight(uint32_t n) {
        int count =0;
        while(n)
        {
            count++;
            n= (n&n-1);
        }
        return count;
    }   
};
void main()
{
    Solution *s = new Solution();
    uint32_t num = 4294967293;
    //cout<<s->isPowerOfTwo(16);
    cout<<s->hammingWeight(num);
}