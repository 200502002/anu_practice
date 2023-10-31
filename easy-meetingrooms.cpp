#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return true;
        //sortMeetings(vector<vector<iun)
        for(int i=0;i<intervals.size()-1;i++)
        {
            cout<<"comparing tuples "<<intervals[i][0]<<","<<intervals[i][1]<<"with"<<intervals[i+1][0]<<","<<intervals[i+1][1]<<endl;
            if(intervals[i+1][0] < intervals[i][1] && intervals[i+1][0]> intervals[i][0])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> intervals;
    vector<int> tuple;
    /* case 1
    tuple.clear();
    tuple.push_back(0);
    tuple.push_back(30);
    intervals.push_back(tuple);
    tuple.clear();
    tuple.push_back(5);
    tuple.push_back(10);
    intervals.push_back(tuple);
    tuple.clear();
    tuple.push_back(15);
    tuple.push_back(20);
    intervals.push_back(tuple);*/

    /* case 2*/
    tuple.clear();
    tuple.push_back(7);
    tuple.push_back(10);
    intervals.push_back(tuple);
    tuple.clear();
    tuple.push_back(2);
    tuple.push_back(4);
    intervals.push_back(tuple);
    cout<<s->canAttendMeetings(intervals);
}