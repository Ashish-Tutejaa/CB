#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<utility>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;cin>>n;
    int powers[n+1];
    for(int i = 1;i<=n;i++)
        cin>>powers[i];
    int health[n+1];
    for(int i = 1;i<=n;i++)
        cin>>health[i];
    pair<int,int> arr[n+1];
    for(int i = 1;i<=n;i++)
        {
        pair<int,int> temp;
        temp.first = 0;temp.second = 0;
        arr[i] = temp;
        }

    for(int i = 1;i<=n;i++)
        {
        int lb = i-powers[i];
        int ub = i+powers[i];
        if(lb<1)lb = 1;
        if(ub>n) ub = n;
        arr[lb].first++;
        arr[ub].second++;
        }
    vector<pair<int,pair<int,int>>> mainVect;
    for(int i = 1;i<=n;i++)
        {
        pair<int,pair<int,int>> dummy;
        dummy.first = i;
        dummy.second.first = arr[i].first;
        dummy.second.second =arr[i].second;
        mainVect.push_back(dummy);
        }
    unordered_map<int,int> mapping;
        int toSub =0 ;
        int temp = 0;
    for(int i = 0;i<n;i++)
        {
        // cout<<mainVect[i].first<<" ("<<mainVect[i].second.first<<","<<mainVect[i].second.second<<")  ";
        if(i==0)
            {
            temp = mainVect[i].second.first;
            temp-=toSub;
            toSub = mainVect[i].second.second;
            mapping[temp]++;
            continue;
            }
        if(mainVect[i].second.first>0)
            {
            temp+=mainVect[i].second.first;
            }
        temp-=toSub;
        toSub = mainVect[i].second.second;
        mapping[temp]++;
        }
    int counter =0 ;
    for(int i =1;i<=n;i++)
        {
        if(mapping.find(health[i])!=mapping.end() and mapping[health[i]]>0)
            {
            mapping[health[i]]--;
            counter++;
            }
        }
    if(counter==n)
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
    }
}