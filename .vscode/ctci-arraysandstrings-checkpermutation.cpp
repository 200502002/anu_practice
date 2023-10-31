#include<iostream>
#include<algorithm>
using namespace std;
bool checkPermutation(string s, string t)
{
    sort(s.begin(),s.end());
    sort(t.begin(), t.end());
    return(s==t);
}
void main()
{
    cout<< checkPermutation("madam", "daamme");
}