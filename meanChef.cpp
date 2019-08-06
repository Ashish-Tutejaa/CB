#include<iostream>
#include<climits>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    long int n;cin>>n;
    long long int arr[n];
    for(long int i=0;i<n;i++)
        cin>>arr[i];
    //a corner case is if all the elements are the same. In this case we just 
    //the first element it self
    bool flag2=1;
    for(long int i=1;i<n;i++)
        {
        if(arr[i]!=arr[i-1])
            flag2=0;
        }
    if(flag2)
        {
        cout<<1<<endl;
        continue;
        }
    //we know the size.  we must get total sum and mean.
    long long int sum=0;
    double mean=0.0;
    for(long int i=0;i<n;i++)
        {
        mean+=arr[i];
        sum+=arr[i];
        }
    mean/=n;
    // cout<<sum<<" "<<mean<<endl;
    // cout<<"MEAN: "<<mean<<" SUM: "<<sum<<endl;
    long int answer=INT_MAX;
    bool flag=0;
    for(long int i=0;i<n;i++)
        {
        // cout<<"I:"<<i<<endl;
        float temp = sum-arr[i];
        temp/=(n-1);
        if(temp==mean and !flag)
            {
            answer = i+1;
            flag=1;
            }
        }
    //1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
    if(flag)
    cout<<answer<<endl;
    if(!flag)
    cout<<"Impossible"<<endl;
    }
}