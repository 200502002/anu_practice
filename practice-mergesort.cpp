#include<iostream>
using namespace std;
#include <vector>
void printArray(vector<int> array)
{
    for(int i=0;i<array.size();i++)
  {
      cout<<array[i]<<" ";
  }
  cout<<endl;
}

vector<int> merge(vector<int> array1, vector<int> array2)
{
    vector<int> final;
    //final.resize(array1.size() + array2.size());
    int i=0, j=0;
    cout<<"merging below"<<endl;
    printArray(array1);
    printArray(array2);
    while(i< array1.size() || j < array2.size())
    {
        if(i==array1.size())
        {
            final.push_back(array2[j]);
            j++;
        }
        else if(j==array2.size())
        {
            final.push_back(array1[i]);
            i++;
        }
        else if(array1[i]< array2[j])
        {
            final.push_back(array1[i]);
            i++;
        }
        else if(array1[i]> array2[j])
        {
            final.push_back(array2[j]);
            j++;
        }
    }
    cout<<"after merging"<<endl;
    printArray(final);
    return final;
}

vector<int> mergeSort(vector<int> array)
{
    if(array.size() == 0 || array.size() ==1)
    {
        return array;
    }
    vector<int> firstHalf;
    vector<int> secondHalf;
    firstHalf.assign(array.begin(), array.begin()+ array.size()/2);
    secondHalf.assign(array.begin()+array.size()/2, array.end());
    cout<<"merge sort on below"<<endl;
    printArray(firstHalf);
    printArray(secondHalf);
    return merge(mergeSort(firstHalf), mergeSort(secondHalf));
}

int main() {
    vector<int> nums = {23,5,4,1,9,16};
    printArray(mergeSort(nums));
    return 0;
}