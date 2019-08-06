#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
int miniMiZed(vector<int> v,int dp[][100])
    {
    vector<int>::iterator itr = v.begin();
    vector<int>::iterator str = v.end();
   //CHECK THIS OUT i = std::distance( names.begin(), it );

    // for(int i=0;i<v.size();i++)
    //     cout<<v[i]<<" ";cout<<endl;
    // cout<<"IN"<<endl;
    //base case 
    if(v.size()==3)
        {
        return min((v[0]+v[1]+v[0]+v[1]+v[2]),min((v[1]+v[2]+v[1]+v[2]+v[0]),(v[0]+v[2]+v[0]+v[2]+v[1])));
        }
    if(v.size()==2)
        return v[0]+v[1];
    if(v.size()==1)
        return 0;
    //rec case
    int maximum = INT_MAX;
    for(int i=1;i<v.size();i++)
        {
        int temp = v[i]+v[i-1];
        vector<int> tempor;
        for(int j=0;j<v.size();j++)
            {
            if(j!=i and j!=(i-1))
               tempor.push_back(v[j]);
            if(j==i)
                {
                tempor.push_back(temp);
                }
            }    
        temp+=miniMiZed(tempor,dp);
        if(temp<maximum)
            {
            maximum=temp;
            }
        }
     long long int anotherOne = v[0]+v[v.size()-1];
     vector<int> tempor;
     for(int i=0;i<v.size()-1;i++)
        {
        if(i==0)tempor.push_back(anotherOne);
        else tempor.push_back(v[i]);
        }
     anotherOne+=miniMiZed(tempor,dp);
        if(anotherOne<maximum)
            {
            maximum = anotherOne;
            }
    // cout<<"MAXIMUM: "<<maximum<<endl;
    return maximum;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    // cout<<n<<"THIS IS N"<<endl;
    vector<int> v;
    int dp[100][100];
    memset(dp,-1,(100*100)*sizeof(int));
    for(int i=0;i<n;i++)
        {
        int temp;cin>>temp;
        v.push_back(temp);
        }
    // cout<<"DONE INPUTS"<<endl;
    cout<<miniMiZed(v,dp)<<endl;
    }
}