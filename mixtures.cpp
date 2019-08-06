#include<bits/stdc++.h>
using namespace std;
int sizer(int * arr,int low,int high)
    {
    int sum=0;
    for(int h = low;h<=high;h++)
        sum+=arr[h];
    sum%=100;
    return sum;
    }
int mixTures(int * arr,int low,int high,int dp[][1000])
    {
    if(dp[low][high]!=-1)
        return dp[low][high];
    if(low==high)
        {
        dp[low][high] =0;
        return 0;
        }
    int ans = INT_MAX;
    for(int k = low;k<high;k++)
        {
        int temp = mixTures(arr,low,k,dp) + mixTures(arr,k+1,high,dp)+(sizer(arr,low,k)*sizer(arr,k+1,high));
        ans = min(ans,temp);
        }
    return dp[low][high]=ans;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    int arr[n];
    int dp[1000][1000];
    memset(dp,-1,(1000*1000)*sizeof(int));
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<mixTures(arr,0,n-1,dp)<<endl;
    }
}