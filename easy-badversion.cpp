#include<iostream>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left= 1;
        int right = n;
        int mid = left+(right-left)/2;
        while(left<right)
        {
            mid = left+(right-left)/2;
            cout<<"mid "<<mid<<" left "<<left<<" right "<<right<<endl;
            if(isBadVersion3(mid))
            {
                //left = 0;
                right = mid-1;
            }
            else
            {
                left= mid +1;
                //right = n;
            }
        }
        cout<<"mid "<<mid<<" left "<<left<<" right "<<right<<endl;
        return left;     
    }
    bool isBadVersion(int n)
    {
        switch(n)
        {
            case 1: return false;
            case 2: return false;
            case 3: return false;
            case 4: return true;
            case 5: return true;
            default: return false;
        }
        return false;
    }
    bool isBadVersion2(int n)
    {
        switch(n)
        {
            case 1: return true;
            default: return false;
        }
        return false;
    }
    bool isBadVersion3(int n)
    {
        switch(n)
        {
            case 2: return true;
            default: return false;
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    cout<<s->firstBadVersion(2);
}