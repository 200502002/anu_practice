#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftMost =0;
        int rightMost = height.size()-1;
        int maxArea = INT_MIN;
        int area;
        while(leftMost<rightMost)
        {
            //cout<<height[leftMost]<<" "<<height[rightMost]<<endl;
            area = min(height[leftMost],height[rightMost]) * (rightMost-leftMost);
            //cout<<area<<endl;
            if(area> maxArea)
                maxArea = area;
            if(height[leftMost] < height[rightMost])
                leftMost ++;
            else
                rightMost--;
        }
        return maxArea;
    }
};

void main()
{
    Solution *s= new Solution();
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<s->maxArea(height);
}