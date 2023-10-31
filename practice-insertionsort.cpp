#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> array)
{
    for(int i=0;i<array.size();i++)
  {
      cout<<array[i]<<" ";
  }
  cout<<endl;
}

void insertionSort(vector<int> array) {
  for (int step = 1; step < array.size(); step++) {
    int key = array[step];
    int j = step - 1;
    cout<<"handling "<<key<<endl;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
      printArray(array);
    }
    array[j + 1] = key;
    printArray(array);
  }
}

//Write again TODO

int main() {
    vector<int> nums = {23,5,4,1,9,16};
    insertionSort(nums);
    return 0;
}