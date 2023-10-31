#include<iostream>
using namespace std;
#include <vector>

void swap(vector<int>& array, int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int indexOfMinimum(vector<int> array, int startIndex) {
    int minValue = array[startIndex];
    int minIndex = startIndex;

    for(int i = minIndex + 1; i < array.size(); i++) {
        if(array[i] < minValue) {
            minIndex = i;
            minValue = array[i];
        }
    } 
    return minIndex;
}; 

void printArray(vector<int> array)
{
    for(int i=0;i<array.size();i++)
  {
      cout<<array[i]<<" ";
  }
  cout<<endl;
}

void selectionSort(vector<int>& array) {
  // Write this method
  printArray(array);
  for(int i=0;i<array.size();i++)
  {
      swap(array, i, indexOfMinimum(array, i));
      printArray(array);
  }
};

int main() {
    vector<int> nums = {23,5,4,1,9,16};
    selectionSort(nums);
    return 0;
}

/* output
23 5 4 1 9 16 
1 5 4 23 9 16 
1 4 5 23 9 16 
1 4 5 23 9 16 
1 4 5 9 23 16 
1 4 5 9 16 23 
1 4 5 9 16 23 
*/