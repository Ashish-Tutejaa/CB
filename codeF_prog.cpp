#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i] = i+1;
        int y=0;
    int counter=0;
    while(1)
        {
        arr[y]=-1;
        y+=2;
        if(y>=n)
            break;
        }
    int siz = floor(n/2.0);
    int ans[siz];
    int j=0;
    for(int i=0;i<n;i++)
        {
        if(arr[i]!=-1)
            {
            ans[j]=arr[i];
            j++;
            }
        if(j>=siz)
            break;
        }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";cout<<endl;
    for(int i=0;i<siz;i++)
        cout<<ans[i]<<" ";cout<<endl;
    cout<<ans[k-1]<<endl;
    }
}