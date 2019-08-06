#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll recur(ll * arr,ll rod, ll size,ll startIndex)
    {
    if(size==1)
        {
        return (startIndex+1)*arr[0];
        }
    if(size==2)
        {
        if(arr[0]>arr[1])
            swap(arr[0],arr[1]);
        //calcing sum and returning//
        ll sum = (arr[0]*(startIndex+1))+(arr[1]*(startIndex+2));
        // swap(arr[0],arr[1]);
        return sum;
        }
    //rec case
    ll left,right;
    ll maximum = INT_MIN;
    for(ll k = rod;k<=size-1;k++)
        {
        ll * temp1 = new ll[k];
        for(ll o = 0;o<k;o++)
            {
            temp1[o]=  arr[o];
            }
        ll * temp2 = new ll[size-k];
        for(ll o = 0;o<size-k;o++)
            {
            temp2[o]=  arr[k+o];
            }
        ll size1 = k;
        ll size2 = size-k;
        left = recur(temp1,1,size1,0);
        right = recur(temp2,1,size2,k);
        maximum = max((left+right),maximum);
        delete []temp1;
        delete []temp2;
        }
        // dp[arr[0]][arr[size-1]] = maximum;
        return maximum;
    }
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i = 0;i<n;i++)
        cin>>arr[i];
    cout<<recur(arr,1,n,0)<<endl;
    }
}
