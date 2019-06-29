#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<pair<string,int>> v1;
int n;cin>>n;
for(int i=0;i<n;i++)
    {
    pair<string,int>p1;
    cin>>p1.first>>p1.second;
    v1.push_back(p1);
    }
for(int i=0;i<n;i++)
    {
    cout<<v1[i].first<<" and "<<v1[i].second<<endl;
    }
cout<<"here"<<endl;
for(int i=0;i<(n-1);i++)
    {
    for(int j=0;j<(n-i-1);j++)
        {
        if(v1[j].second>v1[j+1].second)
            {
            swap(v1[j],v1[j+1]);
            }
        }
    }
//the sort fuction takes the first part of the pair unless a sortBySec type function is used.
cout<<"second"<<endl;
for(int i=0;i<n;i++)
    {
    cout<<v1[i].first<<" and "<<v1[i].second<<endl;
    }
}
