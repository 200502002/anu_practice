#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void printVector(vector<int> nums)
    {
        for(int i=0;i<nums.size();i++)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(i<nums1.size() && j<n)
        {
            cout<<nums1[i]<<" "<<nums2[j]<<endl;
            if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                nums1.insert(nums1.begin()+i, nums2[j]);
                j++;
            }
            printVector(nums1);
        }
    }
};

void main()
{
    Solution* s = new Solution();
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2 = {2,3,4};
    int m=3, n=3;
    s->merge(nums1,m, nums2,n);
}