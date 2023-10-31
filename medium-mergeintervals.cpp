#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

    void printVectors(vector<vector<int>>& intervals)
    {
        for(int i=0;i<intervals.size();i++)
        {
            cout<<"("<<intervals[i][0]<<","<<intervals[i][1]<<")";
        }
        cout<<endl;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i=0;
        while(i< intervals.size())
        {
            //check if next one is overlapping fully
            if(i+1!= intervals.size() && 
            intervals[i+1][0]>=intervals[i][0] &&
            intervals[i+1][1]<=intervals[i][1])
            {
                intervals.erase(intervals.begin()+i+1);
            }
            //check if next one is insersecting
            else if(i+1!= intervals.size() &&
            intervals[i+1][0]>=intervals[i][0] &&
            intervals[i+1][0]<= intervals[i][1])
            {
                intervals[i][0] = intervals[i][0];
                intervals[i][1] = max(intervals[i][1], intervals[i+1][1]);
                intervals.erase(intervals.begin()+i+1);
            }
            //check if next one is a proper successor
            else if(i+1 != intervals.size() &&
            intervals[i+1][0]> intervals[i][1])
            {
                i++;
            }
            if(i+1 == intervals.size())
            {
                break;
            }
        }
        return intervals;
    }
};
int main()
{
    Solution *s = new Solution();
    vector<vector<int>> intervals;
    vector<int> eachInt;
    /*testcase1*/
    // eachInt.push_back(1);
    // eachInt.push_back(3);
    // intervals.push_back(eachInt);
    // eachInt.clear();
    // eachInt.push_back(6);
    // eachInt.push_back(9);
    // intervals.push_back(eachInt);
    // eachInt.clear();
    // eachInt.push_back(2);
    // eachInt.push_back(5);
    /*testcase2
    //[[1,2],[3,5],[6,7],[8,10],[12,16]]
    eachInt.clear();
    eachInt.push_back(1);
    eachInt.push_back(2);
    intervals.push_back(eachInt);
        eachInt.clear();
    eachInt.push_back(3);
    eachInt.push_back(5);
    intervals.push_back(eachInt);
        eachInt.clear();
    eachInt.push_back(6);
    eachInt.push_back(7);
    intervals.push_back(eachInt);
        eachInt.clear();
    eachInt.push_back(8);
    eachInt.push_back(10);
    intervals.push_back(eachInt);
            eachInt.clear();
    eachInt.push_back(12);
    eachInt.push_back(16);
    intervals.push_back(eachInt);
            eachInt.clear();
    eachInt.push_back(4);
    eachInt.push_back(8);*/
    // test case 3
    eachInt.clear();
    eachInt.push_back(3);
    eachInt.push_back(5);
    intervals.push_back(eachInt);
    eachInt.clear();
    eachInt.push_back(12);
    eachInt.push_back(15);
    intervals.push_back(eachInt);
    eachInt.clear();
    eachInt.push_back(6);
    eachInt.push_back(6);
    intervals.push_back(eachInt);
    s->printVectors(intervals);
    intervals = s->merge(intervals);
    s->printVectors(intervals);
    return 0;
}