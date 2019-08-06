#include<iostream>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    string sNum;
    cin>>sNum;
    string rNum;
    cin>>rNum;
    int onesFirst = 0;
    for(int i=0;i<n;i++)
        {
        if(sNum[i]=='1')
            onesFirst++;
        }
    int zeroFirst = n-onesFirst;
    int onesSec = 0;
    for(int i=0;i<n;i++)
        {
        if(rNum[i]=='1')
            onesSec++;
        }
    int zeroSec = n-onesSec;
    if(onesFirst == onesSec and zeroFirst == zeroSec)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
}