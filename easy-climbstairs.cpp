#include<iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        return (climbStairs(n-1)+ climbStairs(n-2)); //Time limit exceeded in leetcode
        /*
        *Accepted Solution
        int* output = new int[n];
        output[0] = 1;
        output[1] = 2;
        for(int i = 2; i < n; i++) {
            output[i] = output[i - 1] + output[i - 2];
        }
        return output[n - 1];
        */
    }
};
int main()
{
    Solution *s = new Solution();
    cout<<s->climbStairs(45);
}