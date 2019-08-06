#include<iostream>
#include<map>
#include<utility>
#include<vector>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
vector<pair<int,int>>vectyN;
for(int i=0;i<n;i++)
    {
    pair<int,int> temp;
    cin>>temp.first>>temp.second;
    vectyN.push_back(temp);
    }
long long int  arr[10000000]={};
for(int i=0;i<m;i++)
    {   
    pair<int,int> temp;
    cin>>temp.first>>temp.second;
    for(int j= temp.first;j<=temp.second;j++)
        {arr[j]=1;}
    }
int counter=0;
for(int i=0;i<vectyN.size();i++)
    {
    if(arr[vectyN[i].first] or arr[vectyN[i].second])
        counter++;
    }
cout<<counter<<endl;
}