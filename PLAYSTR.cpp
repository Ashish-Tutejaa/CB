#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    int s[n];
    int r[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        cin>>r[i];
    unordered_map<int,int> mappyS;
    mappyS.insert(pair<int,int>(0,0));
    mappyS.insert(pair<int,int>(1,0));
    for(int i=0;i<n;i++)
        {
        mappyS[s[i]]+=1;
        }
    unordered_map<int,int> mappyR;
    mappyR.insert(pair<int,int>(0,0));
    mappyR.insert(pair<int,int>(1,0));
    for(int i=0;i<n;i++)
        {
        mappyR[r[i]]+=1;
        }
    int first = mappyS[1];
    int second = mappyS[0];
    int firstCheck = mappyR[1];
    int secondCheck = mappyS[0];
    cout<<"FIRST: "<<first<<"  SECOND: "<<second<<endl;
    cout<<"FIRSTC: "<<firstCheck<<"  SECONDC:  "<<secondCheck<<endl;
    if(first==firstCheck and second==secondCheck)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    }
}