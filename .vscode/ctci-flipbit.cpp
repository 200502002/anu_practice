//#include<bits/stdc++.h>
#include<iostream>
#include<bitset>
using namespace std;
 
int findMaxConsecutiveOnes(int num) {
    int left = 0, right = 0, flips = 0, max_len = 0;
    string binary = bitset<32>(num).to_string(); // convert integer to binary string
    while (right < binary.size()) {
        cout<<left<<" "<<right<<" "<<binary[left]<<" "<<binary[right]<<" "<<binary<<" "<<max_len<<endl;
        if (binary[right] == '0') {
            flips++;
        }
        while (flips > 1) {
            if (binary[left] == '0') {
                flips--;
            }
            left++;
        }
        max_len = max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}
 
// Driver code
int main()
{
    // input 1
    cout << findMaxConsecutiveOnes(13);
    cout << endl;
 
    // input 2
    cout << findMaxConsecutiveOnes(1775);
    cout << endl;
 
    // input 3
    cout << findMaxConsecutiveOnes(15);
    return 0;
}