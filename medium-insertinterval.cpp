#include<iostream>
#include<vector>
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

    void sortProperly(vector<vector<int>>& intervals)
    {
        int i=0;
        // Traverse and make sure everything else is sorted
        while(i<intervals.size())
        {
            if(i+1!= intervals.size() &&
                intervals[i+1][0]<= intervals[i][1])
                {
                    intervals[i][0] = intervals[i][0];
                    intervals[i][1] = max(intervals[i][1], intervals[i+1][1]);
                    intervals.erase(intervals.begin()+i+1);
                }
            else
            {
                //sorted , look for next item
                i++;
            }
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        vector<vector<int>> ans;
        //Corner cases check
        if(intervals.size()==0)
        {
            intervals.push_back(newInterval);
        }
        if(newInterval.size()==0)
        {
            return intervals;
        }
        //Merge fist
        for(i=0;i<intervals.size();i++)
        {
            if(newInterval[0]>=intervals[i][0] &&
                newInterval[0] <= intervals[i][1])
                { 
                    //if there was an overlap
                    intervals[i][0] = intervals[i][0];
                    intervals[i][1] = max(intervals[i][1], newInterval[1]);
                    break;
                }
            else{
                //no overlap
                if(newInterval[0]>= intervals[i][0])
                {
                    //Check if its end of array
                    if(i+1 == intervals.size())
                    {
                        intervals.push_back(newInterval);
                        break;
                    }
                    else if(newInterval[0]<=intervals[i+1][0])
                    {
                        intervals.insert(intervals.begin()+i+1, newInterval);
                        break;
                    }
                }
                else
                {
                    intervals.insert(intervals.begin()+i, newInterval);
                    break;
                }
            }
        }
        cout<<"before sorting\n";
        printVectors(intervals);
        sortProperly(intervals);
        cout<<"after sorting\n";
        printVectors(intervals);  
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
    s->printVectors(intervals);
    intervals = s->insert(intervals,eachInt);
    s->printVectors(intervals);
    return 0;
}