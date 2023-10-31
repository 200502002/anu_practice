#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>& nums, int left, int right, int num)
{
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(nums[mid]== num)
        {
            return mid;
        }
        else if (nums[mid]>num)
        {
            right = mid -1;
        }
        else
        {
            left = mid +1;
        } 
    }
    return -1;
}
void main()
{
    vector<int> ans = {1,2,3,4,5,6};
    cout<<binarySearch(ans,0,6,6);
}