#include<iostream>
using namespace std;
int factorial(int n) {
  int result = 1;
  for(int i=1;i<=n;i++)
  {
    result = result * i;
  }
  
  return result;
};

int factorial_recursive(int n)
{
    if(n==0)
        return 1;
    else
        return n * factorial_recursive(n-1);
}