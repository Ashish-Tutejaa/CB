#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
        {
        int temp;
        if(i==(n-1))
            temp = arr[i];
        else 
            temp = arr[i]+arr[i]*(n-(i+1));
        ans = min(ans,temp);
        }
    cout<<ans<<endl;
    }
}