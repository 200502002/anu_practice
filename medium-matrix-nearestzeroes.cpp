#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int m;
    int n;
    bool isBoundary(int a, int b)
    {
        return((a>=0 && a<m) && (b>=0 && b<n));
    }
    bool isMatrixUpdated(vector<vector<int>> &mat)
    {
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==-1)
                {
                    return false;
                }
            }
        }
        return true;
    }
    /// @brief 
    /// @param mat 
    /// @return 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int val=0;
        m = mat.size();
        n= mat[0].size();
        vector<pair<int,int>> vistedIndices;
        vector<pair<int,int>> temp;
        pair<int,int> pos;
        //update zeroes and rest to -1 
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]!=0)
                {
                    mat[i][j]=-1;                                       
                }
                else
                {
                    vistedIndices.push_back(pair<int,int> (i,j)); 
                }
            }
        }
        printMatrix(mat);
        cout<<"looping"<<endl;
        while(isMatrixUpdated(mat) == false)
        {
            val++;
            while(vistedIndices.empty()==false)
            {   
                pos = vistedIndices[vistedIndices.size()-1];
                cout<<"processing "<<pos.first<<" "<<pos.second<<endl;
                if(isBoundary(pos.first -1, pos.second) == true)
                {
                    //left
                    cout<<"updating "<<pos.first-1<<" "<<pos.second<<"with val "<<val<<endl;
                    mat[pos.first-1][pos.second]=mat[pos.first-1][pos.second]==-1?val:mat[pos.first-1][pos.second];
                    temp.push_back(pair<int,int>(pos.first-1, pos.second));
                }
                if(isBoundary(pos.first+1, pos.second) == true)
                {
                    //right
                    cout<<"updating "<<pos.first+1<<" "<<pos.second<<"with val "<<val<<endl;
                    mat[pos.first+1][pos.second]=mat[pos.first+1][pos.second]==-1?val:mat[pos.first+1][pos.second];
                    temp.push_back(pair<int,int>(pos.first+1, pos.second));
                }
                if(isBoundary(pos.first, pos.second -1) == true)
                {
                    //top
                    cout<<"updating "<<pos.first<<" "<<pos.second-1<<"with val "<<val<<endl;
                    mat[pos.first][pos.second-1]=mat[pos.first][pos.second-1]==-1?val:mat[pos.first][pos.second-1];
                    temp.push_back(pair<int,int>(pos.first, pos.second-1));
                }
                if(isBoundary(pos.first, pos.second +1) == true)
                {
                    //bottom
                    cout<<"updating "<<pos.first<<" "<<pos.second+1<<"with val "<<val<<endl;
                    mat[pos.first][pos.second+1]=mat[pos.first][pos.second+1]==-1?val:mat[pos.first][pos.second+1];
                    temp.push_back(pair<int,int>(pos.first, pos.second+1));
                }
                vistedIndices.pop_back();
            }
            vistedIndices = temp;
            temp.clear();
            cout<<"updated with value "<<val<<endl;
            printMatrix(mat);
        }
        return mat;
    }
    void printMatrix(vector<vector<int>>& mat) {
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    }
};
int main()
{
    Solution *s= new Solution();
    /*fill matrix*/
    vector<int> row;
    vector<vector<int>> matrix;
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    matrix.push_back(row);
    row.clear();
    row.push_back(0);
    row.push_back(1);
    row.push_back(0);
    matrix.push_back(row);
    row.clear();
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    matrix.push_back(row);
    row.clear();
    s->printMatrix(matrix);
    s->updateMatrix(matrix);
    s->printMatrix(matrix);
}