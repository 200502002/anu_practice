#include<iostream>
using namespace std;
#include<vector>
#include<map>
class Solution {
public:
    bool isFinished(vector<int>& coursesDone, int courseNum)
    {
        for(int i=0;i<coursesDone.size();i++)
        {
            if(coursesDone[i]==courseNum)
                return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> coursesDone;
        map<int,vector<int>> prereqMap;
        map<int,vector<int>>::iterator it;
        vector<int> coursesInterim, prereqCourses;
        int courseNum = 0;
        for(int i=0;i<prerequisites.size();i++)
        {
            prereqMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        while(coursesDone.size()!= numCourses)
        {
            it = prereqMap.find(courseNum);
            if(it== prereqMap.end())
            {
                if(isFinished(coursesDone, courseNum)== false)
                    coursesDone.push_back(courseNum);
            }
            else
            {
                prereqCourses = it->second;
                for(int i =0 ;i < prereqCourses.size();i++)
                {
                    if(prereqCourses[i]== courseNum)
                    {
                        break;
                    }
                    coursesInterim.push_back(prereqCourses[i]);                    
                }
                while(

            }
        }

    }
};
int main()
{
    Solution *s = new Solution;
    vector<vector<int>> prerequisites;
    prerequisites = {{1,0},{1,8},{2,1},{4,2},{6,2},{8,4}};
    cout<<s->canFinish(8,prerequisites);
}

