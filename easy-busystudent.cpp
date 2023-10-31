#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int count =0;
        for(int i=0;i<startTime.size();i++)
        {
            if(queryTime>=startTime[i] && queryTime<=endTime[i])
            {
                count++;
            }
        }
        return count;
    }
};

void main()
{
    vector<int> startime = {1,2,3};
    vector<int> endTime = {3,2,7};
    Solution *s = new Solution();
    cout<<s->busyStudent(startime, endTime, 4);
}