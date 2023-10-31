#include <string>
#include<iostream>
using namespace std;
bool isPalindrome(std::string str) {
  // base case #1
  if(str.length() ==0)
    return true;  
  // base case #2
  if(str.length()== 1)
    return true;
  cout<<str<<endl;    
  // recursive case
  if(str[0]==str[str.length()-1])
  {
   return isPalindrome(str.substr(1, str.length()-2));
  }  
  return false;
}

int main()
{
    cout<<isPalindrome("malayalam");
}