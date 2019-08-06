#include<iostream>
#include<climits>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i = 0;i<n;i++)
        cin>>arr1[i];
    for(int i = 0;i<m;i++)
        cin>>arr2[i];
    int minimum = INT_MAX,maximum = INT_MIN;
    minimum = min(arr1[0],arr2[0]);
    maximum = max(arr1[n-1],arr2[m-1]);
    int ans[maximum];
    for(int i = 0;i<maximum;i++)
        {
        ans[i] = i+1;
        }
    }
}