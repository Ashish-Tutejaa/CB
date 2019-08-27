#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
    {
    if(a.second.first == b.second.first)
        {
        return a.second.second<b.second.second;
        }
    return a.second.first<b.second.first;
    }
int main()
{
int n;
cin>>n;
vector<pair<int,pair<int,int>>> v;
for(int i = 1;i<=n;i++)
    {
    pair<int,int> temp;
    cin>>temp.first>>temp.second;
    pair<int,pair<int,int>> ins;ins.first = i;
    ins.second.first = temp.first;
    ins.second.second = temp.second;
    v.push_back(ins);
    }
sort(v.begin(),v.end(),compare);
int totalTime = v[0].second.second + v[0].second.first;
int avgWT[n] = {0};
int avgTAT[n] = {0};
stack<int> s;
int i =1;
while(1)
    {
    if(i==n)
        break;
    avgWT[i] = totalTime - v[i].second.first;
    totalTime+=v[i].second.second;
    i++;
    }
int waitTot =0;
for(int i =0;i<n;i++)
    {
    // cout<<avgWT[i]<<" ";
    waitTot +=avgWT[i];
    }waitTot/=n;cout<<endl;
cout<<"AVG WAIT: "<<waitTot<<endl;
int tat =0 ;
for(int i =0;i<n;i++)
    {
    avgTAT[i] = avgWT[i] + v[i].second.second;
    }
for(int i =0;i<n;i++)
    {
    // cout<<avgTAT[i]<<" ";
    tat+=avgTAT[i];
    }tat/=n;cout<<endl;
cout<<"AVG TURN AROUND: "<<tat<<endl;
}