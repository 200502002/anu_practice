#include<iostream>
using namespace std;
void towersOfHanoi(int disks, char from, char to, char temp)
{
    if(disks==0)
    {
        return;
    }
    towersOfHanoi(disks-1, from, temp, to);
    cout<<" moving "<<disks<<"from "<<from<<" to "<<to<<endl;
    towersOfHanoi(disks-1, temp, to, from);
    return;
}
int main()
{
    towersOfHanoi(1,'A','B','C');
    cout<<"****************"<<endl;
    towersOfHanoi(2,'A','B','C');
    cout<<"****************"<<endl;
    towersOfHanoi(3,'A','B','C');
    return 0;
}