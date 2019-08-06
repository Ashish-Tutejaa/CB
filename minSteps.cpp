#include<iostream>
#include<climits>
using namespace std;
int dp[10000]={-1};
int minSteps(int n)
    {
    if(dp[n]!=-1)
        {
        // cout<<"IN COND IS: "<<dp[n]<<" FOR N"<<n<<endl;
        return dp[n];
        }
    // cout<<n<<" ";
    //base case
    if(n==1)
        return 0;
    //rec case
    int minimum = INT_MAX;
    if(n%3==0)
        {
        int div3 = 1+minSteps(n/3);
        minimum = min(div3,minimum);
        }
    if(n%2==0)
        {
        int div2=1+minSteps(n/2);
        minimum = min(div2,minimum);
        }
    int minus = 1+minSteps(n-1);
    dp[n]=min(minimum,minus);
    return min(minimum,minus);
    }
int main()
{
int n;
cin>>n;
for(int i=0;i<10000;i++)
    {
    dp[i]=-1;
    }
int ans = minSteps(n);
cout<<ans<<endl;
}