#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b)
    {
    if(a.second==b.second)
        return a.first>b.first;
    return a.second>b.second;
    }
int main()
{
int n,k;
cin>>n>>k;
unordered_map<int,int> mappy;
for(int i=0;i<n;i++)
    {
    int temp;
    cin>>temp;
    if(mappy.count(temp)==0)
        mappy.insert(pair<int,int>(temp,1));
    else
        mappy[temp]+=1;
    }
vector<pair<int,int>> v;
for(auto x:mappy)
    {
    pair<int,int> temp;
    temp.first = x.first;
    temp.second = x.second;
    v.push_back(temp);
    }
sort(v.begin(),v.end(),compare);
// for(auto x:v)
//     cout<<"ELEMENT: "<<x.first<<" FREQ: "<<x.second<<" ";cout<<endl;
int difference=0;
int counter;
if(n&1)
    {
        // cout<<"ODD"<<endl;
      counter=ceil(n/2.0);
    }
else
    {
        // cout<<"EVEN"<<endl;
    counter = n/2.0;
    }
// cout<<"COUNTER: "<<counter<<endl;
for(int i=0;i<v.size();i++)
    {
    int need = ceil(v[i].second/2.0);
    if(need>counter)
            {
            difference =v[i].second-(counter*2);
            break;
            }
    counter= counter-need;
    }    
cout<<n-difference<<endl;
}
