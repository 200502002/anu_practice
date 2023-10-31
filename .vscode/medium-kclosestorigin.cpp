#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int distance(int x, int y)
    {
        cout<<"x is "<<x<<" y is "<<y<<endl;
        return (sqrt((x*x)+(y*y)));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int,vector<vector<int>>> distanceMap;
       // map<int,vector<pair<int,int>>>::iterator it;
       vector<vector<int>> allvals;
       vector<vector<int>> ansPoints;
       vector<int> coords;
        int d=0, count=0;
        for(int i=0;i<points.size();i++)
        {
            d= distance(points[i][0],points[i][1]);
            cout<<"d is "<<d<<endl;
            coords.clear();
            coords.push_back(points[i][0]);
            coords.push_back(points[i][1]);
            distanceMap[d].push_back(coords);
        }
        /*for(auto it = distanceMap.begin(); it!= distanceMap.end();it++)
        {
            cout<<"key is "<<it->first<<endl;
            allvals = it->second;
            for(int i=0;i<allvals.size();i++)
            {
              cout<<allvals[i][0]<<" "<<allvals[i][1]<<endl;
            }
        }*/
        auto it = distanceMap.begin();
        while(count<k && it!=distanceMap.end())
        {
            allvals = it->second;
            for(int i=0;i<allvals.size() && count<k;i++)
            {
                ansPoints.push_back(allvals[i]);
                count++;
            }
            it++;
        }
        return ansPoints;
    }
    void printPoints(vector<vector<int>>& points)
    {
        for(int i=0;i<points.size();i++)
        {
            cout<<points[i][0]<<" "<<points[i][1]<<endl;
        }
    }
};
void main()
{
    Solution *s= new Solution();
    vector<int> coords;
    vector<vector<int>> points;
    int k =1;
    /*testcase1
    coords = {1,3};
    points.push_back(coords);
    coords.clear();
    coords = {-2,2};
    points.push_back(coords);*/

    /*tescase2
    coords = {3,3};
    points.push_back(coords);
    coords.clear();
    coords ={5,-1};
    points.push_back(coords);
    coords.clear();
    coords= {-2,4};
    points.push_back(coords);
    coords.clear();*/

    /*testcase3*/
        coords = {-5,4};
    points.push_back(coords);
    coords.clear();
    coords ={-6,-5};
    points.push_back(coords);
    coords.clear();
    coords= {4,6};
    points.push_back(coords);
    coords.clear();
    //s->printPoints(points);
    s->printPoints(s->kClosest(points, 2));
}
