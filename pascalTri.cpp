#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int arr[n][n+1];
memset(arr,0,sizeof(int)*n*(n+1));
arr[0][0] = 1;
arr[1][0] = 1;
arr[1][1] = 1;
for(int i = 2;i<n;i++)
    {
    for(int j = 0;j<(i+1);j++)
        {
        if(j==0 or j==n)
            {
            arr[i][j]=1;
            continue;
            }
        arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
        }
    }
for(int i = 0;i<n;i++)
    {
    for(int k = 0;k<n-i;k++)
        cout<<" ";
    if(i==0)
        cout<<arr[0][0]<<" ";
    int h = 0;
    if(i!=0)
    for(int j = 0;j<=(2*i);j++)
        {
        if(j%2!=0)
            {
            cout<<" ";continue;
            }
        else
            {
            cout<<arr[i][h]<<" ";
            h++;
            }    
        }
    for(int k = 0;k<n-i;k++)
        cout<<" ";
    cout<<endl;
    }
}