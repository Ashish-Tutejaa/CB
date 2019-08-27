#include<iostream>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;cin>>n;
    int arr[n];
    int start = 0;
    for(int i =0;i<n;i++)
        {
        cin>>arr[i];
        if(arr[i]==1)
            start = i;
        }
    bool cloc,coun;
    cloc = coun = true;
    //go cloc (right);
    int j = start;
    while(1)
        {
        int next = j+1;
        if(next>=n)
            next =0;
        if(arr[next]==1)
            break;
        if((arr[j]+1)!=arr[next])
            {
            cloc = false;
            break;
            }
        j++;
        if(j>=n)
            j = 0;
        }
    j = start-1;
    if(j<0)
        j = n-1;
    while(1)
        {
        int prev = j-1;
        if(prev<0)
            prev = n-1;
        if(arr[prev]==1)
            break;
        if((arr[j]+1)!=arr[prev])
            {
            coun = false;
            break;
            }
        j--;
        if(j<0)
            j = n-1;
        }
    if(cloc or coun)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
}